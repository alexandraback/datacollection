#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

char l[30];
char word[2005];

void remove(vector <int> &ans, char c, string s, int x)
{
	int n = (int)s.size();
	while (l[c-'A'])
	{
		For(i, 0, n)
			--l[s[i]-'A'];

		ans.push_back(x);
	}
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		memset(l, 0, sizeof l);

		scanf("%s", word);
		int n = strlen(word);

		For(i, 0, n)
			++l[word[i]-'A'];

		vector <int> ans;
		remove(ans, 'Z', "ZERO", 0);
		remove(ans, 'W', "TWO", 2);
		remove(ans, 'U', "FOUR", 4);
		remove(ans, 'X', "SIX", 6);
		remove(ans, 'G', "EIGHT", 8);
		
		remove(ans, 'O', "ONE", 1);
		remove(ans, 'H', "THREE", 3);
		remove(ans, 'F', "FIVE", 5);
		remove(ans, 'S', "SEVEN", 7);
		remove(ans, 'N', "NINE", 9);

		sort(ans.begin(), ans.end());

		printf("Case #%d: ", caso++);
		For(i, 0, (int)ans.size())
			printf("%d", ans[i]);
		printf("\n");
	}
	
	return 0;
}