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

pair<ll,int> v[1<<26];

int main() {
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++) {
		int N;
		cin >> N;
		vector<ll> S(N);
		rep(i,N) cin >> S[i];
		sort(S.begin(),S.end());
		vai:
			N = min(N,26);
			rep(i,N) v[1<<i].first = S[i];
			rep(i,1<<N) if(i & (i-1)) v[i].first = v[i&(i-1)].first + v[i^(i&(i-1))].first;
			int size = 1 << N;
			rep(i,size) v[i].second = i;
			sort(v,v+size);
			printf("Case #%d:\n",caso);
			for(int i = 1; i < size; i++) {
				for(int j = i-1; j >= 0 && v[j].first == v[i].first; j--) {
					if(v[i].second & v[j].second) continue;
					rep(k,N) if(v[i].second >> k & 1) printf("%lld ",S[k]); puts("");
					rep(k,N) if(v[j].second >> k & 1) printf("%lld ",S[k]); puts("");
					goto end;
				}
			}
			cerr << "ouch" << endl;
			S.erase(S.begin());
		goto vai;
		end:;
	}
	return 0;
}


