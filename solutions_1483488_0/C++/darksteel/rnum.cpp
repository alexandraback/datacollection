#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int i, j, T;
	cin >> T;
	for(i = 1; i <= T; i++) {
		int A, B;
		int ans = 0;
		cin >> A >> B;
		for(j = A; j <= B; j++) {
			int n = j;
			int b = 1;
			while(n >= 10) {
				n /= 10;
				b *= 10;
			}
			n = j;
			while(true) {
				n = (n%10) * b + n/10;
				if(n == j) break;
				if(n >= A && n <= B) ans++;
			}
		}
		printf("Case #%d: %d\n", i, ans/2);
	}
	return 0;
}
