#include <iostream>
#include <array>
#include <vector>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

#define ull unsigned long long


#define dfor(i,n) for(ull i = 0; i < n; i++)
#define rfor(i,n) for(ull i = n-1;i >=0; i--)
#define all(k) k.begin(),k.end()
#define ifor(i,b,n) for(auto i=b, i!=n, i++)

int solve(int m, int n, int k, int ak) {
	int x, y;

	while(true) {
		x = (int)(sqrt(k) + 0.5);
		x = min(x, m);
		x = min(x, m);
		if((k % x == 0) || x == 1) break;
		k++;
	}
	y = k / x;
	if(x * y - 4 >= ak + 2 && x >= 4 && y >= 4) {
		return x * 2 + y * 2 - 8 - 1;
	}
	return x * 2 + y * 2 - 8;

}



void solv() {
	int n, m, k;
	cin >> n >> m >> k;
	int mini = 1002;
	if (m > n) {
		swap(m,n);
	}

	
	if (n <= 2 || m <= 2) {cout << k; return;}
	if (k >= n * m - 4) {
		cout <<  n * 2 + m * 2 - 4 + k - n *m;
		return;
	}
	int a  = solve(m, n, k+4, k);
	int b = solve(m, n, k+3, k)+1;
	cout << min(a, b);
}

int main () {

	int T, cases = 0;
	cin >> T;
	while (T--) {
		cout << "Case #" << ++cases << ": " ;
		solv();
		cout << endl;
	}
	
	return 0;
}

