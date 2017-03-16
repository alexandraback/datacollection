#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

typedef long long ll;

using namespace std;

int cc[] = {1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};

int promote(int i, int j, int z)
{
	if(i < cc[j]) return i;
	int a = i / cc[j];
	int b = i % cc[j];

	return b * cc[z - j - 1] + a;
}

void solve()
{
	int a, b;
	ll cnt = 0LL;
	cin >> a >> b;
	int z = 0;

	int checked[10];

	for(int i = a; i < b; ++i) {
		while(i >= cc[z]) ++ z;
		int chkcnt = 0;

		for(int j = 0; j < 9; ++j) {
			if(i < cc[j]) break;

			int newi = promote(i, j, z);
			if(newi > i && newi <= b) {
				bool flag = true;
				REP(k, chkcnt) {
					if(checked[k] == newi) {
						flag = false;
						break;
					}
				}
				if(flag) {
					checked[chkcnt++] = newi;

					//cout << i << " " << newi << endl;
					++cnt;
				}
			}
		}
	}
	cout << cnt << endl;
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

