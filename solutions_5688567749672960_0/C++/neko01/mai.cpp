/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define clr(a) memset(a,0,sizeof a)
#define clr1(a) memset(a,-1,sizeof a)
#define dbg(a) printf("%d\n",a)
typedef pair<int,int> pp;
const double eps=1e-9;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const LL inf=(((LL)1)<<61)+5;
int dp[1000005];
int cao(int x)
{
    int tmp=0;
    while(x){
        tmp=tmp*10+x%10;
        x/=10;
    }
    return tmp;
}
int main()
{
    dp[1]=1;
    for(int i=2;i<=1000000;i++){
        int tmp=cao(i);
        if(tmp<i&&cao(tmp)==i)
            dp[i]=min(dp[i-1],dp[tmp])+1;
        else
            dp[i]=dp[i-1]+1;
    }
        freopen("A-small-attempt1.in" , "r" , stdin);
    freopen("A-small-attempt1.out" , "w" , stdout);
    int t,cnt=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",++cnt,dp[n]);
    }
    return 0;
}
