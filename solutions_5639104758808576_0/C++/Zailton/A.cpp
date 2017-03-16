#include<bits/stdc++.h>
 
using namespace std;
 
// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) FOR(i, 0, a)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb(e) push_back(e)

const int MAXN = 1000006;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	FORR (c, t) {
		int m;
		cin>>m;
		string s;
		cin>>s;
		int res = 0, acc = 0;
		FORR (i, m+1) {
			int x = s[i]-'0';
			if (x==0) continue;
			if (i>acc) {
				res += i-acc;
				acc = i;
			}
			acc += x;
		}
		cout << "Case #" << c+1 << ": " << res << endl;
	}
}
