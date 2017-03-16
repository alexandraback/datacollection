#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*long long comb(long long n, long long k) {
	long long res = 1;
	if (2*k > n)
		k = n-k;

	for (int i=1; i<=k; i++)
		res = res*(n+1-i)/i;
	return res;
}*/

double comb (int n, int k) {
	int i;
	double p=1;
	for (i=0;i<k;i++){
		p*=(n-i);
		p/=(i+1);
	}
	return p;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, x, y;
		double res;
		scanf("%d %d %d", &n, &x, &y);
		if (x < 0)
			x = -x;

		int pile = 0;
		int layer = 0;

		while (pile <= n) {
			pile += 4*layer + 1;
			layer++;
		}
		layer --;
		pile -= 4*layer + 1;

		int remain = n - pile;
		int place_layer = (x+y)/2;

		//printf("%d %d %d\n", remain, layer, place_layer);

		if (place_layer < layer) {
			res = 1;
		}
		else if (place_layer > layer or (x+y)%2 == 1) {
			res = 0;
		}
		else {
			double good=0, all=0;
			for (int i=0; i<=2*layer; i++) {
				if (i > remain or i+2*layer < remain)
					continue;

				if (i>y)
					good += comb(remain, i);
			}
			all = pow(2,n);
			//printf("%I64d %I64d\n", good, all);

			res = double(good)/all;
		}

		printf("Case #%d: %.6lf\n", iC, res);
	}
	return 0;
}
