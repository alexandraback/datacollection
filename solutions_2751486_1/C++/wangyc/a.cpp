#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool check(char c)
{
	return (c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u');
}

int main()
{
	ifstream inf("a.in");
	ofstream ouf("a.out");
	int test;
	inf >> test;
	for (int ite = 1; ite <= test; ++ite) {
		int n;
		long long ans = 0;
		string s;
		inf >> s >> n;
		int l = 0, len = s.size();
		for (int i = 0; i < len;) {
			int j = 0;
			while (i + j < len && check(s[i + j])) ++j;
			if (!j) {
				++i;
				continue;
			}
			if (j >= n) {
				long long tmp = len - i - n + 1;
				tmp *= (i - l + 1);
				ans += tmp;
				tmp = len - n + 1;
				tmp *= (j - n);
				ans += tmp;
				tmp = 2 * i + j - n + 1;
				tmp *= (j - n);
				tmp /= 2;
				ans -= tmp;
				l = i + j - n + 1;
			}
			i = i + j;
		}
		ouf << "Case #" << ite << ": " << ans << endl;
	}
	return 0;
}

