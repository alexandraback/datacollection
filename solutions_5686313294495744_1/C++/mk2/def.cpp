#include <bits/stdc++.h>
using namespace std;
#define M_PI        3.14159265358979323846

typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;
/*
num 0 : got 0 chain 0 0
0 -1 -1 -1 -1 -1 -1 pairs
num 1 : got 1 chain 1 1
0 1 -1 -1 -1 -1 -1 pairs
num 2 : got 2 chain 3 2
0 1 -1 2 -1 -1 -1 pairs
num 3 : got 3 got 0 chain 4 0 0 3
3 1 -1 2 0 -1 -1 pairs
num 4 : got 4 got 1 chain 2 1 1 4
3 4 1 2 0 -1 -1 pairs
num 5 : got 5 chain 6 5
3 4 1 2 0 -1 5 pairs
num 6 : got 6 got 0 got 3 got 2  fsl chain 5 3 0 0 7 6
0 4 1 2 0 3 5 pairs

2: 0 4
2: 1 2
2: 3 0
4: 0 3 5 8
2: 1 2
1: 6
1: 7
*/

vector<vector<int>> edge;

int n3, k3;

int pairs[2000];
bool used[2000];

bool find_chain(int v){
	if(used[v]) return false;
	used[v] = true;
	for(auto x : edge[v]){
		if(pairs[x] == -1){
			pairs[x] = v;
			return true;
		} else {
			if(find_chain(pairs[x])){
				pairs[x] = v;
				return true;
			}
		}
	}
	return false;
}

int solve3(vector<pair<string, string>> vs){
	int n;
	n = vs.size();
	edge.clear();
	edge.assign(n, vector<int>());
	map<string, int> mapper[2];
	mapper[0].clear();
	mapper[1].clear();
	string a[2];
	for(int i = 0; i < n; i++){
		a[0] = vs[i].first;
		a[1] = vs[i].second;
		int rs[2];
		for(int j = 0; j < 2; j++){
			auto it = mapper[j].find(a[j]);
			if(it == mapper[j].end()){
				it = mapper[j].insert({a[j], (int)mapper[j].size()}).first;
			}
			rs[j] = it->second;
		}
		edge[rs[0]].push_back(rs[1]);
	}
	n3 = mapper[0].size();
	k3 = mapper[1].size();
	fill(pairs, pairs + k3, -1);
	edge.resize(n3);
	int pr = 0;
	for(int i = 0; i < n3; i++){
		fill(used, used + n3, false);
		pr += (int)find_chain(i);
	}
	return n - (n3 + k3 - pr);
}

int solve3_slow(vector<pair<string, string>> vs){
	int n;
	n = vs.size();
	int minans = n;
	int truemask = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		int cans = 0;
		set<string> fi, se;
		for(int i = 0; i < n; i++){
			if((mask & (1 << i)) != 0){
				fi.insert(vs[i].first);
				se.insert(vs[i].second);
				cans++;
			}
		}
		/*
		  	2: 0 4
			2: 1 2
			2: 3 0
			4: 0 3 5 8
			2: 1 2
			1: 6
			1: 7
			0 4 1 2 0 3 5
			15693
		 */
		for(int i = 0; i < n; i++){
			if((mask & (1 << i)) == 0){
				int cn = fi.count(vs[i].first);
				cn += se.count(vs[i].second);
				if(cn < 2){
					cans = INF;
					break;
				}
			}
		}
		if(cans < minans){
			truemask = mask;
			minans = cans;
		}
	}
	for(int i = 0; i < n; i++){
		cerr << (truemask & 1);
		truemask >>= 1;
	}
//	cerr << truemask << "\n";
	return n - minans;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("nextpartition.in", "r", stdin);
//    freopen("nextpartition.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cout << "Case #" << i << ": ";
    	int n;
    	cin >> n;
    	vector<pair<string, string> > vs(n);
    	for(int i = 0; i < n; i++){
    		cin >> vs[i].first >> vs[i].second;
    	}
    	int ress = solve3(vs);
    	cout << ress << "\n";
    }
    return 0;
}
