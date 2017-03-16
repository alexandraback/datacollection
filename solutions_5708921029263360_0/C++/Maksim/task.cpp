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

typedef pair<int, int> TKey;
typedef map<TKey, int> TMap;

bool IsOk(TMap& m, const TKey& k, const int lim){
	return m[k] < lim;
}

void Check(const vector<int>& v, int K){
	TMap jp, js, ps;
	FOR(i, v.size()/3){
		int j = v[3*i+0];
		int p = v[3*i+1];
		int s = v[3*i+2];
		TKey k_jp(j,p);
		TKey k_js(j,s);
		TKey k_ps(p,s);
		if(++jp[k_jp] > K) cout << "www" << endl;
		if(++js[k_js] > K) cout << "www" << endl;
		if(++ps[k_ps] > K) cout << "www" << endl;
	}
}

void SolveCase()
{
	int J,P,S,K; cin >> J >> P >> S >> K;
	TMap jp, js, ps;
	vector<int> res;
	for(int j=1; j<=J; ++j){
	for(int p=1; p<=P; ++p){
	for(int s=1; s<=S; ++s){
		TKey k_jp(j,p);
		TKey k_js(j,s);
		TKey k_ps(p,s);
		if(    !IsOk(jp, k_jp, K)
			|| !IsOk(js, k_js, K)
			|| !IsOk(ps, k_ps, K))
			continue;
		jp[k_jp]++;
		js[k_js]++;
		ps[k_ps]++;
		res.push_back(j);
		res.push_back(p);
		res.push_back(s);
	}
	}
	}
	cout << res.size()/3 << endl;
	FOR(i,res.size()/3){
		cout << res[3*i] << " " << res[3*i+1] << " " << res[3*i+2] << endl;
	}
	//Check(res, K);
}

void test1()
{
}

int main()
{
	//test();return 0;
	int t; cin >> t;
	FOR(i,t){
		cout << "Case #" << i+1 << ": ";
		SolveCase();
		//cout << endl;
	}
	return 0;
}