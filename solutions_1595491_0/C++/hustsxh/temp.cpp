#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 101

using namespace std;

int score[N], f[N][N];

bool getscore(int score, int &a, bool surprising)
{
	a = score / 3;
	switch(score % 3) {
	case 0:
		if(!surprising) {
			return true;
		}
		if(a == 10 || a == 0) {
			return false;
		}
		a = a + 1;
		return true;
	case 1:
		if(!surprising) {
			a = a + 1;
			return true;
		}
		if(a == 0) {
			return false;
		}
		a = a + 1;
		return true;
	case 2:
		if(!surprising) {
			a = a + 1;
		} else {
			a = a + 2;
		}
		return true;
	}
}

int main() 
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for(int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		int n, s, p;
		cin >> n >> s >> p;
		for(int i = 1; i <= n; ++i) {
			cin >> score[i];
		}
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i) {
			int supa, a;
			getscore(score[i], a, false);
			for(int j = 0; j <= s; ++j) {
				f[i][j] = f[i - 1][j] + (a >= p);
			}
			if(getscore(score[i], supa, true)) {
				for(int j = 1; j <= s; ++j) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + (supa >= p));
				}
			}
		}
		cout << f[n][s] << endl;
	}
	return 0;
}
