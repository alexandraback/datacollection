//============================================================================
// Name        : codejam - Password Problem.cpp
// Author      : enzam
// Created At  : Apr 28, 2012 7:10:27 AM
// Description : None
//============================================================================

using namespace std;
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define ROFba(i,b,a) for(typeof(b) i=(b);i>=(a);i--)
#define ROF(i,n) ROFba(i,(n)-1,0)
#define ROF1(i,n) ROFba(i,n,1)
#define FORstl(i,s) for(typeof(s.end()) i=s.begin(); i != s.end(); i++)
#define pb push_back
#define sz(a) (int)a.size()
#define ms(a,n) memset(a, n, sizeof(a))
#define ms0(a) ms(a,0)
#define all(a) a.begin(), a.end()
#define sorts(a) sort(all(a))
#define sorta(a,n) sort(a,a+n)
#define amax(a,b) ( (a) = max( (a) , (b) ) )
#define amin(a,b) ( (a) = min( (a) , (b) ) )
#define mp make_pair
#ifndef USING_IOSTREAM
#define CC ({char a; scanf(" %c ", &a); a;})
#define II ({int a; scanf(" %d ", &a); a;})
#define DD ({double a; scanf(" %lf ", &a); a;})
#define SS(s) scanf("%s", s)
#else
#define CC ({char a; cin >> a; a;})
#define II ({int a; cin >> a; a;})
#define DD ({double a; cin >> a; a;})
#define SS(s) cin >> s
#endif
#define endl '\n'

#define DIM(a,b) typeof(b) a=(b)
#define RDIM(a,b) typeof(b) &a=(b)
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define sqr(a) ((a)*(a))
#define amax(a,b) ( (a) = max( (a) , (b) ) )
#define amin(a,b) ( (a) = min( (a) , (b) ) )
#define EPS 1e-10
//#define EPS DBL_EPSILON
#define abs(x) (((x)>0)?(x):-(x))
#define ZERO(x) (abs(x) < EPS)
#define EQ(a,b) (ZERO((a)-(b)))

//#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _r(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,int> psi;
typedef vector<pii> vii;

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p) { //pair print
	return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
	o << "{";FORstl(it, v) o << *it << ", "; return o << "}";
}

template<class T> ostream& operator<<(ostream& o, const pair<T*,int> arr) { //vector print
	o << "{";FOR(i, arr.second) o << arr.first[i] << ", "; return o << "}";
}

struct debugger
{
	ostream &out; bool first;
	void start() { first = true; }
	debugger(ostream& out):out(out) {start();}
	void nl() { out << '\n'; start(); }
    // Taken from rudradevbasak
    template<class T> debugger& operator,(const T& v) {
    	if(first) first = false; else out << ", ";
    	out << v; return *this;
    }
} dbg(cerr);

#define px first
#define py second

#define USING_IOSTREAM

int nTyped, length;
double prob[100010];

double getProb(int id, int init) {
	return init + (1 - prob[id]) * length;
}

int main() {
    //RFILE("input.txt");
	RFILE("A-small-attempt0.in");
	WFILE("A-small-attempt0.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int numT = II;
    FOR1(cno, numT) {
    	nTyped = II, length = II + 1;
    	prob[0] = 1;
    	FOR1(i, nTyped) prob[i] = prob[i - 1] * DD;

    	double ans = length + 1;
    	FORab(i, 0, nTyped) {
    		amin(ans, getProb(nTyped - i, 2*i + length - nTyped));
    	}

        printf("Case #%d: %.10lf\n", cno, ans);
    }
    return 0;
}
