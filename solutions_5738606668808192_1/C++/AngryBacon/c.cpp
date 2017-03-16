#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

const int N = 16;
const int J = 50;
const int D[] = {0, 0, 3, 2, 5, 2, 7, 2, 9, 2, 11};

int tot;
int a[N];

int testMod(int b, int m)
{
	long long ret = 0;
	for(int i = 0; i < N; ++ i) {
		ret = (ret * b + a[i]) % m;
	}
	return ret == 0;
}

int go(int s1, int s2)
{
	memset(a, 0, sizeof a);
	a[0] = a[N - 1] = 1;
	for(int i = 0; i < N / 2 - 1; ++ i) {
		{
			int x = (s1 >> i & 1);
			a[i * 2 + 2] = x;
		}
		{
			int x = (s2 >> i & 1);
			a[i * 2 + 1] = x;
		}
	}
	for(int i = 2; i <= 10; ++ i) {
		assert(testMod(i, D[i]));
	}
	tot ++;
	for(int i = 0; i < N; ++ i) {
		cout << a[i];
	}
	for(int i = 2; i <= 10; ++ i) cout << ' ' << D[i];
	cout << endl;
}

void solve()
{
	tot = 0;
	for(int i = 0; tot < J && i < (1 << (N / 2 - 1)); ++ i) {
		for(int j = 0; tot < J && j < (1 << (N / 2 - 1)); ++ j) {
			if (__builtin_popcount(i) == __builtin_popcount(j)) {
				go(i, j);
			}
		}
	}
}

int main()
{
	puts("Case #1:");
	solve();
	return 0;
}
