#include<cstdio>
typedef long long ll;
ll po2[100];
ll b,reach;
int n,m;
int tmp[100][100];
void fun() {
  for(int i=0;i<m;i++) {
    if(reach+po2[i]>b) {
      for(int j=i-1;j>=0;j--) {
        if(reach+po2[j]<=b) {
          tmp[j][i]=1;
          reach+=po2[j];
          tmp[i][n-1]=1;
        }
      }
    } else {
      reach+=po2[i];
      tmp[i][n-1]=1;
      for(int j=0;j<i;j++) tmp[j][i]=1;
    }
    //printf("#%lld %d\n",reach,i);
  }
}
int main () {
  po2[0]=1; po2[1]=1; for(int i=2;i<60;i++) po2[i]=po2[i-1]*2;
  //for(int i=50;i<60;i++) printf("%lld ",po2[i]);
  //printf("\n");
  int T;scanf("%d",&T);
  for(int t=0;t<T;t++) {
    scanf("%d %lld",&n,&b);
    m=n-1;
    reach=0;
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++) {
        tmp[i][j]=0;
      }
    fun();
    printf("Case #%d: ",t+1);
    if(reach==b) {
      printf("POSSIBLE\n");
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d",tmp[i][j]);
        printf("\n");
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
