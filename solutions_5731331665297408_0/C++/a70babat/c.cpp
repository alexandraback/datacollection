//be name oo
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>
#include <queue>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "#" << #x << ": " << x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 50 + 10;

int n;
bool adj[MAX_N][MAX_N];
int zipcode[MAX_N];
int mark1[MAX_N];

void find_best(int par, int par_index, int& best, int& best_zip_code, int& best_par_index){
	FOR(i, n)
		if(mark1[i] == 0 && adj[par][i])
			if(best == -1 || zipcode[i] < best_zip_code){
				best = i;
				best_zip_code = zipcode[i];
				best_par_index = par_index;
			}
}

bool mark2[MAX_N];

int dfs(int v){
	if(mark1[v] == 2)
		return 0;
	mark2[v] = true;
	int ret = 1;
	FOR(i, n)
		if(mark1[i] != 2 && !mark2[i] && adj[v][i])
			ret += dfs(i);
	return ret;
}

int main(){
	int num_test_case;
	cin >> num_test_case;
	for(int _test = 1; _test <= num_test_case; _test++){
		cout << "Case #" << _test << ": ";
		memset(adj, 0, sizeof adj);
		memset(mark1, 0, sizeof mark1);
		int m;
		cin >> n >> m;
		FOR(i, n)
			cin >> zipcode[i];
		FOR(i, m){
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			adj[a][b] = adj[b][a] = 1;
		}
		vector<int> stack;
		stringstream ss;

		int start = min_element(zipcode, zipcode + n) - zipcode;
		ss << zipcode[start];
		stack.PB(start);
		mark1[start] = 1;

		FOR(i, n - 1){
			int best = -1;
			int best_zip_code = -1;
			int best_par_index = -1;
			for(int i = SZ(stack) - 1; i >= 0; i--){
				find_best(stack[i], i, best, best_zip_code, best_par_index);
				mark1[stack[i]] = 2;
				memset(mark2, 0, sizeof mark2);
				int visited = dfs(stack[0]);
				FOR(i, n)
					if(mark1[i] != 2)
						visited--;
				if(visited != 0)
					break;
			}
			while(SZ(stack) > best_par_index + 1)
				stack.pop_back();
			FOR(i, SZ(stack))
				mark1[stack[i]] = 1;
			ss << best_zip_code;
			stack.PB(best);
			mark1[best] = 1;
		}
		string ans;
		ss >> ans;
		cout << ans << endl;
	}
	return 0;
}

