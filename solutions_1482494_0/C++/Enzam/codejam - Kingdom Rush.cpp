//============================================================================
// Name        : codejam - Kingdom Rush.cpp
// Author      : enzam
// Created At  : Apr 28, 2012 7:39:06 AM
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
pii levels[1010];
pair<bool,bool> completed[1010];

int dp[22][1<<21];
int nLevels;

int solve(int pt, int vis) {
	RDIM ( ans , dp[pt][vis] );
	if(ans != -1) return ans;
	if(vis == (1 << 2*nLevels) - 1) return ans = 0;
	ans = 40;
	FOR(i, nLevels) {
		int mask1 = ( 1 << (2*i+0) );
		int mask2 = ( 1 << (2*i+1) );
		int vis1 = (vis & mask1);
		int vis2 = (vis & mask2);
		if(levels[i].second <= pt) {
			if(!vis2) {
				if(!vis1) {
					amin( ans , 1 + solve(pt + 2, vis | mask1 | mask2) );
				} else {
					amin( ans , 1 + solve(pt + 1, vis | mask2 ) );
				}
			}
		} else if(levels[i].first <= pt) {
			if(!vis1) {
				amin( ans , 1 + solve(pt + 1, vis | mask1 ) );
			}
		}
	}
	return ans;
}

int main() {
	RFILE("B-small-attempt2.in");
    WFILE("B-small-attempt2.out");
	//RFILE("input.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int numT = II;
    FOR1(cno, numT) {
    	ms(dp, -1);
    	nLevels = II;
    	FOR(i, nLevels) {
    		levels[i].first = II;
    		levels[i].second = II;
    		completed[i] = mp(false, false);
    	}

    	/**
    	int nStar = 0;
    	int nMoves = 0;
    	while(1) {
    		bool taken = false;
    		FOR(j, nLevels) {
    			if(completed[j].second) continue;
    			if(levels[j].second > nStar) continue;
    			if(completed[j].first) nStar++;
    			else nStar += 2;
    			completed[j] = mp(true, true);
    			taken = true;
    			nMoves++;
    		}
    		if(taken) continue;

    		FOR(j, nLevels) {
    			if(completed[j].first) continue;
    			if(levels[j].first > nStar) continue;
    			nStar += 1;
    			completed[j] = mp(true, false);
    			taken = true;
    			nMoves++;
    			break;
    		}
    		if(!taken) break;
    	}
    	bool done = true;
    	FOR(i, nLevels) {
    		if(completed[i] != mp(true, true)) { done = false; break; }
    	}
    	//*/

    	int ans = solve(0, 0);

        printf("Case #%d: ", cno);
        if(ans == 40) printf("Too Bad\n");
        else printf("%d\n", ans);
    }
    return 0;
}
