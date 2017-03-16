#include <iostream>
using namespace std;
bool use[30];
bool visit[30];
bool flag = true;
int child[30];
int repeat[30];
bool app[30];
char str[200];
__int64 mod = 1000000007;
__int64 jc[200];
bool in[30];
bool en[30];
void parseStr() {
	if (use[str[0]-'a'])
	{
		flag = false;
		return;
	}
	int i, j = 1, len;
	
	for (i = 1; str[i] != 0; i++)
	{
		
		if (str[i] != str[i-1])
		{
			app[str[i]-'a'] = true;
			str[j++] = str[i];
		}
	}
	len = j;
	if (j == 1)
	{
		repeat[str[0] - 'a']++;
		return;
	}
	if (str[0] == str[len-1])
	{
		flag = false;
		return;
	}
	if (child[str[0]-'a'] != -1)
	{
		flag = false;
		return;
	}
	app[str[0]-'a'] = true;
	child[str[0] - 'a'] = str[len-1] - 'a';
	in[str[len-1] - 'a'] = true;
	en[str[0]-'a'] = true;
	j = 1;
	for (;j <= len-2; j++)
	{
		app[str[j]-'a'] = true;
		if ((use[str[j]-'a'] || child[str[j]-'a'] != -1) && str[j] != str[j-1])
		{
			flag = false;
			return;
		}
		use[str[j]-'a'] = true;
	}
	if (len > 2 && use[str[len-1]-'a'])
	{
		flag = false;
		return;
	}
	app[str[len-1]-'a'] = true;
}
void solveB(int tc)
{	
	int i, j;
	jc[1] = 1;
	jc[0] = 1;
	for (i = 2; i <= 100; i++)
	{
		jc[i] = (jc[i-1] * i) % mod;
	}
	for (i = 0; i < 26; i++)
	{
		en[i] = false;
		in[i] = false;
		app[i] = false;
		use[i] = false;
		visit[i] = false;
		repeat[i] = 0;
		child[i] = -1;
	}
	int m;
	scanf("%d", &m);
	flag = true;
	for (i = 0; i < m; i++)
	{
		scanf("%s", &str);
		if (!flag)
		{
			continue;
		}
		parseStr();
	}
	__int64 ans = 1;
	int c = 0;
	for (i = 0; i < 26 && flag; i++)
	{
		__int64 x = 1;
		ans = (ans * jc[repeat[i]]) % mod;
		if (!visit[i] && app[i] && in[i] == false && en[i])
		{
			c++;
			j = i;
			while (j != -1)
			{
				visit[j] = true;
				j = child[j];
				if (j != -1 && visit[j])
				{
					flag = false;
					break;
				}
			}
			ans = (ans * x) % mod;
		}
	}
	for (i = 0; i < 26 && flag; i++)
	{
		if (!visit[i] && app[i] && repeat[i] == 0 && !use[i])
		{
			flag = false;
		}
	}
	ans = (ans * jc[c]) % mod;
	if (flag)
	{
		printf("Case #%d: %I64d\n", tc, ans);
	} else {
		printf("Case #%d: 0\n", tc);
	}
	
}
int main()
{
//	freopen("c:\\data\\r1\\B-small-attempt5.in", "r", stdin);
//	freopen("c:\\data\\r1\\B-small-attempt5.out", "w", stdout);
	
	int tc;
	scanf("%d", &tc);
	int i;
	for (i = 1; i <= tc; i++)
	{
		solveB(i);
	}
	return 0;
}