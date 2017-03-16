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

/*struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};*/

int v[1004];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tx;
	cin>>tx;
	FORR (c, tx) {
		int d;
		cin>>d;
		FORR (i, d) cin>>v[i];

		int res = 1010;
		FOR (i, 1, 1010) {
			int cnt = 0;
			FORR (j, d) {
				cnt += (v[j]-1)/i;				
			}
			res = min (res, i+cnt);
		}
		cout << "Case #" << c+1 << ": " << res << endl;
	}
}
