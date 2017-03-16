#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int n, v, res;
vector<int> b;



void go(int k, const vector<int> &a) {
	bool used[33];
	int d[33][73];
	forn(i, 33)memset(d[i], 0, sizeof d[i]);
	memset(used, 0, sizeof used);
	d[0][0] = 1;
	//forn(i, k) 
	//	cout << a[i] << ", ";
	//puts("");
	forn(i, k) {
		used[a[i]] = 1;
		forn(j, v + 1) {
			if (d[i][j]) {
				d[i + 1][j] = 1;
				d[i + 1][j + a[i]] = 1;
			}
		}
	}
	int ok = 1;
	forn(i, v + 1)
		if (!d[k][i]) {
			ok = 0;
			//printf("Error with k = %d, value = %d\n", k, i);
			break;
		}
	if (ok) {
		res = min(res, k);
		return;
	}
	vector<int> f(k + 1, 0);
	forn(i, k)
		f[i] = a[i];
	forn(i, v + 1) {
		if (i > 0 && !used[i]) {
			f[k] = i;
			if (res > k + 1)
				go(k + 1, f);
		}
	}
}

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		int c;
		cin >> c >> n >> v;
		b.resize(n);
		forn(i, n)
			cin >> b[i];

		res = 999999;
		go(n, b);
		printf("Case #%d: %d\n", ttt + 1, (res-n));
	}
}