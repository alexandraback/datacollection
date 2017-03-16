#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define intl long long
using namespace std;

int A[20],n,T;

intl solve(intl u) {
	memset(A,0,sizeof(A)); int res = 10;
	intl v = 0;
	while (res) {
		v++;
		int k = u * v;
		for (; k; k /= 10LL) {
			if (++A[k % 10LL] == 1) res--;
		}				
	}
	return u * v;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	for (scanf("%d",&T), t = 1; t <= T; t++) {
		scanf("%d",&n);
		printf("Case #%d: ",t);
		if (n == 0) printf("INSOMNIA\n");
		else cout << solve(n) << endl;
	}
	return 0;
}
