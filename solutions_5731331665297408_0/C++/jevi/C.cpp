#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

const int MAXN = 55;

int n, m;
int g[MAXN][MAXN];
string s[MAXN];

int stak[MAXN], ptr;

void solve() {
	cout << "Case #" << CASE << ": ";
	
	int p[MAXN];
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	
	string ans; ans += ('9'+1);
	do {
		int ptr = 0;
		stak[ptr++] = p[0];
		string curr = s[p[0]];
		bool cool = true;
		for(int i = 1; i < n && cool; i++) {
			while(ptr>0 && !g[stak[ptr-1]][p[i]]) {
				ptr--;
			}
			if(ptr==0) {
				cool = false;
				break;
			}
			curr += s[p[i]];
			stak[ptr++] = p[i];
		}
		
		if(cool && curr < ans) {
			ans = curr;
		}
	} while(next_permutation(p,p+n));
	
	cout << ans << '\n';
}

int main() {
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(CASE = 1; CASE <= TESTS; CASE++) {
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}
		memset(g,0,sizeof(g));
		for(int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			g[a][b] = g[b][a] = true;
		}
		solve();
	}
}
