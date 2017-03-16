#include <iostream>
#include <string>
using namespace std;

const char v[5] = {'a', 'e', 'o', 'i', 'u'};

bool checkv(char c) {
	for(int i = 0; i < 5; i++)
		if(c == v[i]) return true;
	return false;
}

int main(int argc, char *argv[]) {
	int t1, t2;
	cin >> t1;
	t2 = t1;
	while(t2--) {
		cout << "Case #" << t1 - t2 << ": ";
		string s;
		int n, l;
		unsigned int f[1000005] = {0};
		unsigned int tmp[1000005] = {0};
		cin >> s >> n;
		l = s.length();
		for(int i = 0; i < l - n + 1; ++i) {
			int j;
			for(j = 0; j < n; ++j) {
				if(checkv(s[i + j])) break;
			}
			if(j == n) f[i] = 1;
			else f[i] = 0;
		}
		for(int len = n + 1; len <= l; ++len) {
			for(int i = 0; i < l - len + 1; ++i) {
				int ans = f[i] + f[i + 1] - tmp[i + 1];
				if(ans) ++ans;
				tmp[i] = f[i];
				f[i] = ans;
			}
		}
		cout << f[0] << endl;
	}
	return 0;
}
