#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cassert>

#define SHOW(...) {;}
#define REACH_HERE {;}
#define PRINT(s, ...) {;}
#define PRINTLN(s, ...) {;}

// #undef HHHDEBUG
#ifdef HHHDEBUG
#include "template.h"
#endif

using namespace std;

template<typename T>
using Grid = vector<vector<T>>;

const double E = 1e-8;
const double PI = acos(-1);

struct Network {
    struct Edge {
        int to;
        int pre_edge;
        int cap;
        int flow;
    };

    #define MAXNODE 2005
    int last[MAXNODE];

    int nv; // total number of vertex, index range: [0, nv)
    vector<Edge> edge;
    void init(int _nv) {
        nv = _nv;
        edge.clear();
        fill(last, last + nv, -1);
    }

    void add_e(int x, int y, int cap, int r_cap = 0) {
        Edge e = {y, last[x], cap, 0};
        // Edge e{y, last[x], cap, 0};
        last[x] = edge.size();
        // edge.push_back(move(e));
        edge.push_back(e);

        Edge r_e = {x, last[y], r_cap, 0};
        // Edge r_e{x, last[y], r_cap, 0};
        last[y] = edge.size();
        // edge.push_back(move(r_e));
        edge.push_back(r_e);
    }
    void show_edge() {
        for (int i = 0; i < nv; i++) {
            printf("v [%d]:", i);
            for (int ie = last[i]; ie != -1; ) {
                const Edge& e = edge[ie]; 
                ie = e.pre_edge;
                printf(" [%d]%d/%d", e.to, e.flow, e.cap);
            }
            printf("\n");
        }
        printf("\n");
    }

    // 
    // bipartite match
    // O(V * E)
    int peer[MAXNODE];
    bool went[MAXNODE];
    int bipartite_match() {
        fill(peer, peer + nv, -1);
        int ans = 0;
        for (int i = 0; i < nv; i++) {
            if (last[i] == -1 || peer[i] != -1)
                continue;
            fill(went, went + nv, false);
            if (match(i))
                ans++;
        }
        return ans;
    }
    bool match(int cur) {
        for (int ie = last[cur]; ie != -1; ) {
            const Edge& e = edge[ie];
            ie = e.pre_edge;
            int to = e.to;
            if (went[to])
                continue;
            went[to] = true;
            if (peer[to] == -1 || match(peer[to])) {
                peer[to] = cur;
                peer[cur] = to;
                return true;
            }
        }
        return false;
    }
    void show_peer() {
        for (int i = 0; i < nv; i++)
            printf("%d peer-> %d\n", i, peer[i]);
    }
    // end of 
    // bipartite match
    // 
};

Network network;

void sol() {
	int n;
	cin >> n;
	vector<string> sa(n);
	vector<int> ia(n);
	vector<string> sb(n);
	vector<int> ib(n);
	map<string, int> index;
	string padding = "AAAAAAAAAAAAAAAAAAAAA";
	for (int i = 0; i < n; i++) {
		cin >> sa[i] >> sb[i];
		if (index.find(sa[i]) == end(index)) {
			index[sa[i]] = index.size();
		}
		ia[i] = index[sa[i]];
		if (index.find(sb[i] + padding) == end(index)) {
			index[sb[i] + padding] = index.size();
		}
		ib[i] = index[sb[i] + padding];
		SHOW(sa[i], ia[i], sb[i], ib[i])
		network.add_e(ia[i], ib[i], 1);
	}

	network.init(index.size());
	for (int i = 0; i < n; i++) {
		network.add_e(ia[i], ib[i], 1);
	}

	int matching = network.bipartite_match();
	SHOW(matching)

	int small = index.size() - matching;
	int ans = n - small;
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

   int nc;
    cin >> nc;
    for (int i = 1; i <= nc; i++) {
    	printf("Case #%d: ", i);
    	sol();
    }

}





