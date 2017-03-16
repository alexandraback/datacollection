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

const int maxm=16000010;

int M,a[maxm],b[maxm],s[maxm];

void pus(int k,int l,int r){
  if(s[k]==0)return;
  if(l!=r){
    s[k<<1]=max(s[k<<1],s[k]);
    s[(k<<1)+1]=max(s[(k<<1)+1],s[k]);
  }
  a[k]=max(a[k],s[k]);
  s[k]=0;
}
void upd(int k,int l,int r){
  pus(k,l,r);
  if(l!=r){
    int m=l+r>>1;
    pus(k<<1,l,m);
    pus((k<<1)+1,m+1,r);
    a[k]=min(a[k<<1],a[(k<<1)+1]);
  }
}

void upd(int k,int l,int r,int x,int y,int w){
  if(l==x&&r==y){
    s[k]=max(s[k],w);
    pus(k,l,r);
    return;
  }
  int m=l+r>>1;
  if(y<=m)upd(k<<1,l,m,x,y,w);
  else if(x>m)upd((k<<1)+1,m+1,r,x,y,w);
  else upd(k<<1,l,m,x,m,w),upd((k<<1)+1,m+1,r,m+1,y,w);
  upd(k,l,r);
}

int gmin(int k,int l,int r,int x,int y){
  if(l==x&&r==y){
    upd(k,l,r);
    return a[k];
  }
  pus(k,l,r);
  int m=l+r>>1;
  if(y<=m)return gmin(k<<1,l,m,x,y);
  if(x>m)return gmin((k<<1)+1,m+1,r,x,y);
  return min(gmin(k<<1,l,m,x,m),gmin((k<<1)+1,m+1,r,m+1,y));
}

int check(int x,int y,int w){
  return gmin(1,1,M,x,y)<w;
}
void sol(int x,int y,int w){
  upd(1,1,M,x,y,w);
}

struct rec{
  int t,x,y,w;
  rec(){}
  rec(int t,int x,int y,int w):t(t),x(x),y(y),w(w){}
}A[maxm];
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
    scanf("%d",&N),m=0,M=0;
    while(N--){
      scanf("%d%d%d%d%d%d%d%d",&t,&n,&l,&r,&w,&dt,&dx,&dw);
      for(i=0;i<n;++i){
        A[m++]=rec(t,l,r-1,w);
        b[M++]=l,b[M++]=r-1,b[M++]=l-1,b[M++]=r;
        t+=dt,l+=dx,r+=dx,w+=dw;
      }
    }
    sort(b,b+M);
    M=unique(b,b+M)-b;
    /*for(i=0;i<m;++i)
      printf("%d %d %d %d\n",A[i].t,A[i].x,A[i].y,A[i].w);
    puts("");*/
    for(i=0;i<m;++i){
      A[i].x=lower_bound(b,b+M,A[i].x)-b+1;
      A[i].y=lower_bound(b,b+M,A[i].y)-b+1;
    }
    /*for(i=0;i<m;++i)
      printf("%d %d %d %d\n",A[i].t,A[i].x,A[i].y,A[i].w);
    puts("");*/
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    ans=0;
    sort(A,A+m);
    for(i=0;i<m;i=r){
      for(r=i+1;r<m&&A[r].t==A[i].t;++r);
      for(j=i;j<r;++j)ans+=check(A[j].x,A[j].y,A[j].w);
      for(j=i;j<r;++j)sol(A[j].x,A[j].y,A[j].w);
    }
    printf("Case #%d: %d\n",++Case,ans);
    fprintf(stderr,"%d\n",Case);
  }
  return 0;
}
