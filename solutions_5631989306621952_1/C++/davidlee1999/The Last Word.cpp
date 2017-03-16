#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 1005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[N],lf[N],rt[N];
int main()
{
    int T,test;
    int n,i,nl=0,nr=0,mx=0;
    freopen("Alarge.in","r",stdin);
    freopen("Alarge.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        scanf("%s",s+1);
        printf("Case #%d: ",test);
        n=strlen(s+1);
        nl=nr=mx=0;
        for(i=1;i<=n;i++)
        {
            if(mx<s[i])
            {
                mx=s[i];
                lf[++nl]=s[i];
            }
            else if(mx==s[i])
                lf[++nl]=s[i];
            else rt[++nr]=s[i];
        }
        reverse(lf+1,lf+1+nl);
        for(i=1;i<=nl;i++)
            printf("%c",lf[i]);
        for(i=1;i<=nr;i++)
            printf("%c",rt[i]);
        cout<<endl;
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))
