#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

enum Quat
{
	ONE   = 0,
	NONE  = 1,
	I     = 2,
	NI    = 3,
	J     = 4,
	NJ    = 5,
	K     = 6,
	NK    =7
};

Quat INV_TABLE[8] = { ONE, NONE, NI, I, NJ, J, NK, K };
Quat MUL_TABLE[8][8] = 
{
	{ ONE, NONE, I, NI, J, NJ, K, NK }, // ONE * x
	{ NONE, ONE, NI, I, NJ, J, NK, K }, // NONE * x
	{ I, NI, NONE, ONE, K, NK, NJ, J }, // I * x
	{ NI, I, ONE, NONE, NK, K, J, NJ }, // NI * x
	{ J, NJ, NK, K, NONE, ONE, I, NI},  // J * x
	{ NJ, J, K, NK, ONE, NONE, NI, I }, // NJ * x
	{ K, NK, J, NJ, NI, I, NONE, ONE},
	{ NK, K, NJ, J, I, NI, ONE, NONE },
};

typedef long long ll;
const int PERIOD = 4;

Quat power(Quat A, ll N)
{
	N %= PERIOD;
	Quat R = ONE;
	for (int i = 0; i < N; i++)
	{
		R = MUL_TABLE[R][A];
	}
	return R;
}

Quat parse(char c)
{
	switch (c)
	{
	case 'i':
		return I;
	case 'j':
		return J;
	case 'k':
		return K;
	default:
		assert(false);
		return ONE;
	}
}

int L;
ll X;
const int MAX = 10000 + 100 + 9;
string s;
Quat ss[MAX];
Quat pref[MAX];
Quat suff[MAX];
Quat A;
bool possible[8][MAX];
bool possible_right[8];

bool ok(int l1, int l2)
{
	return (l1 + l2) % PERIOD == (X - 1) % PERIOD && (l1 + l2) <= X - 1;
}

bool ok(int l1, int l2, int l3)
{
	return (l1 + l2 + l3) % PERIOD == (X - 2) % PERIOD && (l1 + l2 + l3) <= X - 2;
}

void calc()
{
	for (int i = 0; i < L; i++) ss[i + 1] = parse(s[i]);
	pref[0] = ONE;
	for (int i = 1; i <= L; i++) pref[i] = MUL_TABLE[pref[i - 1]][ss[i]];

	suff[L + 1] = ONE;
	for (int i = L; i >= 1; i--) suff[i] = MUL_TABLE[ss[i]][suff[i + 1]];

	A = pref[L];
	assert(A == suff[1]);

	for (int q = 0; q < 8; q++)  possible[q][L + 2] = false;
	for (int i = L + 1; i >= 1; i--)
	{
		for (int q = 0; q < 8; q++)
		{
			possible[q][i] = possible[q][i + 1] || (suff[i] == q);
		}
	}

	for (int q = 0; q < 8; q++) possible_right[q] = false;
	for (int i = 0; i <= L; i++)
	{
		Quat curr = pref[i];
		possible_right[curr] = true;
	}
}

bool solve_1()
{
	for (int i = 0; i <= L; i++)
	{
		Quat pr = pref[i];
		for (int ssu = 0; ssu < 8; ssu++)
		{
			Quat su = (Quat)ssu;
			if (!possible[su][i + 1]) continue;

			for (int l1 = 0; l1 < PERIOD; l1++)
			{
				for (int l2 = 0; l2 < PERIOD; l2++)
				{
					if (!ok(l1, l2)) continue;
					Quat Left = MUL_TABLE[power(A, l1)][pr];
					
					Quat Mid = MUL_TABLE[INV_TABLE[pr]][A];
					Mid = MUL_TABLE[Mid][INV_TABLE[su]];

					Quat Right = MUL_TABLE[su][power(A, l2)];

					if (Left == I && Mid == J && Right == K) return true;
				}
			}
		}
	}

	return false;
}

bool solve_2()
{
	for (int i = 0; i <= L; i++)
	{
		for (int ppr = 0; ppr < 8; ppr++)
		{
			Quat pr = (Quat)ppr;
			if (!possible_right[pr]) continue;

			for (int ssu = 0; ssu < 8; ssu++)
			{
				Quat su = (Quat)ssu;
				if (!possible[su][1]) continue;

				for (int l1 = 0; l1 < PERIOD; l1++)
				{
					for (int l2 = 0; l2 < PERIOD; l2++)
					{
						for (int l3 = 0; l3 < PERIOD; l3++)
						{
							if (!ok(l1, l2, l3)) continue;
							Quat Left = MUL_TABLE[power(A, l1)][pr];

							Quat Mid = MUL_TABLE[INV_TABLE[pr]][power(A, l2 + 2)];
							Mid = MUL_TABLE[Mid][INV_TABLE[su]];

							Quat Right = MUL_TABLE[su][power(A, l3)];

							if (Left == I && Mid == J && Right == K) return true;
						}
					}
				}
			}
		}
	}

	return false;
}


bool solve_case()
{
	calc();

	return solve_1() || solve_2();
}

void solve()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int i = 1; i <= T; i++)
	{
		in >> L >> X;
		assert(L + 100 < MAX);
		in >> s;

		string temp = solve_case() ? "YES" : "NO";
		out << "Case #" << i << ": " << temp << "\n";
	
		cout << "SOLVED CASE# :" << i << endl;
	}

	in.close();
	out.close();
}


int main()
{
	solve();
	return 0;
}