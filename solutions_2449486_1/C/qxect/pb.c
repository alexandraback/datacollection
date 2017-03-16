#include<stdio.h>
#include<string.h>

int nu[110][110];

int main()
{
  int tn;
  int n,m;
  int i,j,k,z;
  int a,b;
  int pos;


  scanf("%d",&tn);
  for(z=1;z<=tn;z++){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        scanf("%d",&nu[i][j]);
    pos = 1;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        a = b = 1;
        for(k=0;k<n;k++)if(nu[k][j]>nu[i][j])a = 0;
        for(k=0;k<m;k++)if(nu[i][k]>nu[i][j])b = 0;
        if(a==0 && b==0)pos = 0;
      }
    }

    printf("Case #%d: %s\n",z,pos?"YES":"NO");
  }
  return 0;
}
