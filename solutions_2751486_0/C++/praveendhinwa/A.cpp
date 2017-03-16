#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath>
#include<cassert>

using namespace std;

typedef long long LL;

const int N = 100005;

int caseNo = 1;

LL sum[1000005] , a[1000005];

string s;
int val;

void input()
{
	cin >> s >> val;
}

int isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

void solve()
{
	int n = s.size();
	
	for (int i = 0; i < n; i++)
	{
		if (!isVowel(s[i]))
			a[i] = 1;
		else 
			a[i] = 0;
	}

	LL ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int cnt = 0;
			int ok = false;

			for (int k = i; k <= j; k++)
			{
				if (a[k] == 1)
				{
					cnt ++;
					if (cnt >= val)
						ok = true;
				}
				else 
					cnt = 0;
			}
			if (cnt >= val)
				ok = true;
			if (ok)
				ans ++;
		}
	}
	
	printf("Case #%d: %lld\n", caseNo ++, ans);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		input();
		solve();
	}					
	return 0;
}

