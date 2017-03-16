#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

int m, n;
int codes[100];

int mark[100];
int adj[100][100];
int adjs[100];

int adjr[100];

typedef struct edge {
	int a, b;
	
	bool operator<(const edge &e) const {
		return codes[b] > codes[e.b];
	}
} edge;

int cmp(int a, int b){
	return codes[a] < codes[b];
}

pair<bool, vector<int> > solve(int pos, int size, bool first){
	pair<bool,vector<int> > p;
	p.first = false;
	vector<int> ret;	
	
	if(size == 0){
		if(adjr[pos] >= 0){
			int old = adjr[pos];
			adjr[pos] = -1;
			p = solve(old, size, false);
			adjr[pos] = old;
			if(first) p.second.push_back(pos);
			return p;
		} else {
			if(first) ret.push_back(pos);
			for(int i = 0; i < n; i++){
				if(adjr[i] >= 0) return make_pair(false, ret);
			}
			for(int i = 0; i < n; i++){
				if(!mark[i]) return make_pair(false, ret);
			}
			return make_pair(true, ret);
		}
	}
	
	vector<int> next;
	for(int i = 0; i < adjs[pos]; i++){
		if(!mark[adj[pos][i]]){
			next.push_back(adj[pos][i]);
		}
	}
	
	sort(next.begin(), next.end(), cmp);
	
	for(int i = 0; i < next.size() && !p.first; i++){
		mark[next[i]] = true;
		adjr[next[i]] = pos;

		p = solve(next[i], size-1, true);
		if(p.first){
			if(first) p.second.push_back(pos);
		}
		
		adjr[next[i]] = -1;
		mark[next[i]] = false;
	}
	
	pair<bool, vector<int> > p2;
	p2.first = false;
	if(adjr[pos] >= 0){
		int old = adjr[pos];
		adjr[pos] = -1;
		p2 = solve(old, size, false);
		if(p2.first){
			if(first) p2.second.push_back(pos);
		}
		adjr[pos] = old;
	}
	
	if(p.first && p2.first){
		for(int i = p.second.size()-1; i >= 0; i--){
			if(cmp(p.second[i], p2.second[i])){
				return p;
			} else if(cmp(p2.second[i], p.second[i])){
				return p2;
			}
		}
		return p;
	} else if(p.first) {
		return p;
	} else if(p2.first) {
		return p2;
	} else {
		return make_pair(false, ret);
	}
}

int main(){
	int t, count = 1;
	int a, b;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		memset(adjs, 0, sizeof(adjs));
		memset(mark, 0, sizeof(mark));
		
		vector<int> next;
		
		for(int i = 0; i < n; i++){
			cin >> codes[i];
			adjr[i] = -1;
			next.push_back(i);
		}
		
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			adj[a-1][adjs[a-1]++] = b-1;
			adj[b-1][adjs[b-1]++] = a-1;
		}
		
		pair<bool, vector<int> > res;
		sort(next.begin(), next.end(), cmp);
		for(int i = 0; i < next.size(); i++){
			mark[next[i]] = true;
			res = solve(next[i], n-1, true);
			if(res.first) break;
			mark[next[i]] = false;
		}
		
		cout << "Case #" << count++ << ": ";
		for(int i = res.second.size()-1; i >= 0; i--){
			cout << codes[res.second[i]];
		}
		cout << endl;
	}
	
	return 0;
}

