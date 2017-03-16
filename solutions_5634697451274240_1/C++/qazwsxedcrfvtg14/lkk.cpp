#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
char s[1005];
int dp[1005][2];
int main(){
    int t=0,T;
    scanf("%d",&T);
    while(T--){t++;
        scanf("%s",s);
        int n=strlen(s);
        if(s[0]=='+')
            dp[0][0]=0,dp[0][1]=1;
        else
            dp[0][0]=1,dp[0][1]=0;
        for(int i=1;i<n;i++)
            if(s[i]=='+')
                dp[i][0]=dp[i-1][0],
                dp[i][1]=dp[i-1][0]+1;
            else
                dp[i][0]=dp[i-1][1]+1,
                dp[i][1]=dp[i-1][1];
        printf("Case #%d: %d\n",t,dp[n-1][0]);
        }
    }
