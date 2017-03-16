#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(cont) (cont).begin(),(cont).end()
#define sz(cont) int(cont.size())

#define eachx(it,beg,end) for(typeof(beg) it=beg; it!=end;++it)
#define each(it,cont) eachx(it,cont.begin(),cont.end())

#define rep(i,n) for(typeof(n) i=0; i<(n); ++i)
#define repx(i,s,t) for(typeof(s) i=(s); i<(t); ++i)
#define times(n) for(typeof(n) _=0; _<n; ++_)

#define mset memset
#define mcpy memcpy
#define mclr(x,sz) mset(x,0,sz)

int sum(int mask, const vector<int>& nums) {
	int bit=1;
	int res=0;
	rep(i, sz(nums)) {
		if(mask&bit) res+= nums[i];
		bit <<= 1;
	}
	return res;
}
void output(int mask, const vector<int>& nums) {
	int bit=1;
	rep(i, sz(nums)) {
		if(mask&bit) cout << nums[i] << " ";
		bit <<= 1;
	}
	cout << endl;
}
int main() {
	int T, CAS=1;
	cin>> T;
	while(T--) {
		vector<int> nums;
		map<int, vector<int> > smap;
		int N;
		cin >> N;
		rep(i, N) {
			int t;
			cin >> t;
			nums.pb(t);
		}
		rep(i, (1<<N)) {
			int tsum=sum(i, nums);
			smap[tsum].pb(i);
			if(sz(smap[tsum]) >= 2) break;
		}
		
		cout << "Case #" << CAS++ << ":" << endl;
		each(it, smap) {
			if(sz(it->second) >= 2) {
				output(it->second[0], nums);
				output(it->second[1], nums);
				goto next;
			}
		}
		cout << "Impossible" << endl;
		next: ;
	}
	return 0;
}
