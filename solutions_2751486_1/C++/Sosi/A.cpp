#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1000005
long long dp[MAX];
long long Y[MAX];
long long N[MAX];
string S;
int n;
bool is(char c)
{
    if(c == 'a'|| c=='e'|| c=='i'|| c=='o'|| c == 'u')
    {
        return false;
    }
    return true;
}
int main()
{
    //freopen("A.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T; cin>>T;
    for(int tt = 1; tt<= T; tt++)
    {
        cin>>S>>n;
        int L = S.size();
        for(int i=0; i<L; i++)
        {
            dp[i]= 0LL; Y[i]=0LL; N[i]= 0LL;
        }
        if(is(S[0])) Y[0]=1LL; else N[0]=1LL;
        for(int i=1; i<L; i++)
        {
            if(is(S[i]))
            {
                Y[i] = Y[i-1]+1LL;
            }else
            {
                N[i] = N[i-1]+1LL;
            }
        }
        //for(int i=0; i<L; i++) cout<<Y[i]<<" "; cout<<endl;
        //for(int i=0; i<L; i++) cout<<N[i]<<" "; cout<<endl;
        if(Y[n-1]==n) dp[n-1] = 1LL;
        for(long long i=n; i<L; i++)
        {
            if(!is(S[i]))
            {
                dp[i]=dp[i-1];
            }else
            {
                if(Y[i-1] == n-1)
                {
                    dp[i] =  i-n+2;
                }
                else
                {
                    if(Y[i-1] > n-1)
                        dp[i] = dp[i-1]+1;
                    else
                        dp[i] = dp[i-1];
                }
            }
        }
        long long ret = 0LL;
        for(int i=n-1; i<L; i++)
        {
            ret += dp[i];
            //cout<<dp[i]<<" ";
        }
        cout<<"Case #"<<tt<<": "<<ret<<endl;
    }
    return 0;
}
