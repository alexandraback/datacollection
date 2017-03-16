#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main()
{
	freopen("test.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	
	int t,b;
	tint m;

	cin >> t;

	forsn(caso,1,t+1)
	{
		cin >> b >> m;

		int ans[55][55];

		forn(i,b) forn(j,b) ans[i][j] = 0;

		forn(i,b)
		{
			forsn(j,i+1,b)
			{
				ans[i][j] = 1;
			}
		}

		cout << "Case #" << caso << ": ";

		if((1ll<<(b-2)) < m) cout << "IMPOSSIBLE" << endl;
		else
		{
			if(m < (1ll<<(b-2)))
			{
				ans[0][b-1] = 0;
				forn(i,55)
				{
					if((1ll << i) & m) continue;
					//cout << i << endl;
					if(b-2-i) ans[0][b-2-i] = 0;
				}
			}

			cout << "POSSIBLE" << endl;
			forn(i,b)
			{
				forn(j,b)
				{
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
	}

	return 0;
}