#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME "1"
#define FILE 1

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int T, N;
string s[1000];
vector <int> used[30];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &T);
	for (int g = 0; g < T; g++)
	{
		scanf("%d\n", &N);
		int res = 1, ans = 0, cnt, good;
		for (int i = 0; i < N; i++)
		{
			cin >> s[i];
		    res *= (i + 1);
		}
		sort(s, s + N);
		for (int i = 0; i < res; i++)
		{                
			cnt = 0;
			for (int j = 0; j < N; j++)
				for (int k = 0; k < (int) s[j].length(); k++)
				{
					used[s[j][k] - 'a'].pb(cnt);
					cnt++;
				}
			good = 0;	
			for (int j = 0; j < 26; j++)
			{
				if (used[j].size() == 0 || used[j][(int) used[j].size() - 1] - used[j][0] == (int) used[j].size() - 1)
					good++;
				used[j].clear();
			}
			if (good == 26)
				ans++;
			next_permutation(s, s + N);
		}
		printf("Case #%d: %d\n", g + 1, ans);
	}
    return 0;
}