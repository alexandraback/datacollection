#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int h[2600];
int i,j,k,n,m,x,ca,cas,c;

int main(){

  freopen("B_s.in","r",stdin);
  freopen("B_s.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    memset(h,0,sizeof(h));
    scanf("%d",&n);
    for (i=1;i<=2*n-1;i++)
      for (j=1;j<=n;j++){
        scanf("%d",&x);
        h[x]++;
      }
    printf("Case #%d: ",ca);
    c=0;
    for (i=1;i<=2500;i++)
      if (h[i] & 1){
        printf("%d",i);
        c++;
        if (c==n){
          printf("\n");
          break;
        }
        else printf(" ");
      }
  }
  return 0;



}

