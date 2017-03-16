#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <ctime>

using namespace std;

const int maxN = 40;
int digits[maxN];
int n;

bool isGood(int base, int modulo) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = res * base + digits[i];
		res = res % modulo;
	}
	return res == 0;
}

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

const int maxP = 1000000;
int primes[maxP], p;

void solve(int test) {
	p = 0;
	for (int i = 2; i <= 1000; ++i) {
		if (isPrime(i)) {
			primes[p++] = i;
		}
	}
	int m;
	cin >> n >> m;
	printf("Case #1:\n");
	digits[0] = digits[n - 1] = 1;
	for (int i = 0; i < (1 << (n - 2)) && m > 0; ++i) {
		int j = i;
		int l = 1;
		for (int k = 0; k < (n - 2); ++k) {
			digits[l++] = j % 2;
			j /= 2;
		}
		vector < int > score;
		for (int base = 2; base <= 10; ++base) {
			int good = -1;
			for (int index = 0; index < p && good == -1; ++index) {
				if (isGood(base, primes[index])) {
					good = primes[index];
				}
			}
			if (good == -1) {
				break;
			}
			score.push_back(good);
		}
		if (score.size() == 9) {
			for (int j = 0; j < n; ++j) {
				printf("%d", digits[j]);
			}
			for (int j = 0; j < score.size(); ++j) {
				printf(" %d", score[j]);
			}
			printf("\n");
			--m;
			cerr << m << endl;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
		cerr << i + 1 << ": " << clock() << endl;
	}
	return 0;
}