
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

char mapsTo[256];
string from[4] = {"y qee","ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string to[4]   = {"a zoo","our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
int main() {
	FOR(i,0,256)mapsTo[i] = '{';
	FOR(i,0,4)FOR(j,0,sz(from[i]))mapsTo[from[i][j]]=to[i][j];
	mapsTo['z'] = 'q';
	int tc;
	cin >> tc;
	string in;
	getline(cin,in);
	FOR(tcc,1,tc+1){
		getline(cin,in);
		FOR(i,0,sz(in))in[i] = mapsTo[in[i]];
		cout << "Case #" << tcc <<": "<< in << endl;
	}
	return 0;
}
