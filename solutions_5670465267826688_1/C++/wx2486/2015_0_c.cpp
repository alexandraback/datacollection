#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int mult(int a, int b)
{
	int sig = a*b;
	sig /= abs(sig);
	static const int mult_tab[5][5] = {
		{  0,  0,  0,  0,  0},
		{  0,  1,  2,  3,  4},
		{  0,  2, -1,  4, -3},
		{  0,  3, -4, -1,  2},
		{  0,  4,  3, -2, -1},
	};
	return sig * mult_tab[abs(a)][abs(b)];
}

bool solve(string &s, int n)
{
	int tgt[3] = {2, 3, 4};
	int state = 1;
	int p = 0;
	for (int i=0; i<s.length()*n; i++)
	{
		state = mult(state, s[i%s.length()] - 'i' + 2);
		if (p < 3 && state == tgt[p])
		{
			state = 1;
			p++;
		}
	}
	if (p >= 3 && state == 1)
		return true;
	return false;
}

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int len;
		long long n;
		string s;
		cin >> len >> n >> s;
		if (n > 20)
			n = n % 20 + 20;
		cout << "Case #" << cc << ": ";
		if (solve(s, (int)n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
