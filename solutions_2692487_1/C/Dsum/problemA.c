#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long osmos(int motes[], long long orig, int imote, int n)
{
     long long naddop, ndelop;
     long long smote;

     if (imote == n)
	  return 0;
     smote = motes[imote];
     naddop = 0;
     ndelop = n - imote;
     while (orig <= smote) {
	  naddop++;
	  orig = 2 * orig - 1;
     }
     orig += smote;
     if (ndelop <= naddop)
	  return ndelop;
     naddop += osmos(motes, orig, imote+1, n);
     
     return naddop > ndelop ? ndelop : naddop;
}

int numcmp(const void *a, const void *b)
{
     return *(int *)a - *(int *)b;
}

int main(void)
{
     int T, nc;
     long long amote;
     int motes[200], nmote;
     long long minop;
     int i;

     setvbuf(stdout, 0, _IONBF, 0);
     scanf("%d", &T);
     for (nc = 1; nc <= T; nc++) {
	  scanf("%lld%d", &amote, &nmote);
	  for (i = 1; i <= nmote; i++)
	       scanf("%d", &motes[i]);
	  nmote++;
	  motes[0] = 0;
	  qsort(motes, nmote, sizeof(motes[0]), numcmp);
	  /* for (i = 0; i < nmote; i++) */
	  /*      printf("%d ", motes[i]); */
	  if (amote == 1)
	       minop = nmote-1;
	  else
	       minop = osmos(motes, amote, 0, nmote);
	  printf("Case #%d: %lld\n", nc, minop);
     }

     return 0;
}
