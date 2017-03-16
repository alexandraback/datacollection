#include <iostream>
#include <fstream>

using namespace std;

int v[100];
int n;

int f(int a, int t, int c)
{
	if (t == n)
		return c;
	if (a > v[t])
		return f(a + v[t], t + 1, c);
	int d = 0, a2 = a;
	for ( ; a2 <= v[t] && a != 1; ++d)
		a2 = a2 * 2 - 1;
	int p = f(a, t + 1, c + 1), q = f(a2 + v[t], t + 1, c + d);
	if (a == 1)
		return p;
	else
		return min(p, q);
}

main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.txt");
	int a, tt;
	fin >> tt;
	for (int cnt = 1; cnt <= tt; ++cnt)
	{
		fin >> a >> n;
		for (int i = 0; i < n; ++i)
			fin >> v[i];
		sort(v, v + n);
		fout << "Case #" << cnt << ": " << f(a, 0, 0) << endl;
	}
}
