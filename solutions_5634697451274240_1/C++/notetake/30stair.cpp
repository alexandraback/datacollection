#include <cstdio>

int T, t;

char A[110], tmp[110];
int n, pivot;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j, ans;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		printf("Case #%d: ", t);

		scanf("%s", A);
		for(i=0; A[i]!=NULL; i++){}
		n = i;
		
		for(pivot=n; A[pivot-1]!='-'&&pivot>0; pivot--){}

		for(ans=0; pivot!=0; ans++){
			if ( A[0] == '+' ){
				for(i=0; A[i]=='+'; i++) tmp[i] = A[i];
				for(j=0; j<i; j++) A[i-j-1] = tmp[j]=='+'?'-':'+';
			} else {
				for(j=0; j<pivot; j++) tmp[j] = A[j];
				for(j=0; j<pivot; j++) A[pivot-j-1] = tmp[j]=='+'?'-':'+';
				for(j=pivot-1; A[j]=='+'; j--){}
				pivot = j+1;
			}
		} printf("%d\n", ans);
	}

	return 0;
}