#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	freopen("small", "r", stdin);
	freopen("output", "w", stdout);
	int cases;
	cin >> cases;
	char vowels[] = "aeiou";
	vector<int> pos;

	for (int caseNo = 0; caseNo < cases; caseNo ++)
	{
		pos.clear();
		string s;
		int n;
		cin >> s >> n;
		int l = s.length();

		int ret = 0;
		for ( int i = 0; i < l - n + 1; i ++)
		{
			bool found = true;

			for ( int j = i; j < n + i; j ++)
			{
				bool isVowel = false;
				REP(k, strlen(vowels))
				{
					if (s[j] == vowels[k])
					{
						isVowel = true;
						break;
					}
				}
				if (isVowel)
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				pos.pb(i);
				ret += (i + 1) *(l - (i + n) + 1);
			}

		}

		int totelFound = pos.size();
		int start = 0;
		for (int i = 0; i < totelFound - 1; i ++)
		{
			for (int j = i + 1; j < totelFound; j ++ )
			{
				ret -= (pos[i] + 1 -start) * (l - (pos[j] + n) + 1);
			}
			start = pos[i] + 1;
		}


		cout << "Case #" << caseNo + 1 << ": " << ret << endl;
	}
	return 0;
}
