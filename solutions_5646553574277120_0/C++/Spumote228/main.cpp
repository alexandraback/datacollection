#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fore(i, b, e) for (int i = (int)b; i <= (int)e; i++)
#define f first
#define s second
#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)
#define pb push_back
#define mp make_pair

const int maxN = 2000;

int a[maxN], b[maxN];

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> a[i];
		for (int i = 0; i <= v; i++)
			b[i] = 0;
		for (int i = 0; i < (1 << d); i++) {
			int x = 0;
			for (int j = 0; j < d; j++)
				if (((1 << j) & i) > 0)
					x += a[j];
			b[x] = 1;
		}
		int ans = 0;
		while (1) {
			int x = 0;
			for (int i = 1; i <= v; i++)
				if (b[i] == 0) {
					x = i;
					break;
				}
			if (x == 0)
				break;
			ans++;
			for (int i = v; i >= 0; i--)
				if (b[i] == 1)
					b[i + x] = 1;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}