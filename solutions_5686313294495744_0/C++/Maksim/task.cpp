#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>
#include <list>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

typedef long long ll;

vector<int> ToBin(int x){
	vector<int> v;
	while(x){
		v.push_back(x&1);
		x/=2;
	}
	return v;
}

vector<int> ToIdx(const vector<int>& v){
	vector<int> res;
	FOR(i,v.size()) if(v[i]) res.push_back(i);
	return res;
}

typedef map<string, int> TMap;

enum{
	UNDECIDED = 0,
	FAKE = 1,
	REAL = 2
};

void SolveCase()
{
	int n; cin >> n;
	vector<pair<string, string> > all(n);
	TMap wfirst, wsecond;
	FOR(i,n){
		cin >> all[i].first >> all[i].second;
		wfirst[all[i].first]++;
		wsecond[all[i].second]++;
	}
	vector<pair<int, int> > mn(n);
	FOR(i,n){
		const string& f = all[i].first;
		const string& s = all[i].second;
		mn[i] = make_pair(min(wfirst[f], wsecond[s]), i);
	}
	sort(mn.begin(), mn.end());

	vector<int> type(n, UNDECIDED);
	FOR(i,n){
		int idx = mn[i].second;
		if(type[idx]!=UNDECIDED)
			continue;
		type[idx] = REAL;
		const string& f = all[idx].first;
		const string& s = all[idx].second;
		FOR(j,n) if(j!=idx){
			if(type[j]!=UNDECIDED)
				continue;
			const string& ff = all[j].first;
			const string& ss = all[j].second;
			if((f==ff || s==ss) && (wfirst[ff]>1) && (wsecond[ss]>1)){
				wfirst[ff]--;
				wsecond[ss]--;
				type[j] = FAKE;
			}
		}
		wfirst[f]--;
		wsecond[s]--;
	}
	//cout << "tmp" << endl;
	//FOR(i,n) cout << type[i] << endl;
	//cout << "tmp" << endl;
	int res = 0;
	FOR(i,n) if(type[i]==FAKE) ++res;
	cout << res;
}

void test()
{
	int n = 10;
	vector<int> v(n);
	FOR(i,n) v[i]=i;
	ll cnt = 0;
	do{
		++cnt;
	}while(next_permutation(v.begin(), v.end()));
	cout << cnt << endl;
}

int main()
{
	//test();return 0;
	int t; cin >> t;
	FOR(i,t){
		cout << "Case #" << i+1 << ": ";
		SolveCase();
		cout << endl;
	}
	return 0;
}