#pragma comment(linker, "/STACK:16777216")

//#include <bits/stdc++.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define eps 1e-10
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL

#define fr(x,y,z) for(int(x)=(y);(x)<(z);(x)++)
#define rep(x,n) fr(x,0,n)
#define cast(x,t) *({stringstream ss;static t __ret;ss<<x,ss>>__ret;&__ret;})

#define dbg(x) cout << #x << " == " << x << endl
#define print(x) cout << x << endl
#define _ << " , " <<

int main() {
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++) {
		int N;
		cin >> N;
		vector<int> S(N);
		rep(i,N) cin >> S[i];
		vector<int> sum(1<<N,0);
		rep(i,N) sum[1<<i] = S[i];
		rep(i,1<<N) if(i & (i-1)) sum[i] = sum[i & (i-1)] + sum[i ^ (i&(i-1))];
		vector< pair<int,int> > v(1<<N);
		rep(i,v.size()) v[i] = pair<int,int>(sum[i],i);
		sort(v.begin(),v.end());
		printf("Case #%d:\n",caso);
		for(int i = 1; i < v.size(); i++) {
			for(int j = i-1; j >= 0 && v[j].first == v[i].first; j--) {
				if(v[i].second & v[j].second) continue;
				rep(k,N) if(v[i].second >> k & 1) printf("%d ",S[k]); puts("");
				rep(k,N) if(v[j].second >> k & 1) printf("%d ",S[k]); puts("");
				goto end;
			}
		}
		puts("Impossible"); end:;
	}
	return 0;
}


