#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cases;
long long A, B, C;
int va[40], vb[40], vc[40];


void convert(long long A, int *va, long long posi) {
	for (long long ii = 31; ii >= 0; --ii)
		if (ii > posi) va[ii] = (A >> ii) & 1LL;
		else if (ii == posi) va[ii] = 0;
		else va[ii] = 2;
}


long long check(int a, int b, int c) {
	if (c == 0) {
		if (a == 0) {
			if (b < 2) return 1;
			else return 2;
		}
		else if (a == 1) {
			if (b != 1) return 1;
			else return 0;
		}
		else if (a == 2) {
			if (b == 0) return 2;
			else if (b == 1) return 1;
			else if (b == 2) return 3;
		}
	}
	else if (c == 1) {
		if (a == 0 || b == 0) {
			return 0;
		}
		else return 1;
	}
	else { //c==2
		int tmp = 1;
		if (a == 2) tmp *= 2;
		if (b == 2) tmp *= 2;
		return tmp;
	}
	return 0;
}

int main() {

	scanf("%d", &cases);
	
	for (int casei = 1; casei <= cases; ++casei) {
		scanf("%lld%lld%lld", &A, &B, &C);
		long long ans = 0;
		for (long long i = 31; i >= 0; --i) if ((1LL << i) & A) {
			convert(A, va, i);
			
			for (long long j = 31; j >= 0; --j) if ((1LL << j) & B) {
				convert(B, vb, j);
				
				for (long long k = 31; k >= 0; --k) if ((1LL << k) & C) {
					convert(C, vc, k);
					
					long long tmp = 1;
					for (int t = 31; t >= 0; --t) {
						tmp *= check(va[t], vb[t], vc[t]);
					}
					ans += tmp;
				}
			}
		}
		
		printf("Case #%d: %lld\n", casei, ans);
	}
	
	return 0;
}