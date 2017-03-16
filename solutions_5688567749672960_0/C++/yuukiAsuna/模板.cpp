#include<cstdio>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int ,int> P;
const int maxn=10+1e6;
int dp[maxn];
int rev(int x)
{
         char tmp[30];
         sprintf(tmp,"%d",x);
         int now=0,len=strlen(tmp);
         for(int i=len-1;i>=0;i--)
                  now=now*10+tmp[i]-'0';
         if(now>=x||tmp[len-1]=='0') return -1;
         else return now;
}
void init()
{
         dp[1]=1;
         for(int i=2;i<=1000000;i++){
                  int tmp=rev(i);
                  if(tmp==-1) dp[i]=dp[i-1]+1;
                  else dp[i]=1+min(dp[i-1],dp[tmp]);
         }
}
int main()
{
        freopen("A-small-attempt3.in","r",stdin);
        freopen("A-small-attempt3.out","w",stdout);
        int T,ca=0;
        init();
        scanf("%d",&T);
        while(T--){
                int n;
	       scanf("%d",&n);
	//printf("n=%d\n",n);
                printf("Case #%d: %d\n",++ca,dp[n]);
        }
	return 0;
}
