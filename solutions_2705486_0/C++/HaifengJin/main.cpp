#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxw 600000
#define maxl 50
#define maxn 60
#define inf 0x3f3f3f3f

int word_num;
char word[maxw][maxl];
int word_len[maxw];
char email[maxn];
int f[maxn];
int n;

void input_dic()
{
	int i = 0;
	while (scanf("%s", word[i]) != EOF)
		i++;
	word_num = i;
	for (int i = 0; i < word_num; i++)
		word_len[i] = strlen(word[i]);
}

bool ok(char *a, char *b, int len, int &d)
{
	int g[maxl];
	int num = 0;
	for (int i = 0; i < len; i++)
		if (a[i] != b[i])
			g[num++] = i;
	for (int i = 1; i < num; i++)
		if (g[i] - g[i - 1] < 5)
			return false;
	d = num;
	return true;
}

int dfs(char *st, int step)
{
	if (step == n)
		return 0;
	if (step > n)
		return inf;
	if (f[step] != -1)
		return f[step];
	int ret = inf;
	int d;
	for (int i = 0; i < word_num; i++)
		if (ok(st, word[i], word_len[i], d))
		{
			ret = min(ret, dfs(st + word_len[i], step + word_len[i]) + d);
			if (ret == 0)
			{
				f[step] = ret;
				return ret;
			}
		}
	f[step] = ret;
	return ret;
}

int work()
{
	n = strlen(email);
	return dfs(email, 0);
}

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	input_dic();
	fclose(stdin);
//	freopen("t.txt", "r", stdin);
//	freopen("y.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(f, -1, sizeof(f));
		printf("Case #%d: ", i + 1);
		scanf("%s", email);
		printf("%d\n", work());
	}
	return 0;
}
