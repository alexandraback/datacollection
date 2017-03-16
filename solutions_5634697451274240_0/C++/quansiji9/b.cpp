#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	char s[200];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> s;

		int ans = 1;

		int len = strnlen_s(s, 200);

		if (len > 1) {
			for (int i = 0; i < len - 1; ++i)
				if (s[i] != s[i+1])
					++ans;
		}
		if (s[len-1] == '+')
			--ans;

		cout << "Case #" << tcount << ": " << ans << endl;
	}

	return 0;
}