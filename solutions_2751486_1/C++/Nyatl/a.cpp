#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(i=a; i<=b; i++)
#define fj(a, b) for(j=a; j<=b; j++)
#define fo(a, b) for(o=a; o<=b; o++)
#define fdi(a, b) for(i=a; i>=b; i--)
#define fdj(a, b) for(j=a; j>=b; j--)
#define fdo(a, b) for(o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

#define MAX 1001000

int testq;
int test;

char str[MAX];
int n;
int k;

void Read() {
	scanf("%s %d", str + 1, &k);
}

bool IsVowel(char x) {
	if (x == 'a') return true;
	if (x == 'e') return true;
	if (x == 'i') return true;
	if (x == 'o') return true;
	if (x == 'u') return true;
	return false;
}

int d[MAX];
int s[MAX];

void Solve() {
	int i;
	int l, r, h;
	int64 ans;
	ZERO(d);
	ZERO(s);
	n = strlen(str + 1);
	ans = 0;
	fi(1, n) {
		if (!IsVowel(str[i])) {
			d[i] = d[i - 1] + 1;
		} else {
			d[i] = 0;
		}
	}
	fi(1, n) {
		s[i] = s[i - 1];
		if (d[i] >= k) {
			s[i]++;
		}
	}
	fi(1, n) {
		l = i + k - 1;
		r = n;
		if (i + k - 1 > n) continue;
		while (l < r) {
			h = (l + r) / 2;
			if (s[h] - s[i + k - 2] == 0) {
				l = h + 1;
			} else {
				r = h;
			}
		}
		if (s[l] - s[i + k - 2] != 0) {
			ans += n - l + 1;
		}
	}
	printf("%lld\n", ans);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%d: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}
