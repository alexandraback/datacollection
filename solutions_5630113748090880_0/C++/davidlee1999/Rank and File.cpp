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
#define N 105
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int rc[N][N];
int vis[2505];
int main()
{
    int T,test;
    int n,i,j;
    freopen("Bsmall0.in","r",stdin);
    freopen("Bsmall0.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n*2-1;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&rc[i][j]),vis[rc[i][j]]++;
        }
        printf("Case #%d: ",test);
        for(i=1;i<=2500;i++)
            if(vis[i]&1)
                printf("%d ",i);
        cout<<endl;
    }

}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))
