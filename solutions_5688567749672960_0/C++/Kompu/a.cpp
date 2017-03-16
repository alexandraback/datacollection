#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

const int MAX_N = 9999999;

int main()
{
	int t;
	cin >> t;

	VI tab(MAX_N + 1, INF);
	tab[1] = 1;
	FOR(i, 1, MAX_N)
	{
		string str = to_string(i);
		reverse(ALL(str));
		int a = stoi(str);
		int b = i + 1;
		tab[a] = min(tab[a], tab[i] + 1);
		tab[b] = min(tab[b], tab[i] + 1);
	}

	FOR(o, 1, t)
	{
		int n;
		cin >> n;
		cout << "Case #" << o << ": " << tab[n] << endl;
	}
	return 0;
}