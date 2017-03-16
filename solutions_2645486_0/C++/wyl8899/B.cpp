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

inline void ref(int &x,const int &y){
  if(x<y)x=y;
}

int a[20],f[20][20];

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T,Test=0;
  int E,R,n,i,s,j,k;
  for(scanf("%d",&T);T--;){
    printf("Case #%d: ",++Test);
    scanf("%d%d%d",&E,&R,&n);
    R=min(E,R);
    for(i=1;i<=n;++i)
      scanf("%d",a+i);
    memset(f,0,sizeof(f));
    for(i=0;i<n;++i)
      for(j=R;j<=E;++j)
        for(k=0;k<=j;++k)
          ref(f[i+1][min(E,j-k+R)],f[i][j]+k*a[i+1]);
    for(s=0,i=R;i<=E;++i)
      ref(s,f[n][i]);
    printf("%d\n",s);
  }
  return 0;
}
