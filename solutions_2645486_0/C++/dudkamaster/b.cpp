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

int r,n,t,e;
int v[10000];
int sp[10000];
ll d[100][100];

int main(){
#ifdef dudkamaster
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif	
	scanf("%d", &t);
	forn(tc,t){		
		ll ans = 0;
		scanf("%d%d%d", &e, &r, &n);
		forn(i,n)
			scanf("%d", &v[i]);
		memset(d,-1,sizeof(d));
		d[0][e] = 0;
		forn(i,n){
			forn(j,e+1){
				if (d[i][j] == -1) continue;
				forn(k,j+1){
					int nx = min(j-k+r,e);
					d[i+1][nx] = max(d[i+1][nx], d[i][j] + v[i]*k);
				}
			}
		}
		forn(j,e+1)
			ans = max(ans,d[n][j]);
		cout << "Case #" << tc+1 << ": " << ans << endl;
	}
	return 0;
}