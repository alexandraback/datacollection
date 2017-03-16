#include <stdio.h>
#include <stdlib.h>

#define SMALL
//#define LARGE

int main(int argc, char *argv[])
{
  int c,T,A,B,t,m,n,x;
  
  freopen("c.txt", "rt", stdin);
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
#endif

  scanf("%d\n",&T);
  for (c=0;c<T;c++) {
      scanf("%d %d\n",&A,&B);
      t=0; x=1; if(A>9) x=10; if(A>99) x=100; if(A>999) x=1000; 
      if(A>9999) x=10000; if(A>99999) x=100000; if(A>999999) x=1000000; 
      for (m=A;m<=B;m++) {
          n=x*(m%10)+(m/10);
          while(n!=m) {
             if((n<m)&&(n>=A)) { t++; 
             }
             n=x*(n%10)+(n/10);
          }
      }
      printf("Case #%d: %d\n",c+1,t);
  }  
}
