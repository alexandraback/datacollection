#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
using namespace std;

#define INS insert
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define MEM(p, v) memset(p, v, sizeof(p))
#define SCD(i) scanf("%d", &(i))

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1000000007;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int ceil(int a, int b) { return (a + b - 1)/b; }

bool eq(vector<char> v1, vector<char> v2) {
	int sz;
	if ((sz = v1.size()) != v2.size())
		return false;

	FOR (i, 0, sz) {
		if (v1[i] != v2[i])
			return false;
	} return true;
}

int main(void) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-out.txt", "w", stdout);

	int T;
	SCD(T);
	
	for (int t = 1; t <= T; t++) {
		int a, b, k;
		SCD(a); SCD(b); SCD(k);

		int count = 0;
		FOR (i, 0, a) {
			FOR (j, 0, b) {
				if ((i & j) < k)
					count++;
			}
		}

		printf("Case #%d: %d\n", t, count);
	}

	return 0;
}
