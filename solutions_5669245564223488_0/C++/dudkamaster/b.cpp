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

int n;
vector <pair <string, int> > r;

bool read(){
	cin >> n;
	r.resize(n);
	forn(i,n){
		cin >> r[i].first;
		r[i].second = i;
	}
	return true;
}

void solve(){
	bool ok = true;
	forn(i,sz(r)){
		vector <vector <int> > pos(26);
		forn(j,sz(r[i].first))
			pos[r[i].first[j]-'a'].pb(j);
		forn(i,26)
			forn(j,sz(pos[i])-1)
				ok = ok && (pos[i][j] == pos[i][j+1]-1);
	}
	int ans = 0;
	if (ok){
		forn(i,sz(r))
			r[i].first.resize(unique(all(r[i].first))-r[i].first.begin());
		sort(all(r));
		do{
			vector <int> prev(26,-1);
			ok = true;
			int p = 0;
			forn(i,sz(r)){
				forn(j,sz(r[i].first)){
					int c = r[i].first[j]-'a';
					if (prev[c] == -1 || prev[c] == p-1){
						prev[c] = p;
						p++;
					}else{
						ok = false;
						break;
					}
				}
			}
			if (ok) ans++;
		}while (next_permutation(all(r)));
	}
	cout << ans << endl;
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
	int t;
	cin >> t;
	forn(i,t){
		read();
		cout << "Case #" << i+1 << ": ";
		solve();
	}
    return 0;
}