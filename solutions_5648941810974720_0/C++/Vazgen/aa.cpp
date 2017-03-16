#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
const int N = (int)1e5 + 5, INF = (int)1e9;
const ld EPS = 1e-9;

int a[N], b[20];

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	cin >> T;
	for(int z = 1; z <= T; z++){
		string s;
		for(int i = 0; i < 200; i++)
			a[i] = 0;
		for(int i = 0; i < 15; i++)
			b[i] = 0;
		cin >> s;
		for(int i = 0; i < (int)s.size(); i++)
			a[s[i]]++;
		cout << "Case #" << z << ": ";
		b[0] = a['Z'];
		a['Z'] -= b[0]; a['E'] -= b[0]; a['R'] -= b[0]; a['O'] -= b[0];
		b[2] = a['W'];
		a['T'] -= b[2]; a['W'] -= b[2]; a['O'] -= b[2];
		b[4] = a['U'];
		a['F'] -= b[4]; a['O'] -= b[4]; a['U'] -= b[4]; a['R'] -= b[4];
		b[6] = a['X'];
		a['S'] -= b[6]; a['I'] -= b[6]; a['X'] -= b[6];
		b[8] = a['G'];
		a['E'] -= b[8]; a['I'] -= b[8]; a['G'] -= b[8]; a['H'] -= b[8]; a['T'] -= b[8];
		b[5] = a['F'];
		a['F'] -= b[5]; a['I'] -= b[5]; a['V'] -= b[5]; a['E'] -= b[5];
		b[7] = a['V'];
		a['S'] -= b[7]; a['V'] -= b[7]; a['N'] -= b[7]; a['E'] -= 2 * b[7];
		b[3] = a['H'];
		a['T'] -= b[3]; a['H'] -= b[3]; a['R'] -= b[3]; a['E'] -= 2 * b[3];
		b[1] = a['O'];
		a['O'] -= b[1]; a['N'] -= b[1]; a['E'] -= b[1];
		b[9] = a['I'];
		for(int i = 0; i < 10; i++)
			for(int k = 0; k < b[i]; k++)
				cout << i;
		cout << "\n";
	}
	return 0;
}