# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <iostream>
# include <algorithm>

using namespace std;

int n;
char p[21];

int cnt[256];

int ans;
int ansa[21];
int crr[256];
int cntc;

string s[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool go (int idx, int m)
{
	int i, j;
	if (cntc > n)
		return 0;
	for (i = 0; i < n; i ++)
	{
		if (crr[p[i]] > cnt[p[i]])
			return 0; 
	}
	for (i = 0; i < n; i ++)
	{
		if (crr[p[i]] < cnt[p[i]])
			break; 
	}
	if (i == n)
		return 1;
	
	for (i = m; i <= 9; i ++)
	{
		for (j = 0; j < s[i].size (); j ++)
		{
			crr[s[i][j]] ++;
			cntc ++;
		}
		ans = idx;
		ansa[idx] = i;
		if (go (idx + 1, i))
			return 1;
		ans = -1;
		ansa[idx] = -1;
		for (j = 0; j < s[i].size (); j ++)
		{
			crr[s[i][j]] --;
			cntc --;
		}
	} 
	return 0;
}

int main ()
{
	int nt, t, i;
	scanf ("%d", &t);
	for (nt = 1; nt <= t; nt ++)
	{
		memset (cnt, 0, sizeof (cnt));
		memset (crr, 0, sizeof (crr));
		ans = -1;
		cntc = 0;
		scanf ("%s", p);
		n = strlen (p);
		for (i = 0; i < n; i ++)
			cnt[p[i]] ++;
		go (0, 0);
		printf ("Case #%d: ", nt);
		
		for (i = 0; i <= ans; i ++)
			printf ("%d", ansa[i]);
		printf ("\n");				
	}
	return 0;
}

