#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int primes = 5;
int prime[primes] = { 2, 3, 5, 7, 11 };
const int bases = 9;
int base[bases] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

void solve()
{
	static int casenr = 1;
	printf("Case #%d:\n", casenr++);
	
	int N, J; scanf("%d%d", &N, &J);
	char fmt[10]; sprintf(fmt, "1%%0%dlld", N-1);
	
	vector<vector<int> > basemod(bases, vector<int>(primes, 1));
	// Add 1<<(N-1)
	for (int i = 0; i < bases; ++i) {
		for (int j = 0; j < primes; ++j) {
			for (int k = 1; k < N; ++k) {
				basemod[i][j] *= base[i];
				basemod[i][j] %= prime[j];
			}
		}
	}
	// Add the 1
	for (int i = 0; i < bases; ++i) {
		for (int j = 0; j < primes; ++j) {
			basemod[i][j] += 1;
			basemod[i][j] %= prime[j];
		}
	}
	
	vector<long long> current(bases, 1);
	
	while (true)
	{
		// Check
		vector<int> ps;
		for (int i = 0; i < bases; ++i) {
			for (int j = 0; j < primes; ++j) {
				if (basemod[i][j] == 0) {
					ps.push_back(prime[j]);
					break;
				}
			}
			if (ps.size() <= i) {
				break;
			}
		}
		if (ps.size() == bases) {
			// Print
			printf(fmt, current[bases-1]);
			
			for (int i = 0; i < bases; ++i) {
				printf(" %d", ps[i]);
			}
			puts("");
			
			if (--J <= 0) { break; }
		}
		// Add stuff
		for (int i = 0; i < bases; ++i) {
			long long add = 2LL;
			if (i > 0) {
				long long b = 1LL;
				long long x = 0LL;
				long long v = current[0];
				while (v > 0LL) {
					x += b * (v & 1LL);
					v /= 2LL;
					b *= base[i];
				}
				add = x - current[i];
			}
			for (int j = 0; j < primes; ++j) {
				basemod[i][j] += add;
				basemod[i][j] %= prime[j];
			}
			current[i] += add;
		}
		//printf("\n%10d", current[bases-1]);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
