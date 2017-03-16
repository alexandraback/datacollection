// Anve$hi $hukla
#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(NULL);}}$;

typedef long long LL;
const int Maxn = 200005;
int testcases;

int main() {
	cin >> testcases;   

	for(int tt = 1; tt <= testcases; tt++) {
		int n;
		cin >> n;
		vector <pair <string, string> > v;
		v.resize(n);
		map <string, int> m1, m2;
		m1.clear(), m2.clear();
		
		for(int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end());
		v.erase(unique( v.begin(), v.end() ), v.end());
		n = v.size();

		int Ans = 0;

		for(int i = 0; i < (1<<n); i++) {
			int val = __builtin_popcount(i);
			if( val < 2)
				continue;
			// possible fakes = n - v;
			// set bits are real
			if(n - val <= Ans)
				continue;

			map <string, int> realF, realS;
			realF.clear(), realS.clear();

			for(int j = 0; j < n; j++) {
				if(i & (1<<j)) {
					realF[v[j].first]++;
					realS[v[j].second]++;
				}
			}

			bool Ok =  true;
			for(int j = 0; j < n; j++) {
				if( (i & (1<<j)) == 0){
					//fakes.push_back(j);
					if(realF[v[j].first]!=0 && realS[v[j].second]!=0) {
						continue;
					}
					else {
						Ok = false;
						break;
					}
				}
			}
			if(Ok)
				Ans = n - val;
		}
		cout << "Case #" << tt << ": " << Ans << endl;
	}
	return 0;
}