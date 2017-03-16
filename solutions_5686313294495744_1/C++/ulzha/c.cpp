#include <iostream>
#include <string>
#include <map>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS> babble;

const int nmax = 1000;
string a[nmax], b[nmax];

int main() {
	int nt, it;

	cin >> nt;
	for (it = 0; it < nt; it++) {
		int n, i;
		map<string, int> mv;
		int nv = 0;

		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			a[i] += '0', b[i] += '1';
			if (mv.find(a[i]) == mv.end()) mv[a[i]] = nv++;
			if (mv.find(b[i]) == mv.end()) mv[b[i]] = nv++;
		}

		babble g(nv);

		for (i = 0; i < n; i++) {
			add_edge(mv[a[i]], mv[b[i]], g);
		}

		std::vector<graph_traits<babble>::vertex_descriptor> m(nv);

		edmonds_maximum_cardinality_matching(g, &m[0]);

		int r = n - matching_size(g, &m[0]);
		graph_traits<babble>::vertex_iterator vi, vi_end;

		for (tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
			if (m[*vi] == graph_traits<babble>::null_vertex()) r--;
		}

		cout << "Case #" << it + 1 << ": " << r << endl;
	}
}
