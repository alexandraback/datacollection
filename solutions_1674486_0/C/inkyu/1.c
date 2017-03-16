#include <stdio.h>


int Matrix[1001][1001];
int List[1001][11];
int M[1001];

int main(int argc, char *argv[])
{
    int T, N, t, to, i, j, k;
    scanf("%d", &T);
    for(t = 1; t <= T; t++) {
	for(i = 1; i <= 1000; i++) {
	    for(j = 1; j <= 1000; j++)
		Matrix[i][j] = 0;
	    for(j = 0; j < 10; j++)
		List[i][j] = 0;
	    M[i] = 0;
	}
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
	    scanf("%d", &M[i]);
	    for(j = 0; j < M[i]; j++) {
		scanf("%d", &to);
		Matrix[i][to] = 1;
	    }
	}
	for(k = 1; k <= N; k++) 
	    for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
		    if(Matrix[i][k] && Matrix[k][j]) {
			Matrix[i][j] ++;
			if(Matrix[i][j] > 1) {
			    goto finished;
			}

		    }
	printf("Case #%d: No\n", t);
	continue;
    finished:
	printf("Case #%d: Yes\n", t);
    }
    
    return 0;
}
    
