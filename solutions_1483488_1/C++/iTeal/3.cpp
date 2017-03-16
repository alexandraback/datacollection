#include <iostream>
#include <cmath>

#define MIN(a,b) (a)<(b)?(a):(b)

using namespace std;

int cal(int x) {
	int k = log10(x);
	int p = pow(10.0, (double)k);
	return p;
}

int check(int x, int max) {
	int b = cal(x);
	int t = 0;
	int p = x;
	int num = 0;
	int arr[10];
	int ans = 0;
	do {
		t = p % 10;
		p = p / 10;
		int c = b * t + p;
		// b /= 10;
		p = c;
		if (c > x && c <= max) {
			bool flag = true;
			for(int i = 0; i < num; i++) {
				if (c == arr[i]) flag = false;
			}
			if (flag) ans++;
		}
		arr[num++] = c;
	} while (p != x);
	return ans;
}

int main (int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int a,b;
		cin >> a >> b;
		cout << "Case #" << i << ": ";
		int ans = 0;
		for(int k = a; k < b; k++) {
			ans += check(k,b);
		}
		cout << ans << endl;
	}
	return 0;
}
