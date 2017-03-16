#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int getDigits(int n);

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", iC);
			continue;
		}

		int digits = 0;
		int i;
		for (i=1; ; i++) {
			digits |= getDigits(i*n); 
			if (digits == (1<<10)-1)
				break;
		}

		printf("Case #%d: %d\n", iC, i*n);
	}
	return 0;
}

int getDigits(int n) {
	int res = 0;
	while (n > 0) {
		int d = n % 10;
		res |= (1<<d);
		n /= 10;
	}
	return res;
}