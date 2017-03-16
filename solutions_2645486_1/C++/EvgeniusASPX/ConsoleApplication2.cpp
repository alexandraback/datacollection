#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
using namespace std;

 #pragma comment(linker, "/STACK:16777216")

const long long MOD = 1000000007;
const int MAX = 20000;
long long v[MAX];
long long ce[MAX];
long long saveby[MAX];
long long counter = 0;
long long E, R, n;

void solve(int s, int f)
{
	if (s == f)
	{
		//counter += ce[s] * v[s];
		return;
	}
	int c = s;
	for (int i = s; i < f; ++i)
		if (v[i] > v[c])
			c = i;
	
	long long m = c - s;
	long long restm = f - c;
	long long starte = ce[s];
	long long savebyf = saveby[f];
	long long maxeacc = min(starte + m * R, E);
	long long minesave = savebyf - restm * R;
	minesave = max(0LL, minesave);
	long long spendatc = min(maxeacc - minesave, E);
	if (spendatc < 0)
		throw 1;
	counter += spendatc * v[c];
	saveby[c] = maxeacc;
	ce[c+1] = min(minesave + R, E);
	solve(s, c);
	solve(c+1, f);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	cin >> tt;
					
	for (int t = 0; t < tt; ++t)
	{
		cin >> E  >> R >> n;
		counter = 0;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		ce[0] = E;
		saveby[n] = 0;
		solve(0, n);
	
		cout << "Case #" << t + 1 << ": " << counter << endl;
	}
	return 0;
}