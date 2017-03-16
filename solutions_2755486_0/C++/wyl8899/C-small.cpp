//#define FILE_IO

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef double lf; 

typedef pair<int,int> pii;
typedef pair<lf,lf> pff;
#define mp make_pair
#define X first
#define Y second  

#define pb push_back
#define forI_(i,V,_) for(typeof(V.end())i=_;i!=V.end();++i)
#define forI(i,V) forI_(i,V,V.begin())

int a[10010];

int check(int *a,int x,int y,int w){
  for(int i=x;i<=y;++i)
    if(a[i]<w)return 1;
  return 0;
}
void sol(int *a,int x,int y,int w){
  for(int i=x;i<=y;++i)
    a[i]=max(a[i],w);
}

struct rec{
  int t,x,y,w;
  rec(){}
  rec(int t,int x,int y,int w):t(t),x(x),y(y),w(w){}
}A[1000010];
inline bool operator <(const rec &a,const rec &b){
  return a.t<b.t;
}

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T,Case=0;
  int N,m,t,n,l,r,w,dt,dx,dw,i,j,ans;
  for(scanf("%d",&T);T--;){
    scanf("%d",&N),m=0;
    while(N--){
      scanf("%d%d%d%d%d%d%d%d",&t,&n,&l,&r,&w,&dt,&dx,&dw);
      for(i=0;i<n;++i){
        A[m++]=rec(t,l,r-1,w);
        t+=dt,l+=dx,r+=dx,w+=dw;
      }
    }
    memset(a,0,sizeof(a));
    ans=0;
    sort(A,A+m);
    /*for(i=0;i<m;++i)
      printf("%d %d %d %d\n",A[i].t,A[i].x,A[i].y,A[i].w);*/
    for(i=0;i<m;i=r){
      for(r=i+1;r<m&&A[r].t==A[i].t;++r);
      for(j=i;j<r;++j)ans+=check(a+5000,A[j].x,A[j].y,A[j].w);
      for(j=i;j<r;++j)sol(a+5000,A[j].x,A[j].y,A[j].w);
    }
    printf("Case #%d: %d\n",++Case,ans);
  }
  return 0;
}
