#include<stdio.h>
#include<algorithm>

using namespace std;

bool ispal(long long x) {
	int a[100];
	int i=0;
	while(x) {
		a[i] = x%10;
		x /= 10;
		i++;
	}
	for(int j=0; j<i; j++) {
		if(a[j] != a[i-j-1]) return false;
	}
	return true;
}

long long a[10000];
int n = 0;

int ntest;
long long A, B;

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("CS1.out", "w", stdout);

	for(long long x=1; x*x<=100000000000000; x++) {
		if(ispal(x) && ispal(x*x)) a[n++] = x*x;
	}

	// for(int i=0; i<n; i++) printf("%lld\n", a[i]);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%lld%lld", &A, &B);
		printf("Case #%d: %d\n", test, upper_bound(a, a+n, B) - lower_bound(a, a+n, A));
	}

	return 0;
}