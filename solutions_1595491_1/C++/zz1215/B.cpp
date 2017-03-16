#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
using namespace std;

#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif

#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)
#define FFD(i,a)        for( int i = (a)-1 ; i >= 0 ; i --)
#define S64(a)          scanf(in64,&a)
#define SS(a)           scanf("%d",&a)
#define LL(a)           ((a)<<1)
#define RR(a)           (((a)<<1)+1)
#define SZ(a)           ((int)a.size())
#define PP(n,m,a)       puts("---");FF(i,n){FF(j,m)cout << a[i][j] << ' ';puts("");}
#define pb              push_back
#define CL(Q)           while(!Q.empty())Q.pop()
#define MM(name,what)   memset(name,what,sizeof(name))
#define read            freopen("B-large.in","r",stdin)
#define write           freopen("out.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-10;
const double pi = acos(-1.0);

const int maxn = 111;

int T,n,s,p;
int t[maxn];

bool can1(int x)
{
    if(t[x] >= 3*p - 2 && t[x] -p >=0 )
    {
        return true;
    }
    return false;
}

bool can2(int x)
{
    if(t[x] >= 3*p - 4 && p - 2 >= 0)
    {
        return true;
    }
    return false;
}

int main()
{   write;
    read;

    cin>>T;
    int ans;
    for(int tt=1;tt<=T;tt++)
    {
        cin>>n>>s>>p;

        for(int i=1;i<=n;i++)
        {
            cin>>t[i];
        }

        ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(can1(i))
            {
                ans++;
                continue;
            }
            else if(can2(i) && s>0)
            {
                ans++;
                s--;
                continue;
            }
        }

        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
