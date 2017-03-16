#include <bits/stdc++.h>

using namespace std;

char ch[2000], tmpa[2000], tmpb[2000], ans[2000];

bool cmp(char *x, char *y, int Sz)
{
	for(int i = 1; i <= Sz; i++)
		if(x[i] > y[i]) return 1;
		else if(x[i] < y[i]) return 0;
	return 1;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
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
