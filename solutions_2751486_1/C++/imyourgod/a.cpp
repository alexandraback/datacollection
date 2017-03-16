#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
#define inf 1000000000
#define infLL 1000000000000000000
#define MAXN 1010
#define eps 1e-10
#define pi acos(-1.0)

int main()
{
	int t;
	cin >> t;
	bool con[26];
	for (int i = 0; i < 26; i++)
		con[i] = true;
	con['a' - 'a'] = false;
	con['e' - 'a'] = false;
	con['i' - 'a'] = false;
	con['o' - 'a'] = false;
	con['u' - 'a'] = false;
	for (int cs = 1; cs <= t; cs++)
	{
		string s;
		int n;
		cin >> s >> n;
		int len = s.length();
		vector<pii> qj;
		int i = 0;
		while (i < len)
		{
			int j = 0;
			while (con[s[i + j] - 'a'] && i + j < len)
			{
				j++;
				//cout << i << " " << j << endl;
			}
			if (j >= n)
				qj.PB(MP(i, j));
			i += max(j, 1);
		}
		long long ans = 0;
		int qjc = qj.size();
		int j = 0;
//		for (i = 0; i < qjc; i++)			cout << qj[i].first << " " << qj[i].second << endl;
		for (i = 0; i < len && j < qjc; i++)
		{
			while (qj[j].first + qj[j].second <= i && j < qjc)
				j++;
			if (j < qjc)
			{
				//cout << i << " " << j << endl;
				if (qj[j].first + qj[j].second - i < n)
				{
					j++;
					if (j < qjc)
						ans += len - qj[j].first - n + 1;
				}
				else
				{
					ans += len - max(qj[j].first, i) - n + 1;
				}
			}
		}
		printf("Case #%d: %lld\n", cs, ans);
	}
	return 0;
}
