#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>ans;
char input[2222];
int ch[26];
auto cti = [](char a) {return a - 'A'; };
bool recur(int c)
{
	if (c == 10)
	{
		for (int i = 0; i < 26; i++) if (ch[i]) return false;
		return true;
	}
	switch (c)
	{
	case 1:
		while (ch[cti('O')])
		{
			ch[cti('O')]--;
			ch[cti('N')]--;
			ch[cti('E')]--;
			ans.push_back(1);
		}
		return recur(3);
	case 3:
		while (ch[cti('T')])
		{
			ch[cti('T')]--;
			ch[cti('H')]--;
			ch[cti('R')]--;
			ch[cti('E')] -= 2;
			ans.push_back(3);
		}
		return recur(5);
	case 5:
		while (ch[cti('F')])
		{
			ch[cti('F')]--;
			ch[cti('I')]--;
			ch[cti('V')]--;
			ch[cti('E')]--;
			ans.push_back(5);
		}
		return recur(7);
	case 7:
		while (ch[cti('S')])
		{
			ch[cti('S')]--;
			ch[cti('E')] -= 2;
			ch[cti('V')]--;
			ch[cti('N')]--;
			ans.push_back(7);
		}
		return recur(9);
	case 9:
		while (ch[cti('N')])
		{
			ch[cti('N')] -= 2;
			ch[cti('I')]--;
			ch[cti('E')]--;
			ans.push_back(9);
		}
		return recur(10);
	}
}

void solve()
{
	while (ch[cti('Z')])
	{
		ch[cti('Z')]--;
		ch[cti('E')]--;
		ch[cti('R')]--;
		ch[cti('O')]--;
		ans.push_back(0);
	}
	while (ch[cti('W')])
	{
		ch[cti('T')]--;
		ch[cti('W')]--;
		ch[cti('O')]--;
		ans.push_back(2);
	}
	while (ch[cti('U')])
	{
		ch[cti('F')]--;
		ch[cti('O')]--;
		ch[cti('U')]--;
		ch[cti('R')]--;
		ans.push_back(4);
	}
	while (ch[cti('X')])
	{
		ch[cti('S')]--;
		ch[cti('I')]--;
		ch[cti('X')]--;
		ans.push_back(6);
	}
	while (ch[cti('G')])
	{
		ch[cti('E')]--;
		ch[cti('I')]--;
		ch[cti('G')]--;
		ch[cti('H')]--;
		ch[cti('T')]--;
		ans.push_back(8);
	}
	recur(1);
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%s", input);
		ans.clear();
		for (int i = 0; i < 26; i++) ch[i] = 0;
		for (int i = 0; i < 2222; i++)
		{
			if (input[i] == '\n' || !input[i]) break;
			ch[input[i] - 'A']++;
		}
		solve();
		std::sort(ans.begin(), ans.end());
		printf("Case #%d: ", t);
		for (int i = 0; i < ans.size(); i++) printf("%d", ans[i]);
		puts("");
	}
}