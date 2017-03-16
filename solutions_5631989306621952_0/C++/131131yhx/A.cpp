#include <bits/stdc++.h>

using namespace std;

char ch[1010], tmpa[1010], tmpb[1010], ans[1010];

bool cmp(char *x, char *y, int Sz)
{
	for(int i = 1; i <= Sz; i++)
		if(x[i] > y[i]) return 1;
		else if(x[i] < y[i]) return 0;
	return 1;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int s = 1; s <= _; s++)
	{
		memset(ch, 0, sizeof ch);
		memset(tmpa, 0, sizeof tmpa);
		memset(tmpb, 0, sizeof tmpb);
		printf("Case #%d: ", s);
		scanf("%s", ch + 1);
		int st = strlen(ch + 1);
		for(int i = 1; i <= st; i++)
		{
			for(int j = 1; j < i; j++) tmpa[j + 1] = tmpb[j] = ans[j];
			tmpa[1] = ch[i], tmpb[i] = ch[i];
			if(cmp(tmpa, tmpb, i)) memcpy(ans, tmpa, sizeof tmpa);
			else memcpy(ans, tmpb, sizeof tmpb);
		}
		puts(ans + 1);
	}
	return 0;
}
