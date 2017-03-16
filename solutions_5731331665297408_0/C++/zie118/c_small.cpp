#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
using namespace std;


#define PB push_back
#define MP make_pair

#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORE(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(s, x) memset(s, x, sizeof(s))

#define inf (1<<29)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

string ans,code[10];
char tmp[10];
int N, m;
int g[10][10];
int id[10];

stack<int> st;

bool can() {
	while (!st.empty()) st.pop();
	st.push(id[0]);
	FOR(i,1,N) {
		while (!st.empty() && g[st.top()][id[i]] == 0) st.pop();
		if (st.empty()) return false;
		st.push(id[i]);
	}
	return true;
}

int main()
{
	int T, cc = 0; scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d\n", &N, &m);
		CLR(g, 0);
		FOR(i,0,N) {
			gets(tmp);
			code[i] = string(tmp);
		}
		FOR(i,0,m) {
			int a, b;
			scanf ("%d %d", &a, &b);
			a--; b--;
			g[a][b] = g[b][a] = 1;
		}
		string dump = "99999";
		string ans = "";
		FOR(i,0,N) { id[i] = i; ans = ans + dump; }
		do {
			if (can()) {
				string s = "";
				FOR(i,0,N) s = s + code[id[i]];
				ans = min(ans, s);
			}
		} while (next_permutation(id,id+N));
		printf ("Case #%d: %s\n", ++cc, ans.c_str());
	}
	return 0;
}
