#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 2002000;

vector<int> g[nmax];
bool used[nmax];

string calc(int a){
	char bbf[20];
	memset(bbf, 0, sizeof bbf);
	sprintf(bbf, "%d", a);
	string res = bbf;
	return res;
}

void solve(){
	int a, b, res = 0;;
	cin >> a >> b;
	for (int i = a; i <= b; i ++)
		forn(j, g[i].size())
			if (g[i][j] <= b)
				res ++;
	cout << res << endl;
}

int main ()
{
	for (int i = 1; i <= nmax; i ++){
		string s = calc(i);
		forn(j, s.size()){
			int now = atoi(s.data());
			if (now > i && !used[now]){
				g[i].pb(now);
				used[now] = 1;
			}
			char buf = s[0];
			for (int w = 0; w + 1 < s.size(); w ++)
				s[w] = s[w + 1];
			s[s.size()-1] = buf;
		}
		forn(j, g[i].size())
			used[g[i][j]] = 0;
//		sort(all(g[i]));
//		g[i].erase(unique(all(g[i])), g[i].end());
	}
	cerr << clock() << endl;


	int tst;
	cin >> tst;
	forn(i, tst){
		printf("Case #%d: ", i + 1);
		solve();
	}

	
	return 0;
}
