#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    ofstream output;
    output.open("outout.out");
    int n;
    long len;
    int dp[111];
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        cin>>s;
        if(s[0]=='+')
            dp[0]=0;
        else{
            dp[0]=1;
        }
        len=s.length();
        for(int j=1;j<len;j++){
            if(s[j]=='+')
                dp[j]=dp[j-1];
            else{
                if(s[j-1]=='+')
                    dp[j]=dp[j-1]+2;
                else{
                    dp[j]=dp[j-1];
                }
            }
        }
        output<<"Case #"<<i<<": "<<dp[len-1]<<"\n";
        s.clear();
    }
    return 0;
}