#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

const int MAX = 2001;
const int NIL = 0;
const int INF = numeric_limits<int>::max();
int match[MAX], dis[MAX];
vector<int> neigh[MAX];
int n, m;

bool bfs()
{
	int i;
	int v, u;
	queue<int> q;

	for(int i=1; i<=n; ++i){
		if(match[i] == NIL){
			dis[i] = 0;
			q.push(i);
		}
		else
			dis[i] = INF;
	}
	dis[NIL] = INF;
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(dis[v] < dis[NIL]){
			for(i=0; i<neigh[v].size(); ++i){
				u = neigh[v][i];
				if(dis[match[u]] == INF){
					dis[match[u]] = dis[v]+1;
					q.push(match[u]);
				}
			}
		}
	}

	return dis[NIL] != INF;
}

bool dfs(int v)
{
	int i;
	int u;

	if(v != NIL){
		for(i=0; i<neigh[v].size(); ++i){
			u = neigh[v][i];
			if(dis[match[u]] == dis[v]+1){
				if(dfs(match[u])){
					match[u] = v;
					match[v] = u;
					return true;
				}
			}
		}
		dis[v] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp()
{
	int i, matching;
	for(i=0; i<= n+m; ++i){
		match[i] = NIL;
	}
	matching = 0;
	while(bfs()){
		for(i=1; i<=n; ++i)
			if(match[i] == NIL)
				if(dfs(i))
					++matching;

	}
	return matching;
}

int solve_dec(set<double> naomi, set<double> ken)
{
	// Points that have to be lost
	while(!ken.empty() && (*(ken.rbegin()) > *(naomi.rbegin()) || *(naomi.begin()) < *(ken.begin()) ) ){
		ken.erase(*ken.rbegin());
		naomi.erase(*naomi.begin());
	}

	// Find the size of the maximum bipartite matching
	// Souce is 0
	// G1 is 1..n
	// G2 is n+1..2n

	if(ken.empty())
		return 0;

	int i, j;
	n = m = naomi.size();
	for(i=1; i<=n+m; ++i)
		neigh[i].clear();
	i = 0;
	for(auto itr = ken.begin(); itr!=ken.end(); ++itr){
		++i;
		j = n;
		for(auto itr2 = naomi.begin(); itr2!=naomi.end(); ++itr2){
			++j;
			if(*itr < *itr2){
				neigh[i].push_back(j);
				neigh[j].push_back(i);
			}
		}
	}
	return hopcroft_karp();
}

int solve(set<double> naomi, set<double> ken)
{
	int score = 0;
	for(auto itr = naomi.begin(); itr != naomi.end(); ++itr){
		auto candidate = upper_bound(ken.begin(), ken.end(), *itr);
		if(candidate == ken.end()){
			++score;
			ken.erase(*ken.begin());
		}
		else
			ken.erase(upper_bound(ken.begin(), ken.end(), *itr));
	}
	return score;
}

int main(void)
{
	freopen("D-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios_base::sync_with_stdio(false);
	int i, j;

	double x;
	set<double> naomi, ken;
	int t, n;

	cin >> t;
	for(i=1; i<=t; ++i)
	{
		naomi.clear();
		ken.clear();
		cin >> n;
		for(j=1; j<=n; ++j){
			cin >> x;
			naomi.insert(x);
		}
		for(j=1; j<=n; ++j){
			cin >> x;
			ken.insert(x);
		}

		cout << "Case #" << i << ": " << solve_dec(naomi, ken) << " " << solve(naomi, ken) << endl;
	}

	return 0;
} 
