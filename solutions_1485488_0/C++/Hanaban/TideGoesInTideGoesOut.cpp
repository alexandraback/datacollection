#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class pos {
	public:
		int t;
		int x, y;
		
};

bool operator<(const pos &l, const pos &r) {
	if (l.t == r.t) return (l.x < r.x) || (l.y < r.y);
	return l.t < r.t;
}

double solve(int case_no)
{
	int H;
	int N, M;
	cin >> H >> N >> M;
	
	vector<vector<int> > C(N, vector<int> (M) );
	vector<vector<int> > F(N, vector<int> (M) );
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> F[i][j];
		}
	}
	
	set<pos> pq;
	stack<pos> st;
	pos p, n;
	p.t = 0;
	p.x = 0;
	p.y = 0;
	st.push(p);
	int D[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	int pf, pc, nf, nc;
	
	vector<vector<int> > V(N, vector<int> (M, 0) );
	while (!st.empty() ) {
		p = st.top();
		st.pop();
		if (V[p.y][p.x]) continue;
		V[p.y][p.x] = 1;
		pq.insert(p);
		
		pf = max(F[p.y][p.x], H - p.t);
		pc = C[p.y][p.x];
		
		if (p.y == N - 1 && p.x == M - 1) return 0;
		for (int i = 0; i < 4; ++i) {
			n.x = p.x + D[i][0];
			n.y = p.y + D[i][1];
			if (n.x < 0 || n.x >= M || n.y < 0 || n.y >= N) continue;
			nf = max(F[n.y][n.x], H - p.t);
			nc = C[n.y][n.x];
			if (min(pc, nc) - max(pf, nf) < 50) continue;
			n.t = 0;
			st.push(n);
		}
	}
	
	while (!pq.empty() ) {
		p = *pq.begin();
		pq.erase(pq.begin() );
		pf = max(F[p.y][p.x], H - p.t);
		pc = C[p.y][p.x];
		
		if (p.y == N - 1 && p.x == M - 1) return p.t / 10.0f;
		for (int i = 0; i < 4; ++i) {
			n.x = p.x + D[i][0];
			n.y = p.y + D[i][1];
			if (n.x < 0 || n.x >= M || n.y < 0 || n.y >= N) continue;
			nf = max(F[n.y][n.x], H - p.t);
			nc = C[n.y][n.x];
			if (min(pc, nc) - max(pf, nf) < 50) continue;
			if (H - p.t >= F[p.y][p.x] + 20) n.t = p.t + 10;
			else n.t = p.t + 100;
			pq.insert(n);
		}
		++p.t;
		pq.insert(p);
	}
		
	return 0;
	
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: %f\n", i, solve(i) );
	}
	
	return 0;
}
