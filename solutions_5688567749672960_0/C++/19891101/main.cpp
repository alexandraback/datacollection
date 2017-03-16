

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


const i64 INF=1e16;
const int mod=1000000007;
const int N=1000005;

i64 n;
int a[20],aNum;

i64 f[N];

int rev(int x)
{
    vector<int> V;
    while(x) V.push_back(x%10),x/=10;
    i64 ans=0;
    for(int i=0;i<V.size();i++) ans=ans*10+V[i];
    return ans;
}

int path[N];

void init()
{
    clr(f,-1);
    f[1]=1;
    path[1]=0;
    for(int i=1;i<N;i++)
    {
        if(f[i+1]==-1||f[i+1]>f[i]+1) f[i+1]=f[i]+1,path[i+1]=i;;
        int t=rev(i);
        if(t>=N) continue;
        if(f[t]==-1||f[t]>f[i]+1) f[t]=f[i]+1,path[t]=i;
    }
}


void print(int x)
{
    if(x==0) return;
    print(path[x]);
    printf(" %d",x);
}


i64 cal(i64 L,i64 R,int B)
{
    i64 ans=R-L;

    i64 pre=0;
    for(int i=0;i<B-1;i++)
    {
        pre=pre*10+9;

        i64 tmp=0;
        for(int j=B-1-i-1;j>=0;j--) tmp=tmp*10+9;
        i64 pp=pre+tmp-1+1;
        if(pp<ans) ans=pp;

    }
    return ans;

}

i64 cal()
{
    i64 nn=n;
    if(n<=10) return n;
    i64 tmp=n;
    aNum=0;
    while(tmp) a[++aNum]=tmp%10,tmp/=10;

    i64 ans=10;
    int B=2;
    i64 cur=10;
    while(B<aNum)
    {
        ans+=cal(cur,cur*10-1,B);
        ans++;
        cur*=10;
        B++;
    }
    if(n==cur) return ans;
    int allZero=1;
    if(a[1]==0)
    {
        a[1]=9,a[2]--;
        for(int i=2;i<=aNum;i++)
        {
            if(a[i]>=0) break;
            a[i]+=10;
            a[i+1]--;
        }
        ans++;
        n--;
    }


    i64 A=n-cur;
    for(int i=aNum;i>=1;i--)
    {
        i64 tmp=0;
        for(int j=i;j<=aNum;j++) tmp=tmp*10+a[j];
        tmp++;
        i64 P=0;
        for(int j=i-1;j>=1;j--) P=P*10+a[j];
        if(P==0) continue;
        P--;
        tmp+=P;
        if(tmp<A) A=tmp;
    }

    return ans+A;

}

int main()
{
  //  freopen("A-small-attempt0.in1","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
  //  init();
    int T=myInt();
    int num=0;
    while(T--)
    {
        n=myInt();


        i64 nn=n;
        i64 ans=cal();
        printf("Case #%d: %lld\n",++num,ans);
      //  if(nn<N&&ans!=f[nn]) printf("%lld: %lld %lld\n",nn,ans,f[nn]);
    }
    return 0;
}

