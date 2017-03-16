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

int scores[200];
bool is_eliminator[200];

void solve()
{
	int N = get_int();

	double total = 0;
	FOR(i, N) {
		scores[i] = get_int();
		is_eliminator[i] = false;
		total += scores[i];
	}

	// find large score
	double max = 0;
	FOR(i, N) {
		if (max < scores[i]) max = scores[i];
	}

	// ‚½‚è‚È‚¢‚Ô‚Ž
	double total_diff = 0;
	int num_max = 0;
	FOR(i, N) {
		total_diff += max - scores[i];
		if (max == scores[i]) {
			++num_max;
			is_eliminator[i] = true;
		}
	}

	double eliminator = N;
	if (total_diff > total) eliminator -= num_max;

	double avr = 0;

	do {
		total_diff = 0;
		FOR(i, N) {
			if (is_eliminator[i] == false ) {
				total_diff += max - scores[i];
			}
		}

		// ‹Ï“™‚É‚í‚é‚Ô‚ñ
		avr = (total - total_diff) / eliminator;

		bool is_minus = false;
		FOR(i, N) {
			double ret = 0;
			ret = (max - scores[i] + avr) / total;
			if (ret < 0.0 && is_eliminator[i] == false) {
				is_minus = true;
				eliminator -= 1;
				is_eliminator[i] = true;
			}
		}
		// ok?
		if (is_minus == false) {
			break;
		}
	} while (true);

	FOR(i, N) {
		double ret = 0;
		ret = (max - scores[i] + avr) / total;
		if ( ret < 0.0 ) ret = 0.0;
		printf( "%.6lf ", ret * 100.0 );
	}

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
