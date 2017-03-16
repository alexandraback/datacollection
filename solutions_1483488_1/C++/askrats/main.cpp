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
	int A = get_int();
	int B = get_int();

	int result = 0;

	int places = 1;
	{
		int temp = A;
		do {
			temp /= 10;
			if (temp > 0) places *= 10;
			else break;
		} while (1);
	}

	FORr(number, A, B+1) {
		int mod_number = number;
		do {
			// recycle
			int latest = mod_number % 10;
			mod_number = mod_number / 10 + latest * places;
			// judge
			if (mod_number > number){
				if (A <= mod_number && mod_number <= B) ++result;
			}
		} while (mod_number != number);
	}

	printf("%d", result);
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
