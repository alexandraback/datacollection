#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>
#include <deque>
#include <cassert>
#include <map>
#include <set>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 10005;

const int MIN = 0;
const int MAX = 1;

LL E, R;
int n;
LL v[N];

			#define TESTBIT(b,x) (b[(x)>>3] & (1<<((x)&7)))
			#define SETBIT(b,x) (b[(x)>>3] |= (1<<((x)&7)))
			#define CLEARBIT(b,x) (b[(x)>>3] &= ~(1<<((x)&7)))		


struct graph_t {
	 struct edge_t {
        int to;
        LL cap;
        LL flow;
        LL cost;
        edge_t* rev;
    };
    unsigned char bitset[N/8+2];
    edge_t* dad_link[N];
	vector<edge_t*> list[N];
	LL val[N];
	int n;
	deque<int> d;
	
	void reset( int _n ) {
		n = _n;
		for( int i = 0; i < n; ++i ) {
			for( int j = 0; j <(int)list[i].size(); ++j ) {
				if( list[i][j] ) delete list[i][j];
			}
			list[i].clear();
		}
	}
	
	void edge( int from, int to, LL cap, LL cost ) {
        edge_t *p, *q;
        
		p = new edge_t();
		q = new edge_t();
		
		list[from].push_back(p);
		list[to].push_back(q);
		
        p->to = to;
        p->cap = cap;
        p->flow = 0;
        p->cost = cost;
        p->rev = q;
        
        q->to = from;
        q->cap = cap;
        q->cost = -cost;
        q->flow = cap;
        q->rev = p;		
	}
	
	LL update_network( int from, int to, LL add_flow ) {
		int b = to;
		LL delta = 0;

		do {
			dad_link[b]->flow += add_flow;
			dad_link[b]->rev->flow -= add_flow;
			delta += dad_link[b]->cost * add_flow;
			b = dad_link[b]->rev->to;
		} while( b != from );
		
		return delta;
	}
	LL determine_pushthrough( int from, int to ) {
		LL pt = LLONG_MAX;
        int b = to;
        
		do {
			pt = min( pt, dad_link[b]->cap - dad_link[b]->flow );
			b = dad_link[b]->rev->to;
		} while( b != from );

		return pt;
	}	
	
	LL cost( int a, int b ) {
		LL r = 0;
		int k, cnt;
		
		while(1) {
				for( int i = 0; i < n; ++i ) {
					val[i] = LLONG_MIN;
				}			
		
			val[a] = 0;
			d.clear();
			d.push_back( a );
			d.push_back( -1 );
			
			memset( bitset, 0, sizeof(unsigned char)*(n/8+1) );
			SETBIT( bitset, a );
			
			cnt = 0;
			do {
				k = d.front(); d.pop_front();
				
				if( k == -1 ) {
					if( ++cnt == n-1 ) break;
					d.push_back( -1 );
				} else {
					CLEARBIT( bitset, k );
						for( int i = 0; i < (int)list[k].size(); ++i ) {						
							if( list[k][i]->flow < list[k][i]->cap && val[list[k][i]->to] < val[k] + list[k][i]->cost ) {
								val[list[k][i]->to] = val[k] + list[k][i]->cost;
								dad_link[list[k][i]->to] = list[k][i];
								if( !TESTBIT( bitset, list[k][i]->to ) ) {
									SETBIT( bitset, list[k][i]->to );
									d.push_back( list[k][i]->to );
								}
							}
						}
				}
			} while( d.size() > 1 );
			
			if( val[b] == LLONG_MIN ) break;
			r += update_network( a, b, determine_pushthrough( a, b ) );
		}
		return r;
	}
};


int main() {
	int cases;
	int n;
	
	graph_t* g = new graph_t();
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cin >> E >> R >> n;
		assert( 1 <= n && n <= 10000 );
		for( int i = 0; i < n; ++i ) {
			cin >> v[i];
		}
		if( R > E ) R = E;
		
		g->reset(n+2);
		int S = n;
		int T = S+1;
		
		for( int i = 0; i < n; ++i ) {
			g->edge( S, i, (i==0?E:R), 0 );
			g->edge( i, T, E, v[i] );
			if( i < n-1 ) {
				g->edge( i, i+1, E-R, 0 );
			}
		}
		
		LL res = g->cost( S, T );
		cout << "Case #" << caseid << ": " << res << endl;
	}
	return 0;
}

