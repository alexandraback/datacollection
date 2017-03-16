#include <stdio.h>
#include <stdlib.h>

//#define SMALL
#define LARGE

int main(int argc, char *argv[])
{
  int c, i, T, N, S, p, x, s, u, l;
  
  freopen("b.txt", "rt", stdin);
#ifdef SMALL
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif

  scanf("%d\n",&T);
  for (c=0;c<T;c++) {
      scanf("%d %d %d",&N, &S, &p);
      s=0; u=3*p-2; l=3*p-4;
      if(p==0) u=0;
      if(p<=1) l=u;
      for (i=0;i<N;i++) {
          scanf("%d",&x);
          if(x>=u) s++;
          if((x>=l)&&(x<u)&&(S>0)) {
            S--;
            s++;
          }
      }
      printf("Case #%d: %d\n",c+1, s);
  }  
  return 0;
}
