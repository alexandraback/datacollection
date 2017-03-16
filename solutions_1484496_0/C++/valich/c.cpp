#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define maxn 21

int T;
int n;
int a[maxn];

void out(int mask) {
	int f = 0;
	for (int i = 0; i < n; i++) {
		if ((mask >> i) & 1) {
			if (f) putchar(' ');
			f = 1;
			printf("%d", a[i]);
		}
	}
	puts("");
}


int main() {
	scanf("%d", &T);
	for (int q = 1; q <= T; q++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		printf("Case #%d:\n", q);

		int f = 0;
		for (int mask = 0; !f && mask < 1 << n; mask++) {
			for (int smask = mask - 1; !f && smask > 0; smask = (smask - 1) & mask) {
				int dmask = mask ^ smask;
				int s1 = 0, s2 = 0;
				for (int i = 0; i < n; i++) {
					if ((dmask >> i) & 1) s1 += a[i];
					if ((smask >> i) & 1) s2 += a[i];
				}
				if (s1 == s2) {
					f = 1;
					out(dmask);
					out(smask);
					break;
				}
			}			
		}
		if (!f) {
			puts("Impossible");
		}

	}
  

  return 0;
}
