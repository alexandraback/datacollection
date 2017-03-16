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

tint ans[110];

int main()
{
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t,c,k,s;

	cin >> t;

	forsn(caso,1,t+1)
	{
		cin >> k >> c >> s;

		forsn(i,1,k+1) ans[i] = i;

		forsn(i,1,c)
		{
			forsn(i,1,k+1)
			{
				ans[i] = (tint)(i) + (ans[i] - 1) * (tint)(k);
			}
		}

		cout << "Case #" << caso << ":";
		forsn(i,1,k+1) cout << " " << ans[i];
		cout << endl;
	}

	return 0;
}