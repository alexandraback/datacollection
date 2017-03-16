#pragma comment(linker, "/stack:16777216")
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define FILL(a,v) memset(a,v,sizeof(a))

const double PI = acos(-1.0);
const double EPS = 1e-7;

typedef long long ll;
typedef unsigned long long ull;

const int LEN = 900;
int wall[LEN];
int nwall[LEN];
int center = LEN/2;

struct attack
{
	int day, west, east, strength;

	attack(int d, int w, int e, int s) : day(d), west(w), east(e), strength(s) {}
	bool operator< (const attack& a)
	{
		return day < a.day;
	}

};

void reconstruct()
{
	for (int i = 0; i != LEN; ++i)
		wall[i] = nwall[i];
}

vector<attack> a;
void solve()
{
	a.clear();
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		int d, nn, w, e, s, dd, dp, ds;

		cin >> d>> nn>> w>> e>> s>> dd>> dp>> ds;
		for (int p = 0; p != nn; ++p)
		{
			a.push_back(attack(d+dd*p, center + 2*(w+dp*p), center + 2*(e+dp*p), s+ds*p));
		}
	}
	sort(ALL(a));
	FILL(wall,0);
	FILL(nwall,0);
	n = a.size();
	int ld = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].day != ld)
		{
			reconstruct();
		}
		ld = a[i].day;
		bool r = false;
		for (int j = a[i].west; j != a[i].east+1; ++j)
			if (wall[j] < a[i].strength)
			{
				r = true;
				nwall[j] = max(nwall[j], a[i].strength);
			}
		if (r) ++res;
//		cerr << i << (r?("+"):("-")) << endl;
	}
	cout << res << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tests;
	scanf("%d", &tests);
	++tests;
	for (int i = 1; i != tests; ++i)
	{
		printf("Case #%d: ", i);
		int time = clock();
		solve();
		cerr<<"Case #"<<i<<"\t time="<<clock()-time<<endl;
	}
}