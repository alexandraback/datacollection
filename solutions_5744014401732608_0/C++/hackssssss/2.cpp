
#include <bitset>
#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;int f=1;
    while((c=getchar())<'0' || c>'9')if(c=='-')f=-1;
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res*f;
}
const int N=100010,MOD=1e9+7;

int ans[60][60];
int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("in.txt","w",stdout);
    int T=in(),ca=1;
    //printf("Case #%d: %d",ca++,ans);

    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        //cout<<"n=="<<n<<" m=="<<m<<endl;
        printf("Case #%d: ",ca++);
        if(m > (1LL<<(n-2)))
        {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        if(n==2)
        {
            puts("01");
            puts("00");
            continue;
        }
        mem(ans,0);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++) ans[i][j] = 1;
        ll all = (1LL<<(n-2));
        if(m == all)
        {
            for(int i=1;i<n;i++) ans[0][i]=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    printf("%d%s",ans[i][j],j==n-1?"\n":" ");
                }
            }
            continue;
        }
        int now=1;
        ll tmp=all>>1;
        while(m>0)
        {
            while(tmp > m) tmp>>=1,now++;
            m -= tmp;
            ans[0][now]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d%s",ans[i][j],j==n-1?"\n":" ");
            }
        }
    }
    return 0;
}
