#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <complex>
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define FOR(i,a,b) for(i=a;i<b;i++) 
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define X first
#define Y second
#define MOD 1000000007
vs v;
int solve(char c){
	int ans = 0, f = 1, i, j;
	FOR(i, 0, 4){
		f = 1;
		FOR(j, 0, 4) if(v[i][j] != c && v[i][j] != 'T')
			f = 0;
		if(f) ans = 1;
	}
	FOR(i, 0, 4){
		f = 1;
		FOR(j, 0, 4) if(v[j][i] != c && v[j][i] != 'T')
			f = 0;
		if(f) ans = 1;
	}
	f = 1;
	FOR(j, 0, 4) if(v[j][j] != c && v[j][j] != 'T')
		f = 0;
	if(f) ans = 1;
	f = 1;
	FOR(i, 0, 4){
		j = 4-i-1;
		if(v[j][i] != c && v[j][i] != 'T')
			f = 0;
	
	}
	if(f) ans = 1;
	return ans;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t=1, test, i, c, j, a, b;
	string s, ans;
	cin >> t;
	FOR(test, 0, t){
		v.clear(); c = 0;
		FOR(i, 0, 4) cin >> s, v.push_back(s);
		FOR(i, 0, 4) FOR(j, 0, 4) if(v[i][j] == '.')
			c++;
		a = solve('X'); b = solve('O');
		if(a) ans = "X won";
		else if(b) ans = "O won";
		else if (!c) ans = "Draw";
		else ans = "Game has not completed";
		printf("Case #%d: %s\n", test+1, ans.c_str());
	}
}

