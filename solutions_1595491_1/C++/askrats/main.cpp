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

void solve()
{
	int N = get_int();
	int S = get_int();
	int p = get_int();

	int result = 0;
	int s_num = 0;

	FOR(i, N) {
		int total = get_int();

		int base = total / 3;
		int remain = total % 3;
		
//		printf( "%d(%d), ", base, remain);

		// Šù‚É’´‚¦‚Ä‚é
		if (base >= p) {
			++result;
			continue;
		}

		switch (remain) {
		case 0:
			if (base > 0) {
				if (base + 1 >= p) {
					if (s_num < S) {
						// surprising‚Æ‚·‚é
						++s_num;
						++result;
					}
				}
			}
			break;
		case 1:
			// ’´‚¦‚½
			if (base + 1 >= p) {
				++result;
			}
			break;
		case 2:
			if (base + 1 >= p) {
				++result;
				break;
			}
			if (base + 2 >= p) {
				if (s_num < S) {
					// suprising
					++s_num;
					++result;
				}
			}
			break;
		}

	}

	printf( "%d", result );
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
