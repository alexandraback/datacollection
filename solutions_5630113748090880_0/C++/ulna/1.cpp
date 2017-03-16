#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <cctype>
#include <utility>
#include <cassert>
#include <ctime>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define buli(x) __builtin_popcountll(x)
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define iter(c) __typeof((c).begin())
#define tr(c,i) for (iter(c) i=(c).begin();i!=(c).end();i++)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)
#define repl(i,s,e) for (int (i)=(s);(i);i=e[i])

#define TASK "B-small-attempt0 (1)"

int t;
int n;
                                                                   
int main() {
	#ifdef home
		freopen(TASK".in","r",stdin);
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for (int _t = 0; _t < t; _t++) {
		cin >> n;

		int x;
		map<int, int> c;

		for (int i = 0; i < n + n - 1; i++) {
		 	for (int j = 0; j < n; j++) {
		 	 	cin >> x;
				c[x]++;
			}
		}

		vector<int> res;

		tr(c, ite) {
		 	if (ite->sd % 2) {
		 	 	res.pb(ite->ft);
			}
		}                               

		sort(res.begin(), res.end());

	 	cout << "Case #" << _t + 1 << ":";

		for (int i = 0; i < res.size(); i++) {
		 	cout << " " << res[i];
		}

		cout << endl;
	} 
           
	#ifdef home
		eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif                                                                          
	return 0;
}