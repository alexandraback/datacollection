#include <iostream>
using namespace std;

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		string s;
		int n;
		cin >> s >> n;
		int k = 0;
		int len = s.size();
		int ret = 0;
		int h = 0;
		for (int i = 1; i <= len; i++) {
			if (s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u') h = 0;
			else h++;
			if (h >= n) k = i;
//			cout << i << " " << h << " " << k << " " << (k == 0 ? 0 : i-(i-k+n-1)) << endl;
			if (k != 0) {
				ret += i-(i-k+n-1);
			}
		}
		cout << "Case #" << ti << ": " << ret << endl;
	}
	return 0;
}
