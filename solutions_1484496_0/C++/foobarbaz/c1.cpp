#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
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
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;

int64 INF = 1000*1000*1001;

map<int, VI> m;

void print(VI& foo)	{
	FOR (i, 0, foo.SZ)	{
		cout << foo[i];
		if (i < foo.SZ - 1)	cout << " ";
	}
}

int main(void)	{
	int T;
	int n;
	int s[32];
	
	cin >> T;
	FOR (nc, 1, T+1) {
		cin >> n;
		FOR (i, 0, n)	{
			cin >> s[i];
		}
		cout << "Case #" << nc << ":" << endl;
		bool done = false;
		m.clear();
		FOR (i, 1, 1<<n)	{
			int tot = 0;
			VI vd;
			FOR (j, 0, n)	if ((i & (1<<j)) != 0)	{
				vd.PB(s[j]);
				tot += s[j];
			}
			if (m.count(tot) > 0)	{
				VI foo = m[tot];
				print(foo);
				cout << endl;
				print(vd);
				cout << endl;
				done = true;
				break;
			}
			else	{
				m[tot] = vd;
			}
		}
		if (!done)	{
			cout << "Impossible" << endl;
		}
	}
}
