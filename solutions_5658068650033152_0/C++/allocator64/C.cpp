#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const uint64_t mod = 1000000007;

int N, M, K;


uint32_t bitcnt(uint32_t x) {
	uint32_t res = 0;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int cnv(int i, int j) {
	return i * M + j;
}

bool exist(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void bfs(uint32_t stone, uint32_t &visited, int i, int j) {
	static const vector<int> di = {0, 0, 1, -1};
	static const vector<int> dj = {1, -1, 0, 0};
	if ((stone >> cnv(i, j)) & 1)
		return;
	visited |= (1u << cnv(i, j));
	queue<int> Q;
	Q.push(cnv(i, j));
	while (!Q.empty()) {
		i = Q.front() / M;
		j = Q.front() % M;
		Q.pop();
		for (int k = 0; k < 4; ++k) {
			int I = i + di[k];
			int J = j + dj[k];
			if (exist(I, J) && !((stone >> cnv(I, J)) & 1) && !((visited >> cnv(I, J)) & 1)) {
				visited |= (1u << cnv(I, J));
				Q.push(cnv(I, J));
			}
		}
	}
	return;
}

int check(uint32_t stone, int before) {
	uint32_t visited = 0;
	for (int i = 0; i < N; ++i) {
		bfs(stone, visited, i, 0);
		bfs(stone, visited, i, M - 1);
	}
	for (int j = 0; j < M; ++j) {
		bfs(stone, visited, 0, j);
		bfs(stone, visited, N - 1, j);
	}
	return N*M - bitcnt(visited);
}

string bitout(uint32_t mask) {
	string s;
	for (int i = 0; i < 32; ++i)
		s += '0' + ((mask >> i) & 1);
	return s;
}

int main()
{
	int T;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		cerr << "Case #" << test + 1 << endl;
		cin >> N >> M >> K;
		int ans = N*M;
		for (uint32_t mask = 0; mask < (1u << N*M); ++mask) {
			int bcnt = bitcnt(mask);
			if (bcnt >= ans)
				continue;
			int t = check(mask, bcnt);
			if (t >= K) {
				ans = bcnt;
				// cout << "bestmask:\n";
				// string s = bitout(mask);
				// for (int i = 0; i < N; ++i) {
				// 	for (int j = 0; j < M; ++j)
				// 		cout << s[i*M + j];
				// 	cout << endl;
				// }
				// cout << endl;
			}
		}

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}