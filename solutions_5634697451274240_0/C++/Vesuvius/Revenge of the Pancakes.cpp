#include <bits/stdc++.h>
using namespace std;

bool sudah[10];
long long last;
int cnt;

int main() {
	int T;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	for (int z = 1; z <= T; ++z) {
		string str;
		cin >> str;
		int sum = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '-') {
				++sum;
				while (i < str.length() && str[i] == '-') {
					++i;
				}
				--i;
			}
		}
		
		int ret = (str[0] == '-' ? sum * 2 - 1 : sum * 2);
		
		printf("Case #%d: %d\n", z, ret);
	}
}
