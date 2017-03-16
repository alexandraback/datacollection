//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

map<ii, int64> wall;
map<ii, int64> wall2;
set<int64> days;
int n;
vi di, ni, wi, ei, si, delta_di, delta_pi, delta_si;

int main()
{
//	freopen ("in.txt", "rt", stdin);
//	freopen ("out.txt", "wt", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		wall.clear();
		days.clear();
		
		cin >> n;
		di = ni = wi = ei = si = delta_di = delta_pi = delta_si = vi(n);
		for(int i = 0; i < n; i++)
		{
			cin >> di[i] >> ni[i]>> wi[i]>> ei[i]>> si[i]>> delta_di[i]>> delta_pi[i]>> delta_si[i];
			for(int risk = 0; risk < ni[i]; risk++)
			{
				days.insert(di[i] + risk * delta_di[i]);
			}
		}

		int64 ans = 0;
		for(typeof(days.begin()) it = days.begin(); it != days.end(); it++)
		{
			int day = *it;

			wall2 = wall;
			for(int i = 0; i < n; i++)
			{
				//DEBUG(day);
				if(di[i] <= day && 
					day % delta_di[i] == di[i] % delta_di[i] && 
					(day - di[i]) / delta_di[i] < ni[i])
				{
					//DEBUG(day);
					int64 attack = (day - di[i]) / delta_di[i];
					int64 west = wi[i] + attack * delta_pi[i], east = ei[i] + attack * delta_pi[i];
					int64 strength = si[i] + attack * delta_si[i];
					// interval tree ?
					bool success = false;

					for(int w = west; w <= east; w++)
					{
						if (strength > wall[make_pair(w, 0)])
						{
							success = true;
							wall2[make_pair(w, 0)] = max(wall2[make_pair(w, 0)], strength);
						}
						if (w < east && strength > wall[make_pair(w, 1)])
						{
							success = true;
							wall2[make_pair(w, 1)] = max(wall2[make_pair(w, 1)], strength);
						}
					}
					if(success)
					{
						//DEBUG(day);
						//DEBUG(i);
						ans++;
					}
				}
			}
			//for(typeof(wall2.begin()) it = wall2.begin(); it != wall2.end(); it++)
			//	wall[it->first] = max(wall[it->first], it->second);
			wall = wall2;
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}
