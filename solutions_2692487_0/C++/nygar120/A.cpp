#include <stdio.h>
#include <stdlib.h>

int tab[100];
int Af, N;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int min(int a, int b) {if (a<b) return a; return b;}
int recu(int pos, int A) {
	//printf("recu %d %d\n",tab[pos],A);
	if (pos == N) return 0;
	if (A > tab[pos]) return recu(pos+1, A+tab[pos]);
	
	//on test en supprimant
	int best = 1 + recu(pos+1,A);
	//printf("best en suppr: %d\n",best);
	//cas special
	if (A == 1) return best;
	//sinon
	
	int i = 0;
	while (A <= tab[pos]) {
		A += (A-1);
		i++;
	}
	
	if (i < best) {
		best = min(best, i+ recu(pos+1,A+tab[pos]));
	}
	
	return best;
}
int main() {
   int T, c, i;
   scanf("%d",&T);
   for (c=1;c<=T;c++) {
   		scanf("%d %d",&Af, &N);
   		for (i=0; i<N; i++) {
   			scanf("%d",&tab[i]);
		}
		qsort (tab, N, sizeof(int), compare);
   		printf("Case #%d: %d\n",c, recu(0, Af));
   }
   return 0;
}
