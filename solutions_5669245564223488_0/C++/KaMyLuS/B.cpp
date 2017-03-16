#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

typedef long long int LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const int INF = 1000000001;
const LD EPS = 10e-9;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define abs(a) ((a)<0 ? -(a) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAX_N = 105;

int tc;
int n;
string cars[MAX_N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> tc;
	FOR(t, 1, tc)
	{
		cin >> n;	
		REP(i, n) 
		{
			cin >> cars[i];
		}
		
		int res = 0;
		int perm[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		do
		{
			int last[30];
			REP(i, 30) last[i] = -1;
			
			int pos = 0;
			bool ok = 1;
			
			REP(i, n)
			{
				if(!ok) break;
				
				FORE(it, cars[perm[i]])
				{
					if(last[*it-'a'] == -1 || last[*it-'a'] == pos-1)
					{
						last[*it-'a'] = pos;
					}
					else 
					{
						ok = 0;
						break;
					}
					pos++;
				}
			}
			
			if(ok)
			{
				res++;
				/*cout << "perm: ";
				REP(i, n) cout << perm[i] << ' ';
				cout << endl;*/
			}
		}
		while(next_permutation(perm, perm+n));
		
		cout << "Case #" << t << ": " << res << endl;
	}
	//system("pause");
	return 0;
}

