#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std; 
int G[1001][1001];
int mark[1001];
int T, N;
bool dfs(int u) {
	//cout << "dfs(" << u << ")" << endl;
	if (mark[u] == 2) {
		//cout << u << " is already visited: return true " << endl;
		return true;
	}
	mark[u] = 1;

	for (int v = 1; v <= N; v++) {
		if (mark[v] != 1 && G[u][v] != -1) {
			if (dfs(v)) return true;
		}
	}
	mark[u] = 2;
	//cout << "return: false" << endl;
	return false;
};

bool solve() {
	for (int u = 1; u <= N; u++) {
		//cout << "start point: " << u << endl;
		for (int i = 1; i <= N; i++) {
			mark[i] = 0;
		}
		if (dfs(u)) return true;
	}
	return false;
};
int main(int argc, char** argv) {
	ifstream inF(argv[1]);
	string line;
	getline(inF, line);
	T = atoi(line.c_str());
	for (int t = 0; t < T; t++) {
		memset(G, -1, sizeof(G));
		getline(inF, line);
		N = atoi(line.c_str());
		for (int k = 0; k < N; k++) {
			getline(inF, line);
			stringstream ss;
			ss << line;
			int mi;
			ss >> mi;
			for (int p = 0; p < mi; p++) {
				int tmp;
				ss >> tmp;
				G[k+1][tmp] = 1;
			}
		}
		cout << "Case #" << t+1 << ": ";
		if (solve()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	inF.close();
};
