#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int a, b, k;
		cin >> a >> b >> k;
		int ans = 0;
		for(int q = 0; q < a; ++q) {
			for(int w = 0; w < b; ++w) {
				if((q & w) < k) {
					ans++;
				}
			}
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}