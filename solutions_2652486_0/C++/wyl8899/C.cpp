//#define FILE_IO

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

const int maxn=200;
int N,M,R,K;
int a[maxn],b[maxn];
bool f[maxn],found;

void dfs(int n){
  int i;
  if(n==N){
    memset(f,0,sizeof(f));
    f[1]=1;
    for(i=0;i<N;++i)
      for(int j=maxn-1;j;--j)
        if(j%a[i]==0)
          f[j]=f[j]||f[j/a[i]];
    for(i=0;i<K;++i)
      if(!f[b[i]])break;
    if(i==K)
      found=1;
    return;
  }
  for(i=2;i<=M;++i){
    a[n]=i;
    dfs(n+1);
    if(found)return;
  }
}

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int i;
  scanf("%*d%d%d%d%d",&R,&N,&M,&K);
  puts("Case #1:");
  while(R--){
    for(i=0;i<K;++i)
      scanf("%d",b+i);
    found=0;
    dfs(0);
    for(i=0;i<N;++i)
      printf("%d",a[i]);
    puts("");
  }
  return 0;
}

