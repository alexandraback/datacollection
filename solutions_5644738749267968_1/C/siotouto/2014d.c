#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FALSE 0
#define TRUE 1

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int compare_float(const void *a,const void *b)
{
  if(*(float*)a - *(float*)b>0.0) return 1;
  else return -1;
}

int main(void)
{
  int i,j,k,T,t,n,decwin,warwin;
  float naomi[1024],ken[1024];
  scanf("%d",&T);
  t=T;
  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%f",&naomi[i]);
    qsort(naomi,n,sizeof(float),compare_float);
    for(i=0;i<n;i++) scanf("%f",&ken[i]);
    qsort(ken,n,sizeof(float),compare_float);
    decwin=0;
    warwin=0;
    j=0;
    for(i=0;i<n;i++){
      while(j<n&&ken[j]<naomi[i])j++;
      if(j>=n) warwin++;
      j++;
    }
    i=0;
    for(j=0;j<n;j++){
      while(i<n&&naomi[i]<ken[j])i++;
      if(i<n) decwin++;
      i++;
    }
    printf("Case #%d: %d %d\n",T-t,decwin,warwin);
  }
  return 0;
}
