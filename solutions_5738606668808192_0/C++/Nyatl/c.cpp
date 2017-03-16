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
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int number_of_tests;
int test_number;

int n, j;

void read() {
	scanf("%d %d", &n, &j);
}

long long mod(string s, long long divisor, int base) {
	long long res = 0;
	fi(0, LEN(s) - 1) {
		res = res * base + s[i] - '0';
		res %= divisor;
	}
	return res;
}

set <string> u;

vector <int> primes;

void solve() {
	printf("\n");
	fi(1, j) {
		vector <int> ans;
		string s;
		do {
			do {
				s.clear();
				s += '1';
				fj(1, n - 2) {
					s += rand() % 2 + '0';
				}
				s += '1';
			} while (u.find(s) != u.end());
			u.insert(s);

			ans.clear();

			fi(2, 10) {
				fj(0, SIZE(primes) - 1) {
					if (mod(s, primes[j], i) == 0) {
						ans.pb(primes[j]);
						break;
					}
				}
			}
		} while (SIZE(ans) != 9);
		printf("%s ", s.c_str());
		fi(0, SIZE(ans) - 1) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}

void init() {
	fi(2, 30000) {
		int f = 1;
		fj(2, i - 1) {
			if (i % j == 0) {
				f = 0;
				break;
			}
		}
		if (f) {
			primes.pb(i);
		}
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &number_of_tests);
	init();
	for (test_number = 1; test_number <= number_of_tests; test_number++) {
		read();
		printf("Case #%d: ", test_number);
		solve();
		fflush(stdout);
	}
	return 0;
}
