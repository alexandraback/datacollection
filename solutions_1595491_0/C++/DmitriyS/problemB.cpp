#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define fo(i, n) for (int i = 0; i < (n); i++)
#define rfo(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	int T;
	cin >> T;
	fo(casenum,T)
	{
		int N,s,p;
		int scores[110];
		int nsup[110];
		int sup[110];
		int used[110];
		clr(used,0);
		cin >> N >> s >> p;
		fo(i,N)
		{
			cin >> scores[i];
			if (scores[i] == 0)
			{
				nsup[i] = 0;
				sup[i] = 0;
			}
			else
			{
				nsup[i] = scores[i] / 3;
				if (scores[i] % 3 != 0)
					nsup[i]++;
				sup[i] = min(10, (scores[i]+4) / 3 );
			}
			
		}
		//cout << casenum << " : " << endl;
		//fo(i,N)
		//	cout << sup[i] << " <-> " << nsup[i] << endl;
		
		int count = 0;
		fo(i,N)
			if (nsup[i] >= p)
			{
				count++;
				used[i] = 1;
			}
		int res = s;
		int i = 0;
		while ( res != 0 and i < N)
		{
			if ( !used[i] && sup[i] >= p)
			{
				res--;
				count++;
			}
			i++;
		}
		cout << "Case #" << casenum+1 << ": " << count << endl;
	}
	
	
	return 0;
}