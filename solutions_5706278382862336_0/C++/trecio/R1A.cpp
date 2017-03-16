#include <cstdio>
#include <string>
#include <sstream>
#include <utility>
using namespace std;

int log2(long long x) {
	int res = 0;
	while (x % 2 == 0) {
		x/=2;
		res++;
	}
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		
		int lb = log2(b);
		long long one = 1;
		long long nb = one << lb;
		long long c = b / nb;

		string res;
		if ((a % c) != 0) {
			res = "impossible";
		} else {
			long long na = a / c;
			int pb = 2;
			int r = 1;
			while (na < nb / pb) {
				pb *= 2;
				r++;
			}
			stringstream ss;
			ss << r;
			ss >> res;
		}

		printf("Case #%d: %s\n", t, res.data());
	}
	return 0;
}