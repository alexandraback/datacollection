#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

const double EPS = 1e-8;

int main() {
	int t;cin>>t;
	for(int K=1; K <= t; ++K) {
		int n;
		cin>>n;
		vector<pair<int,int> > v;
		for(int i=0;i<n; ++i) {
			int dd;cin>>dd;
			int h;cin>>h;
			int mm;cin>>mm;
			while(h--){
				v.push_back(make_pair(dd,-(mm++)));
			}
		}
		int res = 0;
		sort(v.begin(), v.end());
		if (v.size() > 1) {
			double v1 = -double(360) / v[0].second,
				   v2 = -double(360) / v[1].second;
			int d1 = v[0].first, d2 = v[1].first;
			if ((360+0.001-d1)/v1 > (360+360-d2)/v2 ||
					(360+0.001-d2)/v2 > (360+360-d1)/v1) res = 1;
		}
		printf("Case #%d: %d\n", K, res);
	}
	return 0;
}
