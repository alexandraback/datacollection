#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <bitset>
#include <list>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define bitcnt(x) __builtin_popcountll(x)
#define rt return

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = (int)1e9 + 37;
const ld PI = acos(-1.0);
const int MAXN = 5115;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};

int n, m;

int get(int v, vector <vector <int> >&g, vector <int>& dist, vector <bool>& used){
	//cout << v << endl;
	if (used[v] == 1){
		return dist[v];
		
	} else {
		int ret = 0;
		for (int i=0;i<n;i++){
			//cout << "opa" << endl;
			if (g[i][v] == 1){
				ret += get(i, g, dist, used);
			}
			dist[v] = ret;
			used[v] = 1;
		}
		return ret;
	}
}

int countWays(vector <vector <int> >&g, vector <int>& dist, vector <bool>& used){
	dist[0] = 1;
	used[0] = 1;
	int ret = get(n - 1, g, dist, used);
	return ret;
}

void print(vector <vector <int> >&g){
	printf("NEW GRAPH\n");
	for (int i=0;i<(int)g.size();i++){
		for (int j=0;j<(int)g[i].size();j++){
			printf("%d", g[i][j]);
		}
		printf("\n");
	}
}

bool dfs(int v, vector <vector <int> >& g, vector <int>& colour){
	colour[v] = 1;
	for (int i=0;i<n;i++){
		if (g[v][i] == 1){
			if (colour[g[v][i]] == 0){
				return dfs(g[v][i], g, colour);
			} else if (colour[g[v][i]] == 1){
				return 1;
			}
		}
	}
	colour[v] = 2;
	return 0;
}	

bool hasCycle(vector <vector <int> >& g, vector <int>& colour){
	return dfs(0, g, colour);
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test = 1; Test <= T; Test++){
		cin >> n >> m;
		vector <vector <int> > g(n, vector <int> (n, 0));
		vector <int> buf;
		bool ok = 0;
		for (int i=0;i<(1 << sqr(n - 1));i++){
			buf.clear();	
			for (int j=0;j<sqr(n - 1);j++){
				buf.pb((i >> j) & 1);		
			}
			int tmp = 0;
			for (int ii=0;ii<n-1;ii++){
				for (int j=0;j<n;j++){
					if (ii == j){
						continue;
					} else {
						g[ii][j] = buf[tmp++]; 
					}				
				}
			}

			//print(g);
			vector <int> colour(n, 0);
			if (hasCycle(g, colour)){
				continue;
			}
						
			vector <int> dist(n, 0);
			vector <bool> used(n, false);
			tmp = countWays(g, dist, used);
			if (tmp == m){
				ok = 1;
				break;
			}	
		}
		
		
		
					
		printf("Case #%d: ", Test);
		if (!ok){
			printf("IMPOSSIBLE\n");
		} else {
			printf("POSSIBLE\n");
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					cout << g[i][j];
				}
				cout << endl;
			}
		}
	}
	
	
    rt 0;
}
