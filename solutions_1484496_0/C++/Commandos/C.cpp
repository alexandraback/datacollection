#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <assert.h>
#include <limits>
#define _USE_MATH_DEFINES
#include <math.h>

#define pb(a) push_back(a)
#define sz size()
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef long double ld;

template<typename T> inline void SWAP(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}
template<typename T> inline T ABS(const T &VAL) {
	return VAL < 0 ? -VAL : VAL;
}
template<typename T> inline T MAX(const T &a, const T &b) {
	return a < b ? b : a;
}
template<typename T> inline T MIN(const T &a, const T &b) {
	return a < b ? a : b;
}
template<typename T> inline T SQR(const T &a) {
	return a * a;
}

#define MSET(d) memset(d,0,sizeof(d))
#define forn(i,n) for(int i=0;i!=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i!=b;i++)
#define for1ab(i,a,b) for(int i=a+1;i<=b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define ford1ab(i,a,b) for(int i=b;i!=a;i--)
#define ford(i,n) for(int i=n-1;i!=-1;i--)
#define ford1(i,n) for(int i=n;i!=0;i--)

//const int INTinf = 2147483647;
const int INTinf = 1000000005;
const int nINTinf = 0 - 2147483648;
const ll LLinf = 9223372036854775807LL;

using namespace std;
typedef pair<int, int> pii;
typedef unsigned int uint;

int t, n;
int vals[25];
vector<pii> vc;
vector<int> ans;
void getV(int pos) {
	vector<pii>::iterator it = vc.begin() + pos;
	ans.clear();
	ans.pb(it->X - it->Y);
	int sum = it->Y;
	while (sum) {
		it = lower_bound(vc.begin(), vc.end(), pii(sum, 0));
		ans.pb(it->X - it->Y);
		sum = it->Y;
	}
	ford(i,ans.sz) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	forn(x,t) {
		cin >> n;
		forn(i,n) {
			cin >> vals[i];
		}
		vc.clear();

		forn(i,n) {
			ford(j,vc.size()) {
				vc.pb(pii(vc[j].X+vals[i],vc[j].X));
			}
			vc.pb(pii(vals[i],0));
			sort(ALL(vc));
			int to = vc.sz - 1;
			forn(j,to) {
				if (vc[j].X == vc[j + 1].X) {
					cout << "Case #" << x + 1 << ":" << endl;
					getV(j);
					getV(j + 1);
					goto nxt;
				}
			}
		}
		cout << "Case #" << x + 1 << ": impossible" << endl;
		nxt: ;
	}

#ifndef ONLINE_JUDGE
	fclose(stdout);
	fclose(stdin);
#endif
	return 0;
}
