#include<stdio.h>
#include<stdlib.h>

int main(void){
  int t,n,*s,i,j,k,x,y,count1,dis;
  double *p,obj,nobj;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    x=0;
    scanf("%d",&n);
    s=(int *)calloc(n,sizeof(int));
    p=(double *)calloc(n,sizeof(double));
    for(j=0;j<n;j++){
      scanf("%d",(s+j));
      x+=*(s+j);
    }
    y=x;
    k=n;
    obj=2*(double)x/n;
    nobj=obj;
    do{
      count1=0;
      dis=0;
      for(j=0;j<n;j++){
	if(nobj<*(s+j)){
	  count1++;
	  dis+=*(s+j);
	  *(s+j)=-1;
	}
      }
      if(count1!=0){
	k-=count1;
	y-=dis;
	nobj=((double)y+(double)x)/k;
      }
      //printf("%d\n",count1);
    }while(count1!=0);
      //printf("%f\n",nobj);
    for(j=0;j<n;j++){
      if(*(s+j)==-1){
	*(p+j)=0;
      }else{
	*(p+j)=(nobj-*(s+j))*100/x;
      }
    }
    printf("Case #%d: ",i+1);
    for(j=0;j<n;j++){
      printf("%f ",*(p+j));
    }
    putchar('\n');
    free(s);
    free(p);
  }
  return 0;
}    
