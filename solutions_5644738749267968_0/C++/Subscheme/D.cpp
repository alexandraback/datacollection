#include <iostream>
#include <algorithm>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)


const int N = 1100;
int T;
double x;
int n, a[N], b[N];

int win(int *a, int *b) {
	int i = 0, j = 0, t = 0;
	while(i < n && j < n) {
		if(a[i] > b[j]) {
			t++;
			i++;
			j++;
		} else {
			i++;
		}
	}
	return t;
}

int main() {
	cin >> T;
	fo(t,T) {
		cout << "Case #" << t + 1 << ": ";
		cin >> n;
		fo(i,n) cin >> x, a[i] = (x * 100000) + 0.2;
		fo(i,n) cin >> x, b[i] = (x * 100000) + 0.2;
		sort(a,a+n);
		sort(b,b+n);
		cout << win(a,b) << ' ' << n - win(b,a) << '\n';
	}
}
