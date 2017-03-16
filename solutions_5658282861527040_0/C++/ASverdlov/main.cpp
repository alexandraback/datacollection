#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define db(v) cout << #v << " = " << (v) << endl;
typedef long long ll;

int T, n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int cnt = 0;
		int A, B, K; cin >> A >> B >> K;
		for (int a = 0; a < A; ++a)
		for (int b = 0; b < B; ++b)
		{
			if ((a & b) < K) ++cnt;
		}
		printf("Case #%d: %d\n", i + 1, cnt);
	}

	return 0;
}
