#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 20;

int n;
int st[size];
bool flag;
int used[size];

void rec(int s1, int s2, int ps)
{
	if (flag)
		return;
	if (s1 == s2 && s1 > 0)
	{
		flag = true;
		for (int i = 0; i < n; i++)
			if (used[i] == 1)
				cout << st[i] << ' ';
		cout << endl;
		for (int i = 0; i < n; i++)
			if (used[i] == 2)
				cout << st[i] << ' ';
		cout << endl;
		return;
	}
	if (ps == n)
		return;
	rec(s1, s2, ps + 1);
	used[ps] = 1;
	rec(s1 + st[ps], s2, ps + 1);
	used[ps] = 2;
	rec(s1, s2 + st[ps], ps + 1);
	used[ps] = 0;
}

int main() {
	int tc;

	freopen("problem_c.in", "r", stdin);
	freopen("problem_c.out", "w", stdout);
	
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> st[i];
		cout << "Case #" << t + 1 << ":" << endl;
		flag = false;
		rec(0, 0, 0);
		if (!flag)
			cout << "Impossible" << endl;
	}

	return 0;
}