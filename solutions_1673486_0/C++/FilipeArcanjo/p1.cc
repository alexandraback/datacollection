#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

double prod(vector<double> &p, int end)
{
	double ans = 1.0;
	FORN(i, 0, end) ans *= p[i];
	return ans;
}

double solve(vector<double> &p, int a, int b)
{
	double sol = 2+a+b;
	FORN(k, 0, a+1) {
		double prob = prod(p, a - k);
		double ns = 2*k+b+1;
		double nf = 2*k+2*b+a+2;
		double e = prob*ns + (1-prob)*nf; 
		WATCH(k);
		WATCH(e);
		WATCH(prob);
		WATCH(ns);
		WATCH(nf);
		WRITE("");
		sol = min(sol, e);
	}
	return sol;
}

int main(){
	//Descomente para acelerar cin
	//ios::sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	FORN(tc, 0, ntc) {
		int a, b;
		cin >> a >> b;
		vector<double> p(a);
		FORN(i, 0, a) cin >> p[i];
		double sol = solve(p,a,b-a);
		cout << "Case #" << (tc+1) << ": ";
		printf("%.6lf\n", sol);
	}
	
}
