#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int itc;

void solve() {
	int n;
	cin >> n;
	if (n == 0) {
		puts("INSOMNIA");
		return;
	}
	int M = 0;
	int i;
	for (i = 1; M != (1<<10)-1; i++) {
		for (int ni = n*i; ni != 0; ni /= 10) {
			M |= 1<<(ni%10);
		}
	}
	printf("%d\n", n*(i-1));
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d: ", itc);
		solve();
	}
}
