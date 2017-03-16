#ifndef _HEAD_H_
#define _HEAD_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())
#define SQR(x) ((x)*(x))

using namespace std;

template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }
#endif

map<string,int> first, second;
string s, t;

vector<pair<int,int> > a;
int n = 0;

void solve(){
	set<int> x, y;

	int ans = 0;
	for (int i=1; i<(1<<n); ++i){
		x.clear();
		y.clear();
		int ret = 0;
		for (int j=0; j<n; ++j) if (i&(1<<j))
			++ret;
		else{
			x.insert(a[j].first);
			y.insert(a[j].second);
		}
		bool ok = true;
		for (int j=0; j<n; ++j) if (i&(1<<j))
			if (x.find(a[j].first) == x.end() ||
					y.find(a[j].second) == y.end()){
				ok = false;
				break;
			}

		if (ok)
			ans = max(ans, ret);

	}
	printf("%d\n", ans);
}

int main(){
	int ts;
	scanf("%d\n", &ts);
	for (int te=1; te<=ts; ++te){

		scanf("%d", &n);

		first.clear();
		second.clear();

		int idx1 , idx2;
		idx1 = idx2 = 0;
		a.clear();

		for (int i=0; i<n; ++i){
			cin>>s>>t;
			if (first[s] == 0) first[s] = ++ idx1;
			if (second[t] == 0) second[t] = ++ idx2;
			a.push_back(make_pair(first[s], second[t]));
		}


		printf("Case #%d: ", te);
		solve();
	}
	return 0;
}
