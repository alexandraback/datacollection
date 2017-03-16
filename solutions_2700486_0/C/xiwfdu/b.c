#include <stdio.h>
const ee=0.000000000001;
double d[21][20000][10000];

int thr(int k,int x,int y,double p){
  if(p<ee)
    return;
  if(y==1){
    d[k][x][y]+=p;
    return;
  }
  
  if(k>1)
    d[k][x][y]+=p*(d[k-1][x-1][y-1]*d[k-2][x+1][y-1]+d[k-2][x-1][y-1]*d[k-1][x+1][y-1]);

  thr(k,x,y-1,p*(1-d[k-1][x][y-2])*(1-d[k-1][x-1][y-1])*(1-d[k-1][x+1][y-1]));

  thr(k,x-1,y-1,p*d[k-1][x][y-2]*0.5*(1-d[k-1][x+1][y-1])*(1-d[k-1][x-1][y-1]));
  thr(k,x+1,y-1,p*d[k-1][x][y-2]*0.5*(1-d[k-1][x+1][y-1])*(1-d[k-1][x-1][y-1]));

  thr(k,x-1,y-1,p*d[k-1][x+1][y-1]*(1-d[k-1][x-1][y-1]));
  thr(k,x+1,y-1,p*d[k-1][x-1][y-1]*(1-d[k-1][x+1][y-1]));

  
}
  

int main(){
  int t,ti;
  int n,x,y,k,i,j;
 
  for(k=0;k<=20;k++)
    for(i=0;i<200;i++)
      for(j=0;j<100;j++)
	d[k][i][j]=0;

  for(k=1;k<=20;k++){
    thr(k,100,10,1.0);
    for(i=0;i<200;i++)
      for(j=0;j<100;j++)
	d[k][i][j]+=d[k-1][i][j];
  }  
  

  scanf("%d",&t);
  for(ti=0;ti<t;ti++){
    scanf("%d %d %d",&n,&x,&y);
    printf("Case #%d: %f\n",ti+1,d[n][x+100][y+1]);
  }
}
