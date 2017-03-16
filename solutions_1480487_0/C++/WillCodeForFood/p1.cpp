#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define vs vector<string>
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector< vector<int> >
#define vpi vector< pair<int,int> >
#define LL long long


int main() {
        int T; cin >> T;
        for(int iter=0;iter<T;iter++) {
			int N;
			cin >> N;
			vi sc(N);
			int x = 0;
			for(int i = 0;i < N; ++i) {cin >> sc[i]; x+=sc[i];}
			vector<double> ans;
			for(int i= 0; i < N;++i) {
				double low = 0;
				double high = 1.;
				while(high-low>1e-9) {
					double m = .5*(high + low);
					double s = 0;
					for(int j = 0;j < N && s <= 1.; ++j) {
						double r = (1.*(sc[i]-sc[j]))/(1.*x) + 1.*m;
						s += max(0.,r);
					}
					if (s <= 1.) 
						low = m;
					else
						high = m;
				}
				ans.pb(50.*(low+high));	
			}
			printf("Case #%d:",(iter+1));
			for(int i = 0; i < N; ++i) cout << " " << ans[i];
			cout << "\n";
	}
}

