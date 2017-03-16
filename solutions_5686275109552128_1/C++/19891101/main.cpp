

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-8



#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()

using namespace std;


void output(i64 x)
{
    if(x<0) putchar('-'),x=-x;
    if(x==0)
    {
        putchar('0');
        return;
    }
    int a[20],num=0;
    while(x) a[++num]=x%10,x/=10;
    while(num>0) putchar('0'+a[num--]);
}

inline i64 myInt()
{
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    int flag=1;
    if(c=='-') flag=-1,c=getchar();
    i64 x=0;
    while(isdigit(c))
    {
        x=(x*10)+(c-'0');
        c=getchar();
    }
    if(-1==flag) return -x;
    return x;
}

const int INF=100100007;
const int N=1111;



int n;
int a[N];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("ans","w",stdout);

    int T=myInt();
    int num=0;
    while(T--)
    {
        n=myInt();
        int Max=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=myInt();
            if(a[i]>Max) Max=a[i];
        }
        int ans=INF;
        for(int i=1;i<=Max;i++)
        {
            int tmp=i;
            for(int j=1;j<=n;j++)
            {
                if(a[j]>i) tmp+=(a[j]-1)/i;
                if(tmp>ans) break;
            }
            if(tmp<ans) ans=tmp;
        }
        printf("Case #%d: %d\n",++num,ans);
    }
}
