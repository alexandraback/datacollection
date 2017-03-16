#include <stdio.h>
#include <string.h>

char S[200];
int A[200];
int i, N, M;
FILE *aux;
FILE *in;

void mul(int A[], int B[])
{
      int i, j, t, C[200];
      memset(C, 0, sizeof(C));
      for (i = 1; i <= A[0]; i++)
      {
              for (t=0, j=1; j <= B[0] || t; j++, t/=10)
                      C[i+j-1]=(t+=C[i+j-1]+A[i]*B[j])%10;
              if (i + j - 2 > C[0]) C[0] = i + j - 2;
      }
      memcpy(A, C, sizeof(C));
}

inline void afis()
{
	memset(A, 0, sizeof(A));
	A[0] = i;
	for (int i = 1; i <= A[0]; ++i)
		A[i] = S[i] - '0';
	mul(A, A);
	for (int i = A[0]; i >= 1; --i)
		fprintf(aux, "%d", A[i]);
	fprintf(aux, "\n");
}

void back(int lv, int Suma)
{
	if (i % 2){ //odd
		if (Suma >= 10) return;
		if (lv - 1 == (i + 1) / 2){
			afis();
		//	++M;
			return;
		}
		if (lv != 1){
			S[lv] = '0';
			S[i - lv + 1] = '0';
			back(lv + 1, Suma);
		}
		if (lv ==  (i + 1) / 2){
			S[lv] = '1';
			S[i - lv + 1] = '1';
			back(lv + 1, Suma + 1);
		}
		else{
			S[lv] = '1';
			S[i - lv + 1] = '1';
			back(lv + 1, Suma + 2);
		}
		
		if (lv == (i + 1) / 2){
			S[lv] = '2';
			S[i - lv + 1] = '2';
			back(lv + 1, Suma + 4);
		}
		else {
			S[lv] = '2';
			S[i - lv + 1] = '2';
			back(lv + 1, Suma + 8);
		}
	}
	else { //even
		if (Suma >= 10) return;
		if (lv - 1 == i / 2){
			afis();
		//	++M;
			return;
		}
		if (lv != 1){
			S[lv] = '0';
			S[i - lv + 1] = '0';
			back(lv + 1, Suma);
		}
		S[lv] = '1';
		S[i - lv + 1] = '1';
		back(lv + 1, Suma + 2);
		
		S[lv] = '2';
		S[i - lv + 1] = '2';
		back(lv + 1, Suma + 8);
	}
}

int main()
{
	aux = fopen("auxiliar.txt","w");
	in = fopen("in.txt", "r");
	
	fscanf(in, "%d", &N);
	M = 88136;
	fprintf(aux, "%d\n", M);
	
	fprintf(aux, "%s\n", "1");
	fprintf(aux, "%s\n", "4");
	fprintf(aux, "%s\n", "9");
	
	for (i = 2; i <= N; ++i)
		back(1, 0);
	
	//fprintf(aux, "%d\n", M);
	fclose(aux); fclose(in);
	return 0;
}