#include <bits/stdc++.h>
using namespace std;

int N;
bool valid(int ind, int s, int o, vector<vector<int> > &lists, vector<vector<int> > &M) {
	vector<int> &L = lists[ind];
	if(s == 0) return true;
	if(o == 0) {
		for(int i = 0; i < N; i++) {
			if(M[s][i] != -1 && M[s][i] != L[i]) return false;
			if(M[s-1][i] >= L[i]) return false;
		}
	}
	if(o == 1) {
		for(int i = 0; i < N; i++) {
			if(M[i][s] != -1 && M[i][s] != L[i]) return false;
			if(M[i][s-1] >= L[i]) return false;
		}
	}
	return true;
}

void insert(int ind, int s, int o, vector<vector<int> > &lists, vector<vector<int> > &M) {

	vector<int> &L = lists[ind];
	if(o == 0) {
		for(int i = 0; i < N; i++) {
			M[s][i] = L[i];
		}
	}
	if(o == 1) {
		for(int i = 0; i < N; i++) {
			M[i][s] = L[i];
		}
	}
}

void code() {
	cin >> N;

	map<int,int> count;
	for(int i = 0; i < 2 * N - 1; i++) {
		for(int j = 0; j < N; j++) {
			int v;
			cin >> v;
			count[v]++;
		}
	}

	vector<int> L;
	for(auto it = count.begin(); it != count.end(); it++) {
		if(it->second % 2 == 1) L.push_back(it->first);
	}
	sort(L.begin(), L.end());
	for(int i = 0; i < N; i++) {
		cout << " " << L[i];
	}
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":";
		code();
		cout << endl;
	}
}
