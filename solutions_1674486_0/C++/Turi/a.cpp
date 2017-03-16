#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAXN 1024

typedef struct {
	int n;
	int nsucc[MAXN];
	int succ[MAXN][MAXN];
	int visited[MAXN];
} graph;

graph g;

bool visit(int i){
	if (g.visited[i])
		return true;
	g.visited[i] = 1;
	
	for (int j = 0; j < g.nsucc[i]; j++)
		if (visit(g.succ[i][j]))
			return true;
	return false;
}

int main(int argc, char *argv[]){
	unsigned int T;
	
	if (argc >= 2){
		freopen(argv[1], "r", stdin);
		string outstr(argv[1]);
		int dot_pos = outstr.find_last_of('.');
		outstr = outstr.substr(0, dot_pos) + ".out";
		freopen(outstr.c_str(), "w", stdout);
	}

	cin >> T;
	for (unsigned int k = 0; k < T; k++){
		cin >> g.n;
		for (int i = 0; i < g.n; i++){
			cin >> g.nsucc[i];
			for (int j = 0; j < g.nsucc[i]; j++){
				int t;
				cin >> t; --t;
				g.succ[i][j] = t;
			}
		}
		
		bool result = false;
		for (int i = 0; i < g.n; i++){
			memset(g.visited, 0, sizeof(int) * g.n);
			
			if (visit(i)){
				result = true;
				break;
			}
		}
		
		cout << "Case #" << k + 1 << ": " << (result ? "Yes" : "No") << endl;
	}
	return 0;
}
