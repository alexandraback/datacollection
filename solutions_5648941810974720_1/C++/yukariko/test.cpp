#include <bits/stdc++.h>

using namespace std;

const char *digit[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const int order[] = {0, 2, 6, 7, 5, 4, 8, 3, 9, 1};
int len[11];
int use[11][26];
char a[2001];
int b[26];
int c[11];
vector<int> res;

void push(int n)
{
	int ans = 987654321;
	for(int i=0; i < 26; i++)
		if(use[n][i])
			ans = min(ans, b[i] / use[n][i]);

	for(int i=0; i < ans; i++)
		res.push_back(n);

	for(int i=0; i < 26; i++)
		b[i] -= use[n][i] * ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int i=0; i < 10; i++)
	{
		len[i] = strlen(digit[i]);
		for(int j=0; digit[i][j]; j++)
			use[i][digit[i][j] - 'A']++;
	}

	for(int tc=1; tc <= T; tc++)
	{
		scanf("%s", a);
		memset(b, 0, sizeof(b));		
		for(int i=0; a[i]; i++)
			b[a[i]-'A']++;

		res.clear();
		for(int i=0; i < 10; i++)
			push(order[i]);


		sort(res.begin(), res.end());
		printf("Case #%d: ", tc);
		for(size_t i=0; i < res.size(); i++)
			printf("%d", res[i]);
		puts("");
	}
	return 0;
}