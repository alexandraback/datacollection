#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


string solve(int R, int C, int M)
{
	int 			a, b, ra, rb;
	int 			F = R*C - M;
	bool			haveSolution = false;
	string 			board(R*C, '*');
	ostringstream	out;

	if (R == 1)
	{
		haveSolution = true;
		a 	= 1;
		b 	= F;
		ra 	= rb = 0;
	}

	if (C == 1)
	{
		haveSolution = true;
		a 	= F;
		b 	= 1;
		ra 	= rb = 0;
	}

	if (F == 1)
	{
		haveSolution = true;
		a 	= b = 1;
		ra 	= rb = 0;
	}

	for (int p = 2; p <= R; p++)
	{
		for (int q = 2; q <= C; q++)
		{
			if (p*q == F)
			{
				haveSolution = true;
				a 	= p;
				b 	= q;
				ra 	= rb = 0;
			}
			else if ( (p*q > F) && (p > 2) && (q > 2) )
			{
				int rp = (p - 2);
				int rq = (q - 2);
				int r  = ( (rp != 0) && (rq != 0) ) ? rp + rq - 1 : rp + rq;

				if (F >= p*q - r)
				{
					haveSolution = true;
					a 	= p;
					b 	= q;
					ra 	= min((p*q - F), rp);
					rb  = min((p*q - F - ra), rq) + ((ra != 0) ? 1 : 0);
				}
			}
		}
	}

	if (!haveSolution) return string("Impossible\n");

	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			board[i*C + j] = '.';

	for (int i = 0; i < ra; i++)
		board[(a - 1)*C + b - 1 - i*C] = '*';

	for (int j = 0; j < rb; j++)
		board[(a - 1)*C + b - 1 - j] = '*';

	board[0] = 'c';

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			out << board[i*C + j];
		}
		out << "\n";
	}

	return string(out. str());
}


int main()
{
	fstream 		f, g;
	int 			T, R, C, M;

	f.open("in.txt", ios::in);
	g.open("out.txt", ios::out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> R >> C >> M;
		g << "Case #" << test << ":\n" << solve(R, C, M);
	}

	f.close();
	g.close();

	return 0;
}

