#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

int main() {
	int n, T, temp, freq[2505];

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%d", &n);

		memset(freq, 0, sizeof(freq));

		REP(i, 2 * n - 1) {
			REP(j, n) {
				scanf("%d", &temp);

				++freq[temp];
			}
		}

		printf("Case #%d:", tc);

		FORU(i, 1, 2500) {
			if (freq[i] & 1) {
				printf(" %d", i);
			}
		}

		printf("\n");
	}

	return 0;
}
