#include <cstdio>

int t, T;

int J, P, S, K;
int A[30], B[30], C[30];

int ans, l, ans_print[30];
int trace[30], AB[1000], BC[1000], CA[1000];

void dfs ( int x, int now )
{
	if ( x > l ){
		if ( ans < now ){
			ans = now;

			int i;
			for(i=1; i<=now; i++) ans_print[i] = trace[i];
		}

		return;
	}

	// nop
	dfs ( x+1, now );

	// doit
	if ( AB[A[x]*100+B[x]] < K && BC[B[x]*100+C[x]] < K && CA[C[x]*100+A[x]] < K ){
		AB[A[x]*100+B[x]] ++;
		BC[B[x]*100+C[x]] ++;
		CA[C[x]*100+A[x]] ++;
		trace[now+1] = x;

		dfs ( x+1, now+1 );

		AB[A[x]*100+B[x]] --;
		BC[B[x]*100+C[x]] --;
		CA[C[x]*100+A[x]] --;
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j, k;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		scanf("%d%d%d%d", &J, &P, &S, &K);
		
		l = 0;
		for(i=1; i<=J; i++){
			for(j=1; j<=P; j++){
				for(k=1; k<=S; k++){
					l ++;
					A[l] = i, B[l] = j, C[l] = k;
				}
			}
		}

		ans = 0;
		dfs ( 1, 0 );

		printf("Case #%d: %d\n", t, ans);
		for(i=1; i<=ans; i++){
			printf("%d %d %d\n", A[ans_print[i]], B[ans_print[i]], C[ans_print[i]]);
		}
	}

	return 0;
}