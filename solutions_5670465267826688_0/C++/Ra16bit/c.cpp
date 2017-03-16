#include <stdio.h>
const int a[4][4]={
{3,2,1,0},
{2,3,0,1},
{1,0,3,2},
{0,1,2,3}
};
bool b[4][4];
char s[10100];
int t,tt,n,m,i,j,cur,prv,prvb,tot,totb,f[10100][3];
int main() {
  b[0][0]=true; b[0][2]=true;
  b[1][0]=true; b[1][1]=true;
  b[2][1]=true; b[2][2]=true;
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    if (n*m>10000) fprintf(stderr, "!!!!\n");
    for (i=n; i<n*m; i++) s[i]=s[i-n];
    n*=m;
    for (i=0; i<n; i++) {
      tot=3;
      totb=false;
      for (j=i; j<n; j++) {
        cur=s[j]-'i';
        prv=tot;
        prvb=totb;
        tot=a[prv][cur];
        totb=b[prv][cur];
        if (prvb) totb=!totb;
        //printf("%d %d | %d %d\n",i,j,tot,totb);
        if (i==0) {
          if (tot==0 && totb==false) f[j][0]=t;
        } else {
          if (f[i-1][0]==t && tot==1 && totb==false) f[j][1]=t;
          if (f[i-1][1]==t && tot==2 && totb==false) f[j][2]=t;
        }
      }
    }
    printf("Case #%d: ",t);
    puts((f[n-1][2]==t)?"YES":"NO");
    fprintf(stderr, "Case #%d\n",t);
  }
  return 0;
}
