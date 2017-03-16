#include <cstdio>

using namespace std;

bool IsPowerOfTwo(long long x)
{
	    return (x & (x - 1LL)) == 0LL;
}

long long gcd(long long p, long long q) {
	if(q == 0)
		return p;
	return gcd(q, p % q);
}

int main() {
	int T, z = 0;
	scanf(" %d", &T);
	while(T --) {
		z ++;
		long long p, q;
		scanf(" %lld/%lld", &p, &q);
		long long g = gcd(p, q);
		p = p / g;
		q = q / g;
		if(IsPowerOfTwo(q)) {
			while(q != (1LL << 40)) {
				q = q << 1;
				p = p << 1;
			}
			int gen = 0;
			while(p != 0) {
				gen ++;
				p = p >> 1;
			}
			printf("Case #%d: %d\n", z, 41 - gen);
		}
		else {
			printf("Case #%d: impossible\n", z);
		}
	}
	return 0;
}
