#include <cstdio>
#include <string>
#include <iostream>

using  namespace std;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {
		bool chk[1000][2] = { false };
		string str[1000][2];
		int n;
		scanf("%d", &n);
		for (int i = 0;i < n;++i) {
			cin >> str[i][0] >> str[i][1];
			for (int j = 0;j < i;++j) {
				if (str[i][0] == str[j][0])
					chk[i][0] = chk[j][0] = true;
				if (str[i][1] == str[j][1])
					chk[i][1] = chk[j][1] = true;
			}
		}

		int res = 0;
		for (int i = 0;i < n;++i) {
			if (chk[i][0] && chk[i][1])
				++res;
		}

		printf("Case #%d: %d\n", tc,res);

	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}