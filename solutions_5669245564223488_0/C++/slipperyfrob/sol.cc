#include <iostream>
#include <cstring>

using namespace std;

#define ZERO(v) memset((v), 0, sizeof((v)))

typedef unsigned long long int ULL;

const size_t MAXN = 100;
const size_t MAXL = 101;
const ULL MOD  = 1000000007;

ULL fact[MAXN+1];
void comp_fact() {
	fact[0] = 1;
	for( ULL i = 1; i <= MAXN; ++i ) {
		fact[i] = i*fact[i-1] % MOD;
	}
}

struct graph {
	size_t edge_mult[26][26];
	size_t degree[26];
	void reset() {
		ZERO(degree); ZERO(edge_mult);
	}
	void add_edge( size_t s, size_t t ) {
		++edge_mult[s][t];
		if( s != t ) ++degree[s];
	}
	size_t dfs_order_r( size_t rt, bool visited[26], size_t order[26], size_t op ) {
		visited[rt] = true;
		for( size_t s = 0; s < 26; ++s ) {
			if( s == rt ) continue;
			if( visited[s] ) continue;
			if( edge_mult[rt][s] == 0 ) continue;
			op = dfs_order_r( s, visited, order, op );
		}
		order[op++] = rt;
		return op;
	}
	void dfs_order( size_t order[26] ) {
		bool visited[26]; ZERO(visited);
		size_t op = 0;
		for( size_t i = 0; i < 26; ++i ) {
			if( visited[i] ) continue;
			op = dfs_order_r(i, visited, order, op);
		}
	}
	ULL do_ct_from( size_t s, bool visited[26] ) {
		visited[s] = true;
		if( degree[s] > 1 ) return 0;
		ULL ret = 1;
		if( degree[s] == 1 ) {
			size_t child = s;
			for( size_t i = 0; i < 26; ++i ) {
				if( i == s ) continue;
				if( edge_mult[s][i] > 0 ) child = i;
			}
			if( child == s ) cerr << "HEY!!" << endl;
			if( edge_mult[s][child] > 1 ) return 0;
			if( visited[child] ) return 0;
			ret *= do_ct_from(child,visited);
		}
		ret = (ret * fact[ edge_mult[s][s] ]) % MOD;
		return ret;
	}
	ULL do_ct( size_t fake_comps ) {
		bool visited[26]; ZERO(visited);
		size_t order[26]; ZERO(order);
		dfs_order(order);
		cerr << "order:";
		for( size_t i = 0; i < 26; ++i ) {
			cerr << " " << order[i];
		}
		cerr << endl;
		ULL ret = 1;
		size_t n_comps = 0;
		for( size_t i = 0; i < 26; ++i ) {
			size_t s = order[25-i];
			if( visited[s] ) continue;
			++n_comps;
			ret = (ret * do_ct_from(s, visited)) % MOD;
		}
		n_comps -= fake_comps;
		ret = (ret * fact[n_comps]) % MOD;
		return ret;
	}
};

char strs[MAXN][MAXL];
size_t str_lens[MAXN];
graph G;

void compress( size_t i ) {
	size_t j = 0;
	strs[i][j++] = strs[i][0];
	for( size_t k = 1; k < str_lens[i]; ++k ) {
		if( strs[i][j-1] == strs[i][k] ) continue;
		strs[i][j++] = strs[i][k];
	}
	strs[i][j] = '\0';
	str_lens[i] = j;
}

int main() {
	comp_fact();
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		cout << "Case #" << Case << ": ";
		ZERO(strs);
		ZERO(str_lens);
		size_t counts[26]; ZERO(counts);
		G.reset();
		bool feasible = true;
		size_t n_incom; cin >> n_incom;
		for( size_t i = 0; i < n_incom; ++i ) {
			cin >> strs[i];
			str_lens[i] = strlen(strs[i]);
			compress(i);
			for( size_t j = 0; j < str_lens[i]; ++j ) {
				++counts[ strs[i][j]-'a' ];
			}
			if( str_lens[i] == 1 ) {
				G.add_edge( strs[i][0]-'a', strs[i][0]-'a' );
			}
			else {
				size_t tmpct[26]; ZERO(tmpct);
				for( size_t j = 0; j < str_lens[i]; ++j ) ++tmpct[ strs[i][j]-'a' ];
				for( size_t c = 0; c < 26; ++c ) {
					if( tmpct[c] > 1 ) {
						cerr << "FEASIBILITY FAIL! (tmpct)" << endl;
						feasible = false;
					}
				}
				for( size_t j = 0; j < str_lens[i]-1; ++j ) {
					G.add_edge( strs[i][j]-'a', strs[i][j+1]-'a' );
				}
			}
		}
		for( size_t i = 0; i < n_incom; ++i ) {
			for( size_t j = 1; j < str_lens[i]-1; ++j ) {
				size_t c = strs[i][j]-'a';
				if( G.edge_mult[c][c] > 0 ) {
					cerr << "FEASIBILITY FAIL! (mult test)" << endl;
					feasible = false;
				}
			}
		}
		if( feasible ) {
			size_t n_bad = 26;
			for( size_t i = 0; i < 26; ++i ) {
				if( counts[i] > 0 ) --n_bad;
			}
			cout << G.do_ct( n_bad ) << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}
