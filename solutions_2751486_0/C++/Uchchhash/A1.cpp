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
#define MAX 105
//struct pii{int x,y;pii(int a=0,int b=0){x=a,y=b;}};
//bool operator<(pii a,pii b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
//int L[],pre[],to[],C[],ne;
//inline void addEdge(int u,int v,int c=1){to[ne]=v,pre[ne]=L[u],C[ne]=c;L[u]=ne++;}

char p[MAX];
int A[MAX],n;

bool check(int l,int r)
{
    int mx=0;
    f1(i,l,r+1)
    {
        if(A[i]==0)continue;
        int j=i+1;
        while(j<=r&&A[j]==A[i])j++;
        mx=max(j-i,mx);
        i=j-1;
    }
    return mx>=n;
}

int ret(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 0;
    return 1;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //fin("in.txt");
    //fout("out.txt");
    int tst,kas=0;scanf("%d",&tst);
    while(tst--)
    {
        int ans=0;
        printf("Case #%d: ",++kas);
        scanf("%s%d",p,&n);
        fs(i,p)A[i]=ret(p[i]);
        fs(i,p)f0(j,i+1)
        {
            ans=ans+check(j,i);
        }
        printf("%d\n",ans);
    }
	return 0;
}
