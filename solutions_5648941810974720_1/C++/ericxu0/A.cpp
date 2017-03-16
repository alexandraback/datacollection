#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int T, N;
string S;
int occ[500];
int cnt[10];

void go()
{
	for (int i = 0; i < N; i++)
		occ[S[i]]++;

	cnt[0] += occ['Z'];
	occ['E'] -= occ['Z'];
	occ['R'] -= occ['Z'];
	occ['O'] -= occ['Z'];
	occ['Z'] = 0;

	cnt[2] += occ['W'];
	occ['T'] -= occ['W'];
	occ['O'] -= occ['W'];
	occ['W'] = 0;

	cnt[4] += occ['U'];
	occ['F'] -= occ['U'];
	occ['O'] -= occ['U'];
	occ['R'] -= occ['U'];
	occ['U'] = 0;

	cnt[5] += occ['F'];
	occ['I'] -= occ['F'];
	occ['V'] -= occ['F'];
	occ['E'] -= occ['F'];
	occ['F'] = 0;

	cnt[6] += occ['X'];
	occ['S'] -= occ['X'];
	occ['I'] -= occ['X'];
	occ['X'] = 0;

	cnt[7] += occ['V'];
	occ['S'] -= occ['V'];
	occ['E'] -= 2*occ['V'];
	occ['N'] -= occ['V'];
	occ['V'] = 0;

	cnt[8] += occ['G'];
	occ['E'] -= occ['G'];
	occ['I'] -= occ['G'];
	occ['H'] -= occ['G'];
	occ['T'] -= occ['G'];
	occ['G'] = 0;

	cnt[3] += occ['R'];
	occ['T'] -= occ['R'];
	occ['H'] -= occ['R'];
	occ['E'] -= 2*occ['R'];
	occ['R'] = 0;

	cnt[1] += occ['O'];
	occ['N'] -= occ['O'];
	occ['E'] -= occ['O'];
	occ['O'] = 0;

	cnt[9] += occ['I'];
	occ['N'] -= 2*occ['I'];
	occ['E'] -= occ['I'];
	occ['I'] = 0;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> S;
		N = S.size();
		memset(occ, 0, sizeof(occ));
		memset(cnt, 0, sizeof(cnt));

		go();
		for (char c = 'A'; c <= 'Z'; c++)
			if (occ[c] != 0)
				cout << c << "\n";
		cout << "Case #" << t << ": ";
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << "\n";
	}

	return 0;
}