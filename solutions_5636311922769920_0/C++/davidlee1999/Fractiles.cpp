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
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)w
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int T,test,i,k,c,s,n,j;
    LL x,now;
    freopen("Dsmall0.in","r",stdin);
    freopen("Dsmall0.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        cin>>k>>c>>s;
        printf("Case #%d: ",test);
        if(s<k/c+(k%c!=0))
            printf("IMPOSSIBLE\n");
        else
        {
            n=k/c+(k%c!=0);
            now=0;
            for(i=1;i<=n;i++)
            {
                for(x=0,j=1;j<=c;j++)
                {
                    x=x*k+now;
                    now=min(now+1,(LL)k-1);
                }
                cout<<x+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
