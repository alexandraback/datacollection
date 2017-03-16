#include<stdio.h>
char trans[30];
int main()
{
	
	char A[200];
	char B[200];
	/*
	while ( 1 ) {
		gets(A);
		gets(B);
		for ( int i = 0 ; A[i] ; i++ ) {
			if ( A[i] <= 'z' && A[i] >= 'a' ) {
				trans[A[i]-'a'] = B[i];
			}
		}
		for ( int i = 0 ; i < 26 ; i++ ) {
			if ( trans[i] != 0 )
				printf("%c", trans[i]);
			else
				printf("_");
		}
		puts("");
	}
	*/
	char ans[30] = {"yhesocvxduiglbkrztnwjpfmaq"};
	char ch;
	int T;
	scanf("%d", &T);
	while ( getchar() != '\n' )	;
	for ( int t = 1 ; t <= T ; t++ ) {
		printf("Case #%d: ", t);
		while ( (ch = getchar()) != '\n' ) {
			if ( ch != ' ' )
				printf("%c", ans[ch-'a']);
			else
				printf(" ");
		}
		puts("");
	}
	
	return 0;
}