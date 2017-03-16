#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>
#pragma comment(linker, "/STACK:640000000")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
double a[1111],b[1111];
void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a + n);
	set<double> st;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		st.insert(b[i]);
	}
	sort(b,b + n);
	int y = 0;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = i; j < n; j++) {
			if (a[j] < b[j - i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			y = n - i;
			break;
		}
	}	
	int z = 0;
	for (int i = 0; i < n; i++) {
		set<double>::iterator it = st.upper_bound(a[i]);
		if (it != st.end()) {
			st.erase(it);
		} else {
			st.erase(st.begin());
			z++;
		}
	}
	int zz = 0;
	for (int i = 0; i < n; i++) {
		st.insert(b[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		set<double>::iterator it = st.upper_bound(a[i]);
		if (it != st.end()) {
			st.erase(it);
		} else {
			st.erase(st.begin());
			zz++;
		}
	}
	assert(z == zz);
	cout << y << " " << z << endl;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int Cases; cin >> Cases;
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		solve();
	}
	return 0;
}
