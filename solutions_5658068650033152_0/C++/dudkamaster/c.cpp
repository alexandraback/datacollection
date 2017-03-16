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

int n,m,k;

bool read(){
	scanf("%d%d%d", &n, &m, &k);
	return true;
}

bool f[20][20];
bool used[20][20];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void solve(){
	int mx = n*m, ans = INF;
	forn(mask,1<<mx){
		if (mask == 6438)
			mask = mask;
		memset(f, false, sizeof f);
		int cnt = 0;
		forn(i,mx){
			if ((1 << i) & mask){
				int r = i/m, c = i % m;
				f[r][c] = true;
				cnt++;
			}
		}
		if (cnt > k) continue;
		memset(used, false, sizeof used);
		queue <int> qr, qc;
		forn(i,n){
			if (!f[i][0]){
				qr.push(i);
				qc.push(0);
				used[i][0] = true;
			}
			if (!f[i][m-1]){
				qr.push(i);
				qc.push(m-1);
				used[i][m-1] = true;
			}
		}
		forn(i,m){
			if (!f[0][i]){
				qr.push(0);
				qc.push(i);
				used[0][i] = true;
			}
			if (!f[n-1][i]){
				qr.push(n-1);
				qc.push(i);
				used[n-1][i] = true;
			}
		}
		while (!qr.empty()){
			int vr = qr.front(); qr.pop();
			int vc = qc.front(); qc.pop();
			forn(dir,4){
				int nvr = vr + dr[dir];
				int nvc = vc + dc[dir];
				if (nvr >=0 && nvr < n && nvc >=0 && nvc<m && !used[nvr][nvc] && !f[nvr][nvc]){
					qr.push(nvr);
					qc.push(nvc);
					used[nvr][nvc] = true;
				}
			}
		}
		int tk = 0;
		forn(i,n)
			forn(j,m)
				if (!used[i][j])
					tk++;
		if (tk >= k)
			ans = min(ans,cnt);
	}
	printf("%d\n", ans);
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++){
		read();
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}