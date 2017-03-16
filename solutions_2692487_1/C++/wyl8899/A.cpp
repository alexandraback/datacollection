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

const int maxn=10010;
int a[maxn];

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T=0,n,w,ans,i,s;
  scanf("%*d");
  while(scanf("%d%d",&w,&n)!=EOF){
    printf("Case #%d: ",++T);
    for(i=0;i<n;++i)scanf("%d",a+i);
    sort(a,a+n);
    if(w==1){
      printf("%d\n",n);
      continue;
    }
    ans=n,s=0;
    for(i=0;i<n;++i){
      ans=min(ans,s+n-i);
      while(w<=a[i])
        ++s,w=2*w-1;
      w+=a[i];
    }
    ans=min(ans,s);
    printf("%d\n",ans);
  }
  return 0;
}
