#include <bits/stdc++.h>
#define MAXS 25


int main()
{
	char str[MAXS], resp[MAXS];
	int T, tc = 1;
	int mark[MAXS];
	scanf("%d", &T);
	getchar();
	while ( T-- ) {
		gets(str);
		//printf("%s\n", str);
		int tam = strlen(str);
		for ( int i = 0; i < tam; i++ )
			mark[i] = false;
		mark[0] = true;
		int atual = 0; mark[0] = true;
		for ( int i = 1; i < tam; i++ ) {
			if ( str[i] >= str[atual] ) {
				mark[i] = true;
				atual = i;
			}
		}
		int count = 0;
		for ( int i = tam-1; i >= 0; i-- ) {
			if ( mark[i] == true ) {
				resp[count++] = str[i];
			}
		}
		for ( int i = 0; i < tam; i++ ) {
			if ( mark[i] == false ) {
				resp[count++] = str[i];
			}
		}
		resp[count] = '\0';
		printf("Case #%d: %s\n", tc++, resp);
	}
	return 0;
}