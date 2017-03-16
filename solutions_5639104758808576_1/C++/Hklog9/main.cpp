#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int main() {
	freopen("out", "w", stdout);
	unsigned short int Case, Smax, tmp = 0, ans = 0, loop = 0;
	string s_k;
	scanf("%hu", &Case);
	loop = Case;
	while (Case--) {
		cin >> Smax >> s_k;
		for (short int i = 0; i < (short int) s_k.length(); i++) {

			if (i > tmp) {
				ans += (i - tmp);
				tmp = i;
			}
				tmp += s_k[i] - '0';
		}
		printf("Case #%d: %hu\n", loop - Case, ans);
		ans = 0;
		tmp = 0;
	}
	return 0;
}
