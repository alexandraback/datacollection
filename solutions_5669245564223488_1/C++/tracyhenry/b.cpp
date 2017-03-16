#include <vector>
#include <list>
#include <cctype>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int N;
map<char, int> M;

string s[1010];
int L[1010], R[1010], h[1010], fac[1010];
int mod = 1000000000 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif
	int T; cin >> T;
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= 200; i ++)
		fac[i] = (int) ((LL) fac[i - 1] * (LL) i % (LL) mod);
	
	
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		cin >> N;

		M.clear();
		for (int i = 1; i <= N; i ++)
		{
			cin >> s[i];
			for (int j = 0; j < s[i].size(); j ++)
				M[s[i][j]] ++;
		}

/*		if (N > 5)
		{
			cout << 0 << endl;
			continue;
		} */
		
		int flag = 1;
		//check inside each string
		for (int i = 1; i <= N; i ++)
		{
			int tot = 0, last = -1;
			for (int j = 0; j < s[i].size(); j ++)
				if (j == 0 || s[i][j] != s[i][j - 1])
				{
					if (last != -1)
						if (j - 1 < s[i].size() - 1 && last > 0) // 
							if (tot != M[s[i][j - 1]]) 
								flag = 0;					
					tot = 1; last = j;
				}
				else tot ++;
			if (last != 0 && s[i][s[i].size() - 1] == s[i][0])
				flag = 0;
		}
		
		if (! flag)
		{
			cout << 0 << endl;
			continue;
		}
		
		for (int i = 1; i <= N; i ++)
			h[i] = 1;
		
		//change1
		for (char c = 'a'; c <= 'z'; c ++)
		{
			int yes[200], tot = 0;
			for (int i = 1; i <= N; i ++)
			{
				yes[i] = 1;
				for (int j = 0; j < s[i].size(); j ++)
					if (s[i][j] != c)
						yes[i] = 0;
				tot += yes[i];
			}

			if (tot == 0) continue;
			vector<pair<string, int> > tmp; tmp.clear();
			for (int i = 1; i <= N; i ++)
				if (! yes[i])
					tmp.push_back(make_pair(s[i], h[i]));
			string vv = ""; vv += c;
			tmp.push_back(make_pair(vv, fac[tot]));
			
			N = tmp.size();
			for (int i = 1; i <= N; i ++)
				s[i] = tmp[i - 1].first, h[i] = tmp[i - 1].second;
		}
		
		//change2
		for (char c = 'a'; c <= 'z'; c ++)
		{
			int lo = -1, mid = -1, hi = -1;
			for (int i = 1; i <= N; i ++)
			{
				if (s[i].size() == 1 && s[i][0] == c)
				{
					mid = i; continue;
				}
				if (s[i][0] == c)
				{
					if (lo != -1) 
						flag = 0;
					lo = i;
				}
				if (s[i][s[i].size() - 1] == c)
				{
					if (hi != -1) 
						flag = 0;
					hi = i;
				}
			}
			if (lo != -1 && lo == hi) flag = 0;
			swap(lo, hi);
			if (! flag) break;
			if (lo < 0 && mid < 0 && hi < 0) continue;

			vector<pair<string, int> > tmp; tmp.clear();
			
			for (int i = 1; i <= N; i ++)
				if (i != lo && i != mid && i != hi)
					tmp.push_back(make_pair(s[i], h[i]));
			
			string gen = "";
			int count = 1;
						
			if (lo != -1)
				gen += s[lo], count = (int) ((LL) count * (LL) h[lo] % (LL) mod);
			if (mid != -1)
				gen += s[mid], count = (int) ((LL) count * (LL) h[mid] % (LL) mod);
			if (hi != -1)
				gen += s[hi], count = (int) ((LL) count * (LL) h[hi] % (LL) mod);
			
			tmp.push_back(make_pair(gen, count));
			
			N = tmp.size();
			for (int i = 1; i <= N; i ++)
				s[i] = tmp[i - 1].first, h[i] = tmp[i - 1].second;
		}
		
		
		if (! flag)
		{
			cout << 0 << endl;
			continue;
		}
		
		int ans = 1;
		for (int i = 1; i <= N; i ++)
			ans = (int) ((LL) ans * (LL) h[i] % (LL) mod);
		
		ans = (int) ((LL) ans * (LL) fac[N] % (LL) mod);
		cout << ans << endl;
	}
	
	return 0;
}
