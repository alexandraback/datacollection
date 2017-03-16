#include <stdio.h>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

int a, b;
set<int> s;

int calc(int n) {
	int p = 10, ans = 0, num = n, a[30];
	int top = 0;
	while(p * 10 <= n) p *= 10;
	s.clear();

	while(num) {
		a[top++] = num % 10;
		num /= 10;
	}
	for(int i=0; i<top/2; ++i) swap(a[i], a[top-1-i]);

	for(int i=0; i<top; ++i) {
		int tmp = 0;
		for(int j=0; j<top; ++j) {
			tmp = tmp * 10 + a[(i+j)%top];
		}
		if(tmp > n && tmp <= b && s.find(tmp) == s.end()) {
			ans++;
			s.insert(tmp);
			//if(b == 40) printf("%d %d\n", n, tmp);
		}
	}

	return ans;
}

int main() {
	int t;
	//calc(1002451);

	scanf("%d", &t);

	for(int q=1; q<=t; ++q) {
		scanf("%d%d", &a, &b);
		cout << "Case #" << q << ": ";

		ll ans = 0;
		for(int i=a; i<=b; ++i) ans = (ll)ans + calc(i);
		cout << ans << endl;
	}
	return 0;
}

