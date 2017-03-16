#include <iostream>

using namespace std;

int a[100];

void f(int n) {
	while(n > 0) { 
		a[n%10] = 1;
		n /= 10;
	}
	return;
}
int g() {
	int total = 0;
	for(int i=0;i<10;i++) total += a[i];
	return total;
}
int main() {
	freopen("A.in", "r", stdin);
	freopen("B.txt", "w", stdout);
	long long t, n, cnt, now;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> n;
		if(n == 0) {
			cout << "Case #" << ii+1 << ": INSOMNIA" << endl;
			continue;
		}
		for(int i=0;i<10;i++) a[i] = 0;
		cnt = 0;
		now = 1;
		while(cnt < 10) {
			f(now * n);
			cnt = g();
			now ++;
		}
		cout << "Case #" << ii+1 << ": " << (now - 1) * n << endl;
		
	}
}