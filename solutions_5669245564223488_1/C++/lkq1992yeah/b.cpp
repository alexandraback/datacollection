#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 120
#define MAXL 120
#define MOD 1000000007

int n;
char trains[MAXN][MAXL];
char st[MAXN][10];
int ind[26], oud[26], same[26];

int pa[26];
int grps = 0;
int gind[26], goud[26], visit[26], usedchar[26];

int Find(int x)
{
	if (x != pa[x])
		pa[x] = Find(pa[x]);
	return pa[x];
}

void Union(int a, int b)
{
	int ra = Find(a), rb = Find(b);
	pa[ra] = rb;
}

int work()
{
	memset(ind, 0, sizeof ind);
	memset(oud, 0, sizeof oud);
	memset(same, 0, sizeof same);
	int i, j, scnt = 0;
	for (i = 0; i < n; i++)
	{
		char x = st[i][0], y = st[i][1];
		if (x == y)
		{
			same[x - 'a']++;
			scnt++;
		}
		else
		{
			ind[x - 'a']++;
			oud[y - 'a']++;
		}
	}
	// printf("scnt = %d\n", scnt);
	// printf("same: "); for (i = 0; i < 26; i++) printf("%d ", same[i]); printf("\n");
	if (scnt == n)			//all the same, k! * am * bm * cm * ...
	{
		for (i = grps = 0; i < 26; i++)
			if (same[i] > 0) grps++;
	}
	else
	{
		for (i = 0; i < n; i++)
			if (ind[i] >= 2 || oud[i] >= 2)
			{
				// printf("Too much ind/oud. for %c !\n", i + 'a');
				return 0;		//ab ac...
			}
		
		memset(gind, 0, sizeof gind);
		memset(goud, 0, sizeof goud);
		memset(visit, 0, sizeof visit);
		memset(usedchar, 0, sizeof usedchar);
		grps = 0;
		for (i = 0; i < 26; i++) pa[i] = i;
		for (i = 0; i < n; i++)
		{
			char x = st[i][0], y = st[i][1];
			if (x == y) continue;
			usedchar[x - 'a'] = 1;
			usedchar[y - 'a'] = 1;
			Union(x - 'a', y - 'a');
		}
		// printf("ind : "); for (i = 0; i < 26; i++) printf("%d ", ind[i]); printf("\n");
		// printf("oud : "); for (i = 0; i < 26; i++) printf("%d ", oud[i]); printf("\n");
		// printf("pa  : "); for (i = 0; i < 26; i++) printf("%d ", Find(i)); printf("\n");
		
		// printf("used: "); for (i = 0; i < 26; i++) printf("%d ", usedchar[i]); printf("\n");
		
		for (i = 0; i < 26; i++)
		{
			if (!usedchar[i]) continue;
			int root = Find(i);
			if (!visit[root])
			{
				visit[root] = 1;
				grps++;
			}
			if (ind[i] == oud[i] + 1)
				gind[root]++;
			if (oud[i] == ind[i] + 1)
				goud[root]++;
		}
		// printf("gind: "); for (i = 0; i < 26; i++) printf("%d ", gind[i]); printf("\n");
		// printf("goud: "); for (i = 0; i < 26; i++) printf("%d ", goud[i]); printf("\n");
	
		for (i = 0; i < 26; i++)
		{
			if (!visit[i]) continue;
			if (gind[i] != 1 || goud[i] != 1) 
			{
				// printf("No ind/oud for chain grp No. %d !\n", i);
				return 0;				//for one grp, only one in / out
			}
		}
		for (i = 0; i < 26; i++)
			if (!usedchar[i] && same[i] > 0) grps++;
	}
	long long ans = 1;
	for (i = 1; i <= grps; i++)
		ans = (ans * i) % MOD;
	for (i = 0; i < 26; i++)
	{
		for (j = 1; j <= same[i]; j++)
			ans = (ans * j) % MOD;
	}
	return ans;
}

bool validTrain(char str[MAXL])
{
	memset(usedchar, 0, sizeof usedchar);
	int i, l = strlen(str);
	usedchar[str[0] - 'a'] = 1;
	for (i = 1; i < l; i++)
	{
		if (str[i] != str[i - 1])
		{
			if (usedchar[str[i] - 'a']) return false;
			else
				usedchar[str[i] - 'a'] = 1;
		}
	}
	return true;
}

int main()
{
	int t, cas;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		// printf("Case #%d: \n", cas);
		printf("Case #%d: ", cas);
		int i, j, k, l;
		bool flag = true;
		
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%s", trains[i]);
		for (i = 0; i < n; i++)
		{
			flag = validTrain(trains[i]);
			if (!flag)
				break;
			set<char> mids = set<char>();
			for (j = 0, l = strlen(trains[i]); j < l; j++)
				if (trains[i][j] != trains[i][0] && trains[i][j] != trains[i][l - 1])
					mids.insert(trains[i][j]);
			for (k = 0; k < n && flag; k++)
			{
				if (k == i) continue;
				for (j = 0, l = strlen(trains[k]); j < l; j++)
					if (mids.find(trains[k][j]) != mids.end())
					{
						flag = false;
						break;
					}
			}
			if (!flag)
				break;
		}
		if (flag == false)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; i < n; i++) { st[i][0] = trains[i][0]; st[i][1] = trains[i][strlen(trains[i]) - 1]; }
		// for (i = 0; i < n; i++)
			// printf("%s\n", st[i]);
		printf("%d\n", work());
	}
	return 0;
}
