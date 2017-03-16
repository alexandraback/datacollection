#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

vector<unsigned long long int> primes;

bool isprime(const unsigned long long int& x) {
	for (vector<unsigned long long int>::iterator it = primes.begin(); *it**it <= x; it++) {
		if (x%*it == 0)return false;
	}
	return true;
}

unsigned long long int update() {
	for (unsigned long long int x = primes.back() + 2;; x += 2) {
		if (isprime(x)) {
			primes.push_back(x);
			return x;
		}
	}
}

bool remaind(const int *a, const unsigned long long int& fact, const int& j, const int& N) {
	unsigned long long int remaind = 0;
	for (int i = N - 1; i >= 0; i--) {
		remaind = (remaind*j + a[i]) % fact;
	}
	if (remaind == 0)return true;
	return false;
}

int main() {
	FILE *fpi, *fpo;
	fpi = fopen("C-test.in", "r");
	fpo = fopen("testC2.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	primes.push_back(2);
	primes.push_back(3);
	for (int co = 1; co <= re; co++) {
		int N, J, i;
		fprintf(fpo, "Case #%d:\n", co);
		fscanf(fpi, "%d%d", &N, &J);
		unsigned int s = 32799;
		while (J) {
			unsigned long long int factor[9];
			int arr[32];
			unsigned int t = s;
			for (i = 0; i < N; i++) {
				arr[i] = t & 1;
				t >>= 1;
			}
			for (i = 2; i <= 10; i++) {
				unsigned int max = 1000;
				bool flag = false;
				unsigned long long int fact;
				vector<unsigned long long int>::iterator it = primes.begin();
				do {
					if (it == primes.end()) {
						fact = update();
						it = primes.end() - 1;
					}
					else
						fact = *it;
					if (remaind(arr, fact, i, N)) {
						flag = true;
						factor[i - 2] = fact;
						break;
					}
					it++;
				} while (fact < max);
				if (!flag) {
					break;
				}
			}
			if (i == 11) {
				for (i = N - 1; i >= 0; i--) {
					fprintf(fpo, "%d", arr[i]);
				}
				for (i = 0; i < 9; i++) {
					fprintf(fpo, " %lld", factor[i]);
				}
				fprintf(fpo, "\n");
				J--;
				
			}
			s += 24;
		}

	}
	fclose(fpi);
	fclose(fpo);
}