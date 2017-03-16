#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<map>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>
#define pb push_back 

#define MAX 1000001
#define MOD 1000000007LL

map<pp, int> ff, ss, tt;

int main() {

	int t, j, p, s, k;

	cin>>t;
	FOR(i, 1, t+1) {
		cin>>j>>p>>s>>k;

		cout<<"Case #"<<i<<": ";
		
		ff.clear(); ss.clear(); tt.clear();
		vector<pair<pp, int> > v;
		for(int n=s;n>0;n--) {
			FOR(m, 1, p+1) {
				FOR(l, 1, j+1) {
					if((ff[{l, m}] < k) && (ss[{l, n}] < k) && (tt[{m, n}] < k)) {
						v.pb({{l, m}, n});
						ff[{l, m}]++;
						ss[{l, n}]++;
						tt[{m, n}]++;
					}
				}
			}
		}

		cout<<v.size()<<endl;
		FOR(l, 0, v.size()) {
			cout<<v[l].first.first<<" "<<v[l].first.second<<" "<<v[l].second<<" "<<endl;
		}
		
	}
	return 0;
}













