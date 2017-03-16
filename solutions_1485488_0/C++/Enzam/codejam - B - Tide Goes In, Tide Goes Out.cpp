//============================================================================
// Name        : codejam - B - Tide Goes In, Tide Goes Out.cpp
// Author      : enzam
// Created At  : May 5, 2012 11:19:29 PM
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


int initWater, nRow, nCol;
template<class NodeType, class DistType> struct Dijstra {
	map<NodeType, DistType> D;
	typedef pair<DistType, NodeType> pdti;
	map< NodeType , vector<pdti> > adj;
	void init() { adj.clear(); }

	void addOneWayEdge(NodeType a, NodeType b, DistType cost) {
		adj[a].push_back(mp(cost, b));

		//_(a, b, cost);
	}

	void addEdge(NodeType a, NodeType b, DistType cost) {
		addOneWayEdge(a, b, cost);
		addOneWayEdge(b, a, cost);
	}

	DistType doDijstra(NodeType start, NodeType end) {
		D.clear();
		set< pdti > pq;
		pq.insert(mp(DistType(0), start));
		D[start] = DistType(0);
		while(pq.size()) {
			DIM ( nowDis , pq.begin()->first );
			DIM ( nowId , pq.begin()->second );
			if(!(nowId < end) && !(end < nowId)) return nowDis;
			pq.erase(pq.begin());

			//_(nowId);

			FORstl(it, adj[nowId]) {
				DIM ( edCost , it->first );
				DIM( chId , it->second );
				DIM( it , D.find(chId) );
				bool exists = (it != D.end());
				if(exists && nowDis + edCost >= it->second) continue;

				RDIM(chDis, D[chId]);
				if(exists) { pq.erase(mp(chDis, chId)); }
				chDis = nowDis + edCost;
				pq.insert(mp(chDis, chId));
			}
		}
	}
};

int high[200][200];
int  low[200][200];

struct node {
	int r, c, h;
};
bool operator<(const node& a, const node& b) {
	if(a.r != b.r) return a.r < b.r;
	if(a.c != b.c) return a.c < b.c;
	return a.h < b.h;
}
ostream& operator<<(ostream& o, const node a) {
	return o << '(' << a.r << ' ' << a.c << ' ' << a.h << ')';
}

int ddr[] = { -1 , 1, 0 , 0};
int ddc[] = {  0 , 0, -1, 1};


int main() {
    RFILE("B-small-attempt0.in");
    WFILE("B-small-attempt0.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int numT = II;
    FOR1(cno, numT) {
    	int initWater = II, nRow = II, nCol = II;

    	Dijstra<node, int> dtra;

    	FOR(i, nRow) FOR(j, nCol) { high[i][j] = II; }
    	FOR(i, nRow) FOR(j, nCol) {  low[i][j] = II; }

    	node dest = {nRow, nCol, 0};
    	FOR(nr, nRow) FOR(nc, nCol) {
    		FOR(dd, 4) {
    			int dr = ddr[dd], dc = ddc[dd];
    			int cr = nr + dr; if(!in(0, cr, nRow - 1)) continue;
    			int cc = nc + dc; if(!in(0, cc, nCol - 1)) continue;
    			if(high[cr][cc] < initWater + 50) continue;
    			if(high[cr][cc] < low[nr][nc] + 50) continue;
    			if(high[cr][cc] < low[cr][cc] + 50) continue;
    			if(high[nr][nc] < low[cr][cc] + 50) continue;

    			dtra.addOneWayEdge((node){nr, nc, initWater}, (node){cr, cc, initWater}, 0);
    		}
    		dtra.addOneWayEdge((node){nRow-1, nCol-1, initWater}, dest, 0);
    	}

    	for(int wheight = initWater; wheight >= 0; wheight--) {
			FOR(nr, nRow) FOR(nc, nCol) {
				int cheight = max(wheight - 1, 0);
				dtra.addOneWayEdge((node){nr, nc, wheight}, (node){nr, nc, cheight}, 1);
	    		FOR(dd, 4) {
	    			int dr = ddr[dd], dc = ddc[dd];
					int cr = nr + dr; if(!in(0, cr, nRow - 1)) continue;
					int cc = nc + dc; if(!in(0, cc, nCol - 1)) continue;
					if(high[cr][cc] < wheight + 50) continue;
					if(high[cr][cc] < low[nr][nc] + 50) continue;
					if(high[cr][cc] < low[cr][cc] + 50) continue;
					if(high[nr][nc] < low[cr][cc] + 50) continue;

					int cost;
					if(wheight < low[nr][nc] + 20) cost = 100;
					else cost = 10;
					cheight = max(wheight - cost, 0);
					dtra.addOneWayEdge((node){nr, nc, wheight}, (node){cr, cc, cheight}, cost);
				}
			}
			dtra.addOneWayEdge((node){nRow-1, nCol-1, wheight}, dest, 0);
    	}

    	//_(cno, "SDF");

    	/**
    	FOR(nr, nRow) FOR(nc, nCol) {
    		FORab(dr, -1, 1) FORab(dc, -1, 1) { if(!dr && !dc) continue;
    			int cr = nr + dr; if(!in(0, cr, nRow - 1)) continue;
    			int cc = nc + dc; if(!in(0, cc, nCol - 1)) continue;
    			if(high[cr][cc] < 0 + 50) continue;
    			if(high[cr][cc] < low[nr][nc] + 50) continue;
    			if(high[cr][cc] < low[cr][cc] + 50) continue;
    			if(high[nr][nc] < low[cr][cc] + 50) continue;

    			dtra.addOneWayEdge((node){nr, nc, 0}, (node){cr, cc, 0}, 100);
    		}
    		dtra.addOneWayEdge((node){nRow-1, nCol-1, 0}, dest, 0);
    	}
    	//*/

    	int distance = dtra.doDijstra((node){0, 0, initWater}, dest);

    	printf("Case #%d: %lf\n", cno, distance / 10.0);
    }
    return 0;
}
