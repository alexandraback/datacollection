#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
using namespace std;

namespace {
	using Integer = long long; //__int128;
	template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
	template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
	template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(int i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
	template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

	template<class H> void print(const H& head){ cout << head; }
	template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
	template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

	template<class H> void eprint(const H& head){ cerr << head; }
	template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; print(tail...); }
	template<class ... T> void eprintln(const T& ... values){ print(values...); cerr << endl; }

	string operator "" _s (const char* str, size_t size){ return move(string(str)); }
	constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
	constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
	constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

	inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

	mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

	template<class T> string join(const vector<T>& v, const string& sep){
		stringstream ss; for(int i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str();
	}
}

constexpr long long mod = 9_ten + 7;


class SCC{
public:
	int n;
	vector<vector<int> > G;
	vector<vector<int> > rG;

private:
	void dfs(vector<bool> &visit, int pos, vector<int> &result){
		visit[pos] = true;
		for(int i=0; i<G[pos].size(); i++){
			if(visit[ G[pos][i] ]) continue;
			dfs(visit, G[pos][i], result);
		}
		result.push_back(pos);
	}

	void rdfs(vector<bool> &visit, int pos, int k){
		visit[pos] = true;
		component[pos] = k;
		for(int i=0; i<rG[pos].size(); i++){
			if(visit[ rG[pos][i] ]) continue;
			rdfs(visit, rG[pos][i], k);
		}
	}

	void make_rev(vector<vector<int> > &G){
		for(int i=0; i<n; i++){
			for(int j=0; j<G[i].size(); j++){
				rG[ G[i][j] ].push_back(i);
			}
		}
	}

public:
	int num_components;
	vector<int> component;
	vector< vector<int> > scc_graph;
	
	SCC(int n){
		this->n = n;
		G.resize(n);
		rG.resize(n);
	}

	SCC(vector<vector<int> > &G){
		this->n = G.size();
		this->G = G;
		rG.resize(n);
		make_rev(G);
	}
	
	void strongly_connected_components(){
		vector<bool> visit(n, false);
		vector<int> result;

		for(int i=0; i<n; i++){
			if(visit[i]) continue;
			dfs(visit, i, result);
		}

		
		component.resize(n);
		fill(visit.begin(), visit.end(), false);
		int k=0;
		for(int i=result.size()-1; i>=0; i--){
			if(visit[ result[i] ]) continue;
			rdfs(visit, result[i], k);
			k++;
		}

		num_components = k;
		scc_graph.resize( num_components );
		for(int i=0; i<n; i++){
			int cmp = component[i];
			for(int j=0; j<G[i].size(); j++){
				if(component[ G[i][j] ] == cmp) continue;
				scc_graph[cmp].push_back( component[ G[i][j] ] );
			}
		}
		
		for(int i=0; i<scc_graph.size(); i++){
			sort(scc_graph[i].begin(), scc_graph[i].end());
			scc_graph[i].erase( unique(scc_graph[i].begin(), scc_graph[i].end()), scc_graph[i].end());
		}
		
	}
	
	void add_edge(int from, int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}
};


void solver(int test_number){
	int n;
	cin >> n;
	vector<int> v(n);
	cin >> v;
	for(int& x: v) x--;

	SCC g(n);
	for(int i=0; i<n; i++){
		g.add_edge(i, v[i]);
	}
	g.strongly_connected_components();

	vector<int> dp(n, -1);
	vector<int> c_sz(g.num_components, 0);
	vector<int> ord(n, -1);
	for(int i=0; i<n; i++){
		c_sz[g.component[i]]++;
	}
	for(int i=0; i<n; i++){
		if(c_sz[g.component[i]] > 1 && ord[i] == -1){
			function<void(int,int)> dfs = [&](int pos, int cnt){
				if(ord[pos] != -1) return;
				ord[pos] = cnt;
				for(int next : g.G[pos]){
					dfs(next, cnt+1);
				}
			};
			dfs(i, 0);
		}
	}

	int ans   = *max_element(c_sz.begin(), c_sz.end());
	int merge = 0;
	vector<int> used(g.num_components, 0);

	function<int(int)> dfs = [&](int pos){
		if(dp[pos] != -1) return dp[pos];
		priority_queue<int, vector<int>, less<int>> pq;

		pq.push(0);
		pq.push(0);

		for(int next : g.rG[pos]){
			if(g.component[pos] == g.component[next]) continue;
			pq.push(dfs(next));
		}
		dp[pos] = pq.top() + 1;
		pq.pop();

		return dp[pos];
	};

	for(int i=0; i<n; i++){
		dfs(i);
		for(int j=i+1; j<n; j++){
			if(g.component[i] == g.component[j]){
				int tmp_ij = (ord[j] - ord[i] + c_sz[g.component[i]]) % c_sz[g.component[i]] + 1;
				int tmp_ji = (ord[i] - ord[j] + c_sz[g.component[i]]) % c_sz[g.component[i]] + 1;

				if(tmp_ij == 2 && tmp_ji == 2){
					int leg = dfs(i) + dfs(j) - 2;

					ans = max({ans, leg + tmp_ij, leg + tmp_ji});

					if(used[g.component[i]] == 0){
						merge += dfs(i)+dfs(j);
						used[g.component[i]] = 1;
					}
				}

			}
		}
	}

	ans = max(ans, merge);

	printf("Case #%d: ", test_number);
	println(ans);
}


int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		solver(i+1);
	}
	
	return 0;
}
