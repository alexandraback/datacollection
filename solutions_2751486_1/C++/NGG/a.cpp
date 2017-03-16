#include <iostream>
using namespace std;

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		string s;
		long long n;
		cin >> s >> n;
		long long k = 0;
		long long len = s.size();
		long long ret = 0;
		long long h = 0;
		for (long long i = 1; i <= len; i++) {
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
