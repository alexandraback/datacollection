#include<stdio.h>
#include<math.h>
       
int main()
{
   //freopen("1.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,i,j,k; 
    scanf("%d",&t);
    k=1;
    while(k<=t)
    { 
               int n,m,m1[105][105],mr[105]={0},mc[105]={0},f=1;
              scanf("%d%d",&n,&m);
              for(i=0;i<n;i++)for(j=0;j<m;j++){scanf("%d",&m1[i][j]);if(mr[i]<m1[i][j])mr[i]=m1[i][j];if(mc[j]<m1[i][j])mc[j]=m1[i][j];}
             
                  for(i=0;i<n;i++)for(j=0;f&&j<m;j++)if(m1[i][j]<mr[i]&&m1[i][j]<mc[j]){printf("Case #%d: NO\n",k);f=0;break; }
                if(f)  printf("Case #%d: YES\n",k); 
                  k++;  }
     return 0;
    }
