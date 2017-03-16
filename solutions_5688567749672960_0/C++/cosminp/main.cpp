#include <fstream>
using namespace std;

typedef long long 	int64;


int64 getDigitCount(int64 N)
{
	return (N == 0) ? 0 : (1 + getDigitCount(N / 10));
}

int64 getFirst(int64 N, int64 k)
{
	int64 len = getDigitCount(N);
	for (int64 i = 0; i < len - k; N /= 10, i++);
	return N;
}

int64 getLast(int64 N, int64 k)
{
	return (k == 0) ? 0 :(getLast(N/10, k - 1)*10 + (N%10));
}

int64 reverse(int64 N)
{
	int64 x = 0;
	while (N)
	{
		x 	= x*10 + (N%10);
		N  /= 10;
	}
	return x;
}


int64 solve(int64 N)
{
	int64 	nines 	= 0;
	int64	c 		= 1;
	int64 	digits  = 0;
	int64 	best;

	while (10*nines + 9 <= N)
	{
		digits++;
		nines 	= 10*nines + 9;
		c 	   += getLast(nines, digits - digits/2) - 1;
		c 	   += (digits > 1) ? getFirst(nines, digits/2) - 1 : 0;
		c 	   += (digits > 1) ? 1 : 0;

		if (N == nines) return c;
		c++;

		if (N == nines + 1)	return c;
		c++;
	}

	if ((N % 10) == 0)
	{
		N--;
		c++;
	}

	digits 	= getDigitCount(N);
	best 	= N - ((nines == 0) ? 1 : (nines + 2));
	for (int64 i = 1; i < digits; i++)
	{
		int64  x 	= getFirst(N, i);
		int64  y 	= getLast(N, digits - i);
		int64  cost = reverse(x) + y - 1;

		if (cost < best) best = cost;
	}

	return c + best;
}


int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T;
	int64 		N;

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> N;
		g << "Case #" << test << ": " << solve(N) << endl;
	}

	return 0;
}
