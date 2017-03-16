#include <cstdio>
#include <cstring>

#define N 1001

int T,n,t[N][2];
int chk[N][2];
int cnt,pt;

int main() {
  int i,j,k,l,a;
  scanf("%d",&T);
  for(int lT=1;lT<=T;lT++){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&t[i][0],&t[i][1]);
    memset(chk,0,sizeof(chk));
    cnt=pt=0;
    while(1){
      k=l=a=-1;
      for(i=0;i<n;i++)
        if(!chk[i][1] && t[i][1]<=pt){
          k=i;l=1;break;
        }
      if(k<0){
        for(i=0;i<n;i++)
          if(!chk[i][1] && !chk[i][0] && t[i][0]<=pt){
            if(k<0 || t[i][1]>t[k][1]){
              k=i;l=0;
            }
          }
      }
      if(k<0)break;
      cnt++;
      if(l==1){
        if(chk[k][0])
          pt++;
        else
          pt+=2;
      }else{
        pt++;
      }
      chk[k][l]=1;
    }
    if(pt<2*n)
      printf("Case #%d: Too Bad\n",lT);
    else
      printf("Case #%d: %d\n",lT,cnt);
  }
  return 0;
}
