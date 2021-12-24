//A program that returns index of first unique character of the given string without using key-value pairs like data structure.
//Input : String  
//Output: numerical value, i.e Index
//For Example 
// i/p : Supercalifragilisticexpialidocious
// o/p : 18

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int unic(std::string word)
{   
    int caps[27][2]={0};
    int NonCaps[27][2]={0};                //1 indexed 2D array to frequency and index value in columns respectively 
    int ans=0;
    
    for(int i=0;i<=word.length();i++){     //Reading the string character by character
        //std::cout<<word.length();
        if(((int)word[i])>=64 && ((int)word[i])<=90) //for caps
        {
            if(caps[(int)word[i]-64][1] == 0)
            {
                caps[(int)word[i]-64][1]  = i;
                caps[(int)word[i]-64][0] += 1;
            }
            else
            {
                caps[(int)word[i]-64][0] += 1;
            }

        }
        if(((int)word[i])>96 && ((int)word[i]) <=122) //for non-caps
        {
            //std::cout<<"hello";
            if(NonCaps[(int)word[i]-96][1] == 0)
            {
                NonCaps[(int)word[i]-96][1]  = i+1;
                NonCaps[(int)word[i]-96][0] += 1;
            }
            else
            {
                NonCaps[(int)word[i]-96][0] += 1;
            }
        }


    }
    for(int i=1;i<=27;i++)
    {
        if(caps[i][0]==1 && NonCaps[i][0] == 1)
        {
            ans = std::min(caps[i][1],NonCaps[i][1]);
        }
        else if(NonCaps[i][0] == 1 && caps[i][0] != 1)
        {
            ans = (ans==0) ? NonCaps[i][1] : std::min(ans,NonCaps[i][1]);
        }
        else if(NonCaps[i][0] != 1 && caps[i][0] == 1)
        {
            ans = (ans==0) ? caps[i][1] : std::min(ans,caps[i][1]);
        }
    }

    //Uncomment the below to see matrix mapping.
    /*for(int j=1,i=1;j<=26;j++)
        {
            std::cout<<(char)(96+j)<<"\t"<<NonCaps[j][0]<<"\t"<<NonCaps[j][i]<<"\n";
        }*/       
    return ans;
};

int main()
{
    std::string word;
    std::cin>>word;
    std::cout<<unic(word);
    return 0;
}
