#include<stdio.h>
#include<stdlib.h>

int main(void){
  unsigned int A,l,t,ti;
  int i,j,k,b;
  double *e,*p,tmp,min,*prod_p,now;

  scanf("%u",&t);
  for(ti=1;ti<=t;ti++){
    scanf("%u %u",&A,&l);
    min=l+2;

    p=(double *)calloc(A,sizeof(double));
    e=(double *)calloc(A+1,sizeof(double));
    prod_p=(double *)calloc(A+1,sizeof(double));
    for(i=0;i<A;i++) scanf("%lf",p+i);
    for(i=0,tmp=1;i<A;i++){
      prod_p[i]=(1-p[i])*tmp;
      tmp*=p[i];
    }
    prod_p[A]=tmp;
    //for(i=0;i<=A;i++) printf("prod_p[%d]=%f\n",i,prod_p[i]);

    for(i=A-1,e[A]=0;i>=0;i--){
      e[i]=e[i+1]+prod_p[A-i-1]*(l+1);
    }
    // for(i=0;i<=A;i++) printf("e[%d]=%f\n",i,e[i]);

    for(b=0;b<=A;b++){
      now=2*b+l-A+1+e[b];
      //printf("b=%u,now=%f\n",b,now);
      if(min>now) min=now;
    }
    printf("Case #%u: %.06f\n",ti,min);
    free(e);
    free(prod_p);
    free(p);
  }
  return 0;
}
