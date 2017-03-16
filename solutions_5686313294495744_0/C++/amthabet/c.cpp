#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;

#define SMALL 1
//#define LARGE 1

int main() {
#ifdef LARGE
	freopen("c_large.i", "rt", stdin);
	freopen("c_large.o", "wt", stdout);
#elif SMALL
	freopen("c_small.i", "rt", stdin);
	freopen("c_small.o", "wt", stdout);
#else
	freopen("c_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n;
		cin>>n;
		string a, b;
		vector< pair<string, string> > v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i].first>>v[i].second;
		}
		int ans = 0;
		for(int i=0;i<(1<<n);i++) {
			set<string> a,b;
			bool invalid = 0;
			int cnt = 0;
			for(int j=0;j<n;j++) {
				if(!(i&(1<<j))) continue;
				cnt++;
				bool b1 = !(a.insert(v[j].first).second);
				bool b2 = !(b.insert(v[j].second).second);
				if(b1 && b2) {
					invalid = 1;
					break;
				}
			}
			if(!invalid) {
				ans = max(ans, cnt);
			}
		}
		cout<<"Case #"<<tt<<": "<<n-ans<<endl;
	}

	return 0;
}
