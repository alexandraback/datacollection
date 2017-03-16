#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

FILE *in, *out, *aux;

int A[90000][140];
int M, N, T;
char S[400];
int Aux[140], Left[140], Right[140];
int test, i, j;

void add(int A[], int B[])
{
      int i, t = 0;
      for (i=1; i<=A[0] || i<=B[0] || t; i++, t/=10)
              A[i] = (t += A[i] + B[i]) % 10;
      A[0] = i - 1;
}

inline int compare(int A[], int B[])
{
	if (A[0] < B[0]) return -1;
	if (A[0] > B[0]) return 1;
	int w;
	for (w = A[0]; w >= 1 && A[w] == B[w]; --w);
	if (A[w] < B[w]) return -1;
	if (A[w] > B[w]) return 1;
	return 0;
}

inline int f(int T[])
{
	int st, dr, mij, sol;
	st = 1; dr = M; sol = 0;
	while (st <= dr){
		mij = (st + dr) >> 1;

		if (compare(A[mij], T) == -1){
			sol = mij;
			st = mij + 1;
		}
		else
			dr = mij - 1;
	}
	return sol;
}

int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	aux = fopen("auxiliar.txt","r");
	
	fscanf(aux, "%d\n", &M);
	for (i = 1; i <= M; ++i){
		fgets(S, 150, aux);
		A[i][0] = strlen(S) - 1;
		for (j = 1; j <= A[i][0]; ++j)
			A[i][j] = S[j - 1] - '0';
	}
	
	fscanf(in, "%d\n", &T);
	for (test = 1; test <= T; ++test){
		fgets(S, 400, in);
		memset(Left, 0, sizeof(Left));
		memset(Right, 0, sizeof(Right));
		for (j = 0; S[j] >= '0' && S[j] <= '9'; ++j)
			Left[++Left[0]] = S[j] - '0';
		reverse(Left+1, Left+Left[0]+1);
		++j;
		for (; S[j] >= '0' && S[j] <= '9'; ++j)
			Right[++Right[0]] = S[j] - '0';
		reverse(Right+1, Right+Right[0]+1);
		
		Aux[0] = Aux[1] = 1;
		add(Right, Aux);
		
		fprintf(out, "Case #%d: %d\n", test, f(Right) - f(Left));
	}
	
	fclose(out); fclose(in); fclose(aux);
	return 0;
}