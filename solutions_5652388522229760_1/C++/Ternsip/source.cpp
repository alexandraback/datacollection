#include <iostream>

using namespace std;

int main() {
	
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		long n;
		cin >> n;
		long ans = 0;
		for (int i = 1, a = 0; i < 1e4; ++i) {
			long number = n * i;
			while (number) {
				a |= 1 << (number % 10);
			    number = number / 10;
			}
			if (a == 1023) {
				ans = n * i;
				break;
			}
		}
		ans ? printf("Case #%d: %I64d\n", test, ans): printf("Case #%d: INSOMNIA\n", test);
	}
	
    return 0;
}