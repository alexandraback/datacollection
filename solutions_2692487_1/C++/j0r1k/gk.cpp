#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int a[1111], n, t, tt, x;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	cin >> t;
	tt = t;
	while (t > 0){
		t--;
		cin >> x >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int ans = 2000000000;
		int q = 0;
		int kol = 0;
		if (x == 1) kol = n; else{
			while (true){
				while (x > a[q] && q < n) x = x + a[q++];
				if (q == n) break;
				if (kol + n - q < ans) ans = kol + n - q;
				while (x <= a[q]){
					kol++;
					x = x + x - 1;
				}
			}
		}
		if (kol < ans) ans = kol;
		cout << "Case #" << tt - t << ": " << ans << endl;
	}
	return 0;
}
