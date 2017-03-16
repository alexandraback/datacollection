#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:300000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

map <vector <int>, set <int> > res;

void calc(int n, int m, vector <int> tt){
	if (n == 0){
		forn(mask, 1<<sz(tt)){
			int v = 1;
			forn(j,sz(tt)){
				if ((1 << j) & mask){
					v *= tt[j];
				}
			}
			res[tt].insert(v);
		}		
		return;
	}
	for (int i=2; i<=m; i++){
		vector <int> nxt = tt;
		nxt.pb(i);
		calc(n-1,m,nxt);
	}
}

int main(){
#ifdef dudkamaster
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int t;
	scanf("%d", &t);
	forn(tc,t){
		printf("Case #%d:\n", tc+1);
		int r,n,m,k;
		scanf("%d%d%d%d", &r, &n, &m, &k);
		vector <int> tt;
		calc(n,m,tt);
		forn(i,r){
			tt.assign(k,0);
			forn(j,k)
				scanf("%d", &tt[j]);
			int cnt = 0;
			vector <int> ans(n,2);
			for (map <vector <int>, set <int> > :: iterator it = res.begin(); it!=res.end(); it++){
				int tcnt = 0;
				forn(j,k)
					if (it->second.count(tt[j])==1)
						tcnt++;
				if (tcnt > cnt){
					cnt = tcnt;
					ans = it->first;
				}
			}
			forn(i,n)
				printf("%d", ans[i]);
			puts("");
		}
	}
	return 0;
}