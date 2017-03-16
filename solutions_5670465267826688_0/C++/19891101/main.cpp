

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
const int N=11111;


int T[5][5]=
{
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,-1,4,-3,
    0,0,-4,-1,2,
    0,0,3,-2,-1
};


int n;
i64 m;
int a[N];
char s[N];

int mul(int x,int y)
{
    if(x==-1) return -y;
    if(y==-1) return -x;
    if(x==1) return y;
    if(y==1) return x;

    int sx=1,sy=1;
    if(x<0) sx=-1,x=-x;
    if(y<0) sy=-1,y=-y;

    return T[x][y]*sx*sy;
}

int divide(int x,int y)
{
    for(int i=-4;i<=4;i++)
    {
        if(i!=0&&mul(y,i)==x) return i;
    }
    return 0;
}


int pre[N],next[N];

int cycle[15],cycleNum;

vector<pair<int,int> > Vi;

vector<int> f[10][15];

int cal()
{
    if(n*m<3) return 0;
    pre[0]=next[n+1]=1;
    for(int i=1;i<=n;i++) pre[i]=mul(pre[i-1],a[i]);
    for(int i=n;i>=1;i--) next[i]=mul(a[i],next[i+1]);
    cycle[0]=1;
    cycle[cycleNum=1]=pre[n];
    while(cycle[cycleNum]!=1)
    {
        cycle[cycleNum+1]=mul(cycle[cycleNum],pre[n]);
        cycleNum++;
    }



    Vi.clear();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<cycleNum;j++)
        {
            if(mul(cycle[j],pre[i])==2)
            {
                Vi.push_back(MP(i,j));
            }
        }
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<15;j++) f[i][j].clear();
    }


    for(int i=n+1;i>=1;i--)
    {
        for(int j=0;j<cycleNum;j++)
        {
            if(mul(next[i],cycle[j])==4)
            {
                int t=pre[i-1]+4;

                f[t][j].push_back(i);
            }
        }
    }
    for(int id=0;id<Vi.size();id++)
    {
        int i=Vi[id].first,cnt1=Vi[id].second;

        int val=next[i+1];
        for(int j=0;j<cycleNum;j++)
        {
            int tmp=mul(val,cycle[j]);
            int k=divide(3,tmp);
            if(0==k) continue;
            k+=4;
            for(int t=0;t<14;t++) if(f[k][t].size()>0)
            {
                int sum=cnt1+1+j+1+t;
                if(sum<=m&&(m-sum)%cycleNum==0)
                {
                    return 1;
                }
            }
        }

        int k=mul(pre[i],3);
        if(0==k) continue;
        k+=4;
        for(int t=0;t<14;t++) if(f[k][t].size()>0&&f[k][t][0]>i)
        {
            int sum=cnt1+1+t;
            if(sum<=m&&(m-sum)%cycleNum==0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int baoli()
{
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[j+(i-1)*n]=a[j];
        }
    }

   // assert(n*m<N);
 //   for(int j=1;j<=n*m;j++) printf("%d ",a[j]); puts("");
    pre[0]=next[n*m+1]=1;
    for(int i=1;i<=n*m;i++) pre[i]=mul(pre[i-1],a[i]);
    for(int i=n*m;i>=1;i--) next[i]=mul(a[i],next[i+1]);

    for(int i=1;i<=n*m;i++)
    {
        if(pre[i]==2)
        {
            for(int j=i+1;j<=n*m;j++)
            {
                if(mul(2,3)==pre[j])
                {
                    if(j+1<=n*m&&next[j+1]==4)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("ans","w",stdout);

    int T=myInt();
    int num=0;
    while(T--)
    {
        n=myInt();
        m=myInt();
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='i') a[i]=2;
            else if(s[i]=='j') a[i]=3;
            else a[i]=4;
        }
        int ans=cal();
        printf("Case #%d: %s\n",++num,ans?"YES":"NO");


    }
}
