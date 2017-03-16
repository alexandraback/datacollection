#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>

using namespace std;

int main(){
	int TEST; cin >> TEST;
	static int lower[10000], upper[10000], used[10000];
	for(int test=1;test<=TEST;test++){
		int E, R, N;
		cin >> E >> R >> N;
		for(int i=0;i<N;i++){
			lower[i] = 0;
			upper[i] = E;
			used[i] = 0;
		}
		vector< pair<int, int> > vp;
		for(int i=0;i<N;i++){
			int t; cin >> t;
			vp.push_back(make_pair(-t, i));
		}
		sort(vp.begin(), vp.end());
		long long res = 0;
		for(int i=0;i<N;i++){
			int idx = vp[i].second;
			long long t = -vp[i].first;
			res += (upper[idx]-lower[idx])*t;
			used[idx] = 1;
			for(int j=1; ;j++){
				if(idx-j < 0) break;
				if(used[idx-j]) break;
				lower[idx-j] = max((long long)lower[idx-j], upper[idx]-lower[idx]-j*(long long)R);
			}
			for(int j=1; ;j++){
				if(idx+j >= N) break;
				if(used[idx+j]) break;
				upper[idx+j] = min((long long)upper[idx+j], j*(long long)R); 
			}
		}
		printf("Case #%d: %lld\n", test, res);
	}
}
