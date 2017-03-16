//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define PI  acos(-1.0)
#define eps 1e-8
#define LL  long long
#define PB  push_back
#define MP  make_pair
#define PQ  priority_queue
#define MII map<int,int>::iterator
#define MLL map<LL,LL>::iterator
#define PII pair<int,int>
#define SI  set<int>::iterator
#define SL  set<LL>::iterator
#define MSI map<string,int>::iterator
#define IN  freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
#define BUG printf("bug************bug************bug\n");

#define MEM(a,b) memset(a,b,sizeof(a))
#define M_SI     multiset<int>::iterator

using namespace std;

const int maxn=10000+10;
struct node
{
    double d,sp;
    node(double d=0,double sp=0):d(d),sp(sp){};
}P[maxn];

int dcmp(double x)
{
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return -1;
}

int main()
{
    IN; OUT;
    int t,cas=0,n,h;
    double d,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int N=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%d%lf",&d,&h,&m);
            for (int j=0;j<h;j++) P[++N]=node(d,m+j);
        }
        if (N==1) {printf("Case #%d: 0\n",++cas);continue;}
        if (N==2)
        {
            int ans=1;
            double v1=(360-P[1].d)/P[1].sp;
            double v2=(360-P[2].d)/P[2].sp;
            double s1=v1*P[2].sp+P[1].d;
            if (dcmp(s1-360.0)>0 && dcmp(s1-720.0)<0) ans=min(ans,0);
            double s2=v2*P[1].sp+P[2].d;
            if (dcmp(s2-360.0)>0 && dcmp(s2-720.0)<0) ans=min(ans,0);
            printf("Case #%d: %d\n",++cas,ans);
            continue;
        }
        else printf("Case #%d: 0\n",++cas);
    }
    return 0;
}
