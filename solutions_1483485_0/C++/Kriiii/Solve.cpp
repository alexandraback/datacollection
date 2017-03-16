#include <stdio.h>

char A[110];
int T,C,U[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i;

	scanf ("%d\n",&T); while (T--){
		gets(A);
		for (i=0;A[i];i++) if (A[i] != ' ') A[i] = U[A[i]-'a'] + 'a';
		printf ("Case #%d: %s\n",++C,A);
	}

	return 0;
}