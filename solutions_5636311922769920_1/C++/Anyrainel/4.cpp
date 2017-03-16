#include <iostream>
using namespace std;

int c,s;
int k;
inline int min(int a, int b) {return a<b?a:b;}
int main()
{
	int T;
	unsigned long long ans;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		cout << "Case #" << kase << ": ";
		cin >>k >>c >>s;
		if(s * c < k) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for(int i = 1; i <= k; i+=c) {
			ans = (unsigned long long)i;
			for(int r = 1; r < c; r++)
				ans = (ans - 1) * k + min(i + r, k);
			cout << ans << ' ';
		}
		cout << endl;
	}
	return 0;
}