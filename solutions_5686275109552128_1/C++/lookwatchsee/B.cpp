#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

bool solvable(vector<int>& v, int t, int n) {
	vector<int> cut(n,0);
	while (t>=0) {
		bool pass = true;
		for (int i=n-1;i>=0 ;--i) {
			int a=0;
			if (cut[i]==0) a=v[i];
			else if (v[i]%(cut[i]+1) ==0 ) {
				a=v[i]/(cut[i]+1);
			} else {
				a=1+ v[i]/(cut[i]+1);
			}
			if (a > t) {
				pass = false;
				t--;
				cut[i]++;
			}
		}
		if (pass) {
			return true;
		}
	}
	return false;
}

int solve (vector<int>& v, const int n) {
	sort(v.begin(), v.end());
	int b=1, e=v[n-1]+1;
	while (b<e) { //[b, e)
		int t = b+(e-b)/2;
		bool r=solvable(v,t,n);
		if (!r) {
			b=t+1;
		} else {
			e=t;
		}
	}
	return e;
}

int main(void) {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int D;
		cin>>D;
		vector<int> v(D, 0);
		for (int i=0;i<D;++i) {
			int x;
			cin>>x;
			v[i] = x;
		}
		int ans = solve(v, D);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
