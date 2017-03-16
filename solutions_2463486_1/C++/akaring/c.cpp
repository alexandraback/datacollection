#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

vector<long long> lv;

inline bool isPar(long long n) {
	string s = to_string(n);
	string t = s;
	reverse(ALL(t));
	return s == t;
}

long long gao(long long N) {
	return upper_bound(ALL(lv), N) - lv.begin();
}

int main() {
	for (long long i = 1, j; i < 10000; ++i) {
		string s = to_string(i);
		string t = s;
		reverse(ALL(t));
		j = stoll(s + t);
		if (isPar(j * j)) {
//			printf("%lld => %lld\n", j, j * j);
			lv.push_back(j * j);
		}
		s.pop_back();
		j = stoll(s + t);
		if (isPar(j * j)) {
//			printf("%lld => %lld\n", j, j * j);
			lv.push_back(j * j);
		}
	}
	sort(ALL(lv));

	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		long long A, B;
		scanf("%lld%lld", &A, &B);
		printf("Case #%d: %lld\n", index, gao(B) - gao(A - 1));
	}
	return 0;
}
