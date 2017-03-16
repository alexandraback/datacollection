#include <iostream>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

int N, M, K, R;
int prod[20];

struct state {
	vector<int> v, prods;
	bool operator<(const state& other) const {
		for (int i = 0; i < N; i++)
			if (v[i] != other.v[i])
				return v[i] < other.v[i];
		return true;
	}
	friend ostream& operator<<(ostream& os, const state& s) {
		for (int i = 0; i < N; i++)
			os << s.v[i];
		return os;
	}
	int chance() {
		int ret = 1.0;
		for (int i = 0; i < K; i++) {
			int tel = 0;
			for (int j = 0; j < (1 << N); j++) {
				if (prods[j] == prod[i]) tel++;
			}
			ret *= tel;
		}
		return ret;
	}
};

vector<state> states;
vector<int> curr;

void process() {
	state s = (state) {curr, vector<int>()};
	for (int bitset = 0; bitset < (1 << N); bitset++) {
		int prd = 1;
		for (int i = 0; i < N; i++) {
			if (bitset & (1 << i))
				prd *= curr[i];
		}
		s.prods.push_back(prd);
	}
	states.push_back(s);
}

void dfs(int d) {
	if (d == N) {
		process();
		return;
	}
	for (int i = 2; i <= M; i++) {
		curr.push_back(i);
		dfs(d + 1);
		curr.pop_back();
	}
}

void solve(int casenum) {
	cout << "Case #" << casenum << ":" << endl;
	cin >> R >> N >> M >> K;
	/*assert(R == 100);
	assert(N == 3);
	assert(M == 5);
	assert(K == 7);*/
	dfs(0);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			cin >> prod[j];
		}
		state argBest;
		int best = -1;
		for (vector<state>::iterator it = states.begin(); it != states.end(); it++) {
			//cerr << "state " << *it << ": " << it->chance() << endl;
			int deze = it->chance();
			if (deze > best) {
				argBest = *it;
				best = deze;
			}
		}
		//cerr << endl;
		cout << argBest << endl;
	}
}

int main() {
	int T;
	cin >> T;
	assert(T == 1);
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
