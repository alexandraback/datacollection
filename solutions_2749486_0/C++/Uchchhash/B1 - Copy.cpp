//This is the painkiller...
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
#include<time.h>
#include<set>
#include<vector>
using namespace std;
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define abv(a) ((a)>0?(a):-(a))
#define sqr(a) ((a)*(a))
#define fs(i,s) for(int i=0;s[i];i++)
#define fg(e,u) for(int e=L[u];e!=-1;e=pre[e])
#define f0(i,n) for(int i=0;i<(n);i++)
#define f1(i,a,n) for(int i=(a);i<(n);i++)
#define f2(i,a,n,b) for(int i=(a);i<(n);i+=(b))
#define rf0(i,n) for(int i=(n);i>=0;i--)
#define rf1(i,a,n) for(int i=(a);i>(n);i--)
#define rf2(i,a,n,b) for(int i=(a);i>(n);i-=(b))
#define mem(a,v) memset(a,v,sizeof(a))
#define pq priority_queue
#define pb push_back
#define pq priority_queue
#define sz size
#define vint vector<int>
#define vvint vector<vector<int> >
#define vstr vector<string>
#define emt empty
#define clr clear
#define bn begin
#define en end
#define all(a) a.bn(),a.en()
#define dlt(v,a) v.erase(v.bn()+a)
#define dlst(v) v.erase(v.bn()+((int)v.size()-1))
#define nset(S,v) S.erase(find(v))
#define scn(a,b,n) f1(j,b,n+b)cin>>a[j]
#define scm(a,b,c,m,n) f1(i,b,m+b)scn(a[i],c,n)
#define prn(a,b,n) f1(j,b,n+b){if(j>b)cout<<' ';cout<<a[j];}
#define prm(a,b,c,m,n) f1(i,b,m+b){prn(a[i],c,n);cout<<endl;}
#define greater(a,b) ((a)>(b)+eps)
#define zero(a) (fabs(a)<eps)
#define Int __int64
#define Long long long
const double Pi=acos(-1.0);
Long mod=1000000007;
#define inf (1<<30)
#define eps 1e-9
#define MAX 1205
#define id(i) (i+600)
struct pii{int x,y;pii(int a=0,int b=0){x=a,y=b;}};
//bool operator<(pii a,pii b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
//int L[],pre[],to[],C[],ne;
//inline void addEdge(int u,int v,int c=1){to[ne]=v,pre[ne]=L[u],C[ne]=c;L[u]=ne++;}

int D[MAX][MAX];
int mother[MAX][MAX];
pii Q[MAX*MAX];

int di[]={1,-1,0,0};
int dj[]={0,0,1,-1,};
char p[5]={"EWNS"};

void bfs(int X,int Y)
{
    int fr=0,bk=0;
    mem(D,-1);
    mem(mother,-1);
    D[0][0]=0;
    mother[0][0]=-2;
    Q[bk++]=pii(0,0);
    while(fr<bk)
    {
        int x=Q[fr].x;
        int y=Q[fr++].y;
        if(x==X&y==Y)return;
        f0(t,4)
        {
            int c=D[id(x)][id(y)]+1;
            int a=x+c*di[t];
            int b=y+c*dj[t];
            if(D[id(a)][id(b)]==-1)
            {
                D[id(a)][id(b)]=c;
                mother[id(a)][id(b)]=t;
                Q[bk++]=pii(a,b);
            }
        }
    }
}

char ans[505];

int main()
{
    //ios_base::sync_with_stdio(false);
    //fin("in.txt");
    //fout("out.txt");
    int tst,kas=0;scanf("%d",&tst);
    while(tst--)
    {
        printf("Case #%d: ",++kas);
        int a,b,k=0;scanf("%d%d",&a,&b);
        bfs(a,b);
        while(a!=0||b!=0)
        {
            int c=D[id(a)][id(b)];
            int t=mother[id(a)][id(b)];
            //if(t==-1)cout<<"ouch!\n";
            ans[k++]=p[t];
            a=a-c*di[t];
            b=b-c*dj[t];
        }
        rf0(i,k-1)printf("%c",ans[i]);putchar(10);
    }
	return 0;
}
