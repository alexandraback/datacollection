#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

#define LIM 14
#define PLIM 100000000000000ULL

using namespace std;

int main() {
	stack<pair<unsigned long long, int> > s;
	vector<unsigned long long> palindromes;
	palindromes.reserve(20000000);
	vector<unsigned long long> sqpalin;
	unsigned long long powers[] = {1ULL,
				       10ULL,
				       100ULL,
				       1000ULL,
				       10000ULL,
				       100000ULL,
				       1000000ULL,
				       10000000ULL,
				       100000000ULL,
				       1000000000ULL,
				       10000000000ULL,
				       100000000000ULL,
				       1000000000000ULL,
				       10000000000000ULL,
				       100000000000000ULL};
	
	s.push(make_pair(0, 0));
	
	for (int i = 0; i < 10; i++) {
		s.push(make_pair(i, 1));
	}
	
	while (!s.empty()) {
		pair<unsigned long long, int> x = s.top();
		s.pop();
	
		if (x.first % 10 != 0) {	
			palindromes.push_back(x.first);
		}
		
		if (x.second + 2 > LIM) continue;
		
		for (int i = 0; i < 10; i++) {
			s.push(make_pair(powers[x.second + 1] * i + x.first * 10 + i, x.second + 2));
		}
	}
	
	sort(palindromes.begin(), palindromes.end());
	
	for (int i = 0; i < palindromes.size() && PLIM / palindromes[i] >= palindromes[i]; ++i) {
		unsigned long long x = palindromes[i] * palindromes[i];
		
		if (*lower_bound(palindromes.begin(), palindromes.end(), x) == x) {
			sqpalin.push_back(x);
		}
	}
	
	int T;
	unsigned long long A, B;
	
	scanf("%d\n", &T);
	
	for (int nCase = 1; nCase <= T; nCase++) {
		scanf("%llu %llu\n", &A, &B);
		
		printf("Case #%d: %d\n", nCase, lower_bound(sqpalin.begin(), sqpalin.end(), B+1) - lower_bound(sqpalin.begin(), sqpalin.end(), A));
	}
}

