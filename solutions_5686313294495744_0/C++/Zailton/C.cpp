#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2000006;
const int INF = 1000000000;



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T;
	cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		
		int N;
		cin>>N;
		vector< pair<string, string> > topics;
		FORR (i, N) {
			string s1, s2;
			cin>>s1>>s2;
			topics.pb (make_pair (s1, s2));
		}
		
		int maxx = 0;
		FORR (i, 1<<N) {
			map<string, int> mp1, mp2;
			bool ok = true;
			int fake = N;
			FORR (j, N) {
				if ((1<<j) & i) {
					mp1[topics[j].first]++;
					mp2[topics[j].second]++;
					fake--;
				}
			}
			
			FORR (j, N) {
				if ((1<<j) & i) {
					if (mp1[topics[j].first] ==1 || mp2[topics[j].second]==1) {
						continue;
					} else {
						ok = false;
					}
				}
			}
			
			//cout << "aqui" << endl;
			
			FORR (j, N) {
				if (((1<<j) & i)==0) {
					mp1[topics[j].first]++;
					mp2[topics[j].second]++;
				}
			}
			
			FORR (j, N) {
				if (((1<<j) & i)==0) {
					if (mp1[topics[j].first] ==1 || mp2[topics[j].second]==1) {
						ok = false;
					}
				}
			}
			
			if (!ok) continue;
			maxx = max (maxx, fake);			
		}
		cout << maxx << endl;
	}
    
}
