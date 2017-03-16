#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int a[1000002];
int dp[1000002];
int main()
{
    ifstream in("in.txt");
    ofstream out("out2.txt");
    int T, n;
    in >> T;
 
    for(int t = 1; t <= T; t++)
    {
        string word;
        in >> word >> n;
        int val = 0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < word.size(); i++)
        {
            int good = 1;
            for(int k = 0; k < 5; k++)
            {
                if(word[i] == vow[k]) good = 0;
            }
            if(good)
            {
                if(i == 0) a[i] = 1;
                else
                  a[i] = a[i-1] + 1;
            }
            else
              a[i] = 0;
        }
        for(int i = 0; i < word.size(); i++)
        {
            if(a[i] >= n)
            {
                if(i == 0) dp[i] = 1;
                else
                {
                    dp[i] = i-n+2;
                }
            } 
            else
            {
                if(i == 0) dp[i] = 0;
                else
                {
                    dp[i] = dp[i-1];    
                } 
            }
        }
        long long sum = 0;
        for(int i = 0; i < word.size(); i++)
        {
            sum += dp[i];
        }
       out<<"Case #"<<t<<": "<<sum<<endl;   
    }
    return 0;
}
