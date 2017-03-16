#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>


const long long mod = 1000000007;


using namespace std;


char buf[1046];
int used[1046];
int timer = 146;
long long fact[1046];


bool valid(string & s)
{
	timer++;
	for(int i = 0; i < s.length(); i++)
	{
		if(i > 0 && used[s[i]] == timer && s[i] != s[i - 1])
			return false;
		used[s[i]] = timer;
	}
	return true;
}


string s[146];
int first[146], last[146], inter[146], strict[146];
int cnt[146][146];
bool canStart[146];
bool canFinish[146];
bool ussed[146];


long long buildChain(int e)
{
	if(ussed[e])
		return 0;
	ussed[e] = true;
	long long res = fact[cnt[e][e]];
	if(canFinish[e])
		return res;
	int pos = -1;
	for(int i = 0; i < 26; i++)
		if(cnt[e][i] > 0 && e != i)
			pos = i;
	if(pos == -1)
		return 0;
	return res * buildChain(pos) % mod;
}


bool pres[146];


void solve(int t)
{
	fprintf(stderr, "%d\n", t);
	int n;
	scanf("%d", &n);
	vector<pair<string, int> > v;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", buf);
		s[i] = string(buf);
	}
	for(int i = 0; i < n; i++)
	{
		if(!valid(s[i]))
		{
			printf("Case #%d: %d\n", t, 0);
			return;
		}
		first[i] = s[i][0] - 'a';
		last[i] = s[i][(int)s[i].length() - 1] - 'a';
		inter[i] = 0;
		strict[i] = 0;
		for(int j = 1; j < (int)s[i].length() - 1; j++)
		{
			int num = s[i][j] - 'a';
			inter[i] |= (1 << num);
			if(num != first[i] && num != last[i])
			{
				strict[i] |= (1 << num);
			}
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if((strict[i] & inter[j]) != 0 || (strict[j] & inter[i]) != 0)
			{
				printf("Case #%d: %d\n", t, 0);
				return;
			}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
			{
				for(int k = 0; k < s[j].length(); k++)
				{
					int num = s[j][k] - 'a';
					if(strict[i] & (1 << num))
					{
						printf("Case #%d: %d\n", t, 0);
						return;
					}
				}
			}
	memset(pres, false, sizeof(pres));
	memset(canStart, false, sizeof(canStart));
	memset(canFinish, false, sizeof(canFinish));
	for(int i = 0; i < n; i++)
		pres[first[i]] = pres[last[i]] = true;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++)
		cnt[first[i]][last[i]]++;
	for(int i = 0; i < 26; i++)
	{
		int startsAndNotEnds = 0;
		int endsAndNotStarts = 0;
		int totCnt = 0;
		for(int j = 0; j < 26; j++)
		{
			totCnt += cnt[i][j] + cnt[j][i];
			if(i != j && cnt[i][j] > 0)
				startsAndNotEnds++;
			if(i != j && cnt[j][i] > 0)
				endsAndNotStarts++;
		}
		if(startsAndNotEnds > 1 || endsAndNotStarts > 1)
		{
			printf("Case #%d: %d\n", t, 0);
			return;
		}
		if(totCnt == 0)
			continue;
		if(startsAndNotEnds == 0)
			canFinish[i] = true;
		if(endsAndNotStarts == 0)
			canStart[i] = true;
	}
	memset(ussed, false, sizeof(ussed));
	int blocks = 0;
	long long ans = 1;
	for(int i = 0; i < 26; i++)
	{
		if(!ussed[i] && canStart[i])
		{
			blocks++;
			ans = ans * buildChain(i) % mod;
		}
	}
	for(int i = 0; i < 26; i++)
		if(pres[i] && !ussed[i])
			ans = 0;
	ans = ans * fact[blocks] % mod;
	printf("Case #%d: %lld\n", t, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	fact[0] = 1;
	for(int i = 1; i < 146; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}