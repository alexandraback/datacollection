#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:", t);

		char str[1024];
		cin >> str;

		char ans[2048];
		char mchar = 0;
		int f = 1023, b = 1024;
		for (int i = 0; str[i]; i++) {
			if (str[i] >= mchar) {
				mchar = str[i];
				ans[f--] = str[i];
			} else {
				ans[b++] = str[i];
			}
		}

		cout << " ";
		for (int i = f + 1; i < b; i++)
			cout << ans[i];

		printf("\n");
	}

	return 0;
}
