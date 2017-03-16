#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
const static int wall_m = 10000;
int main() {

	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		map<int, set<pair<int, pair<int, int> > > > att;
		int wall[wall_m];
		int wall_a[wall_m];
		for(int i = 0; i < wall_m; ++i) {
			wall[i] = 0;
			wall_a[i] = 0;
		}
		int N, d, n, w, e, s, dd, dp, ds;
		cin >> N;
		for(int i = 0; i < N; ++i) {
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
			for(int a = 0; a < n; ++a) {
				att[d+dd*a].insert(make_pair(s + ds*a, make_pair(w+dp*a + 203, e+dp*a + 203)));
//				cout << d+dd*a << endl;
			}	
		}
		int res = 0;
		for(int day = 0; day < 676064; ++day) {
			if (att[day].empty()) continue;
			for(set<pair<int, pair<int, int> > >::iterator it = att[day].begin();
						it != att[day].end(); ++it) {
				bool att = false;
//				cout << it-> first << " " << it->second.first << " " << it->second.second << endl;
				for(int w = it->second.first; w < it->second.second; ++w) {
					if (wall[w] < it->first) {
						if (wall_a[w] < it->first) {
							wall_a[w] = it->first;
						}
						att = true;
					}
				}
				if (att) {
					res += 1;
				}
			}
			for(int i = 0; i < wall_m; ++i) {
				wall[i] = wall_a[i];
			}
		}
		cout << "Case #" << x << ": " << res << endl;//result 
	}
	return 0;
}
