#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string>

#define FORr(i,A,B)	for (int i=(A); i<(B); ++i)
#define FOR(i, N)	FORr(i,0,N)

using namespace std;

int 	get_int()		{int a; 	scanf("%d", &a); 	return a;}
double	get_double()	{double a;	scanf("%lf", &a);	return a;}
char	get_char()		{char c; 	scanf("%c", &c); 	return c;}

char str_buf[100000];
string	get_str()		{scanf("%s", str_buf); return str_buf;}

bool classes[1000];

int inherits_from[1000][10];
int inherits_num[1000];

bool dive(int curr, bool* classes) {
//	printf( "%d>>>>%d\n", curr, inherits_num[curr] );
	FOR(i, inherits_num[curr]) {
		int base = inherits_from[curr][i];
//		printf( "%d -> %d\n", curr, base );
		if ( classes[base] == true) {
			// diamond !
			return true;
		} else {
			classes[base] = true;
//			printf( "* %d\n", base );
			if ( dive( base, classes ) ) {
				return true;
			}
		}
	}
//	printf( "%d<<<<\n", curr );
	return false;
}

void solve()
{
	int N = get_int();

	FOR(i, N) {
		int num = get_int();
		inherits_num[i] = num;
		FOR(j, num) {
			inherits_from[i][j] = get_int() - 1;
		}
	}

	bool success = false;
	FOR(i, N) {
		FOR(j, N) {
			classes[j] = false;
		}

		if (dive(i, classes)) {
			success = true;
			break;
		}
	}

	if (success) printf( "Yes" );
	else printf( "No" );
}

int main()
{
	int T = get_int();
	FOR (t, T)
	{
		printf("Case #%d: ", t + 1);
		solve();
		printf("\n");
	}
}
