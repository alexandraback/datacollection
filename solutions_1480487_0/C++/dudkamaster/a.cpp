#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
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

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<=int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
	int t;
	cin >> t;
	forn(tc,t){
		int n;
		cin >> n;
		double x = 0;
		vector <double> a(n);
		forn(i,n){
			cin >> a[i];
			x += a[i];
		}
		double l = 0;
		double r = 100000000;
		forn(iter,200){
			double mid = (l+r)/2;
			double s = 0;
			forn(i,n)
				if (a[i]+eps<mid)
					s += (mid-a[i])/x;
			if (s-eps<1)
				l = mid;
			else
				r = mid;
		}
		vector <double> ans;
		forn(i,n)
			if (a[i]+eps<l)
				ans.pb((l-a[i])/x*100.0);
			else
				ans.pb(0);
		double s = 0;
		double cnt = 0;
		forn(i,n){
			s += ans[i];
			if (ans[i] == 0)
				cnt += 1.0;
		}
		if (abs(s-100)>eps)
			forn(i,n)
				if (ans[i] == 0)
					ans[i] = (100-s)/cnt;
		printf("Case #%d: ", tc+1);
		forn(i,n)
			printf("%0.6lf ", abs(ans[i]));
		puts("");
	}
	return 0;
}