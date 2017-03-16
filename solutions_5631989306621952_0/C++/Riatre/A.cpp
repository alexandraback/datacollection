#include <bits/stdc++.h>

using namespace std;

char word[1111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d: ", ++TK);

		scanf("%s", word);
		int len = strlen(word);

		string ans = "";
		ans += word[0];
		for(int i = 1;i < len;i++) {
			if (word[i] + ans >= ans + word[i]) ans = word[i] + ans;
			else ans += word[i];
		}
		cout << ans << endl;
	}
	return 0;
}