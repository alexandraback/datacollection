#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	if (a>b) swap(a,b);
	long long m = b%a;
	if (m==0) return a;
	return gcd(m,a);
}

int main() {
  int T, X;
  cin >> T;
  for (int t=1;t<=T;t++) {
		long long P, Q, m;
		scanf("%lld/%lld",&P,&Q);
		m = gcd(P,Q);
		P/=m;
		Q/=m;

		bool possible = true;
		int gen = 0;
		while (Q) {
			if (Q==1) {
				break;
			}
			else if (Q%2==1) {
				possible = false;
				break;
			}
			else {
				Q/=2;
				P/=2;
				if (P==0) gen++;
			}
		}
		
		//printf("Case #%d: %lld\n", t, gcd(P,Q));
		printf("Case #%d: ", t);
		if (!possible) printf("impossible\n");
		else {
			printf("%d\n", gen);
		}
	}

  return 0;
}
