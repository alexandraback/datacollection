#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d ", &t);
	for (int tcase = 1; tcase <= t; tcase++) {
		string str;
		cin >> str;
		string res = str;
		int len = str.size();
		for (int i = 1; i < len; i++) {
			if (str[i] < res[0])
				res[i] = str[i];
			else {
				for (int j = i; j >= 1; j--)
					res[j] = res[j - 1];
				res[0] = str[i];
			}
		}
		cout << "Case #" << tcase << ": " << res << endl;
	}
	return 0;
}
