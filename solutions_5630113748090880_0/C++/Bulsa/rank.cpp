#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cassert>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

static int grid[50][50];
static int N;
vector<vector<int>> lines;
static int sr;

static unique_ptr<vector<int>> pick(int idx, int ri, int ci) {
	if(idx == lines.size()) {
		int unused = sr;
		if(unused == -1) {
			if(ri == N) return nullptr;
			unused = ri;
		}
		FOR(i,1,N) FOR(j,0,N)
			if(grid[i][j] <= grid[i-1][j] || grid[j][i] <= grid[j][i-1])
				return nullptr;
		auto res = make_unique<vector<int>>(N);
		FOR(i,0,N) {
			res->at(i) = grid[unused][i];
		}
		return res;
	}
	bool r = ri != N;
	if(r) FOR(i,0,N) {
		if(grid[ri][i] && grid[ri][i] != lines[idx][i])
			r = false;
		if(ri && grid[ri-1][i] && grid[ri-1][i] >= lines[idx][i])
			r = false;
		if(ri > 1 && sr == ri-1 && grid[ri-2][i] && grid[ri-2][i] >= lines[idx][i])
			r = false;
	}
	if(r) {
		vector<bool> picked(N);
		FOR(i,0,N) {
			picked[i] = grid[ri][i];
			grid[ri][i] = lines[idx][i];
		}
		auto res = pick(idx+1, ri+1, ci);
		if(res) return res;
		FOR(i,0,N)
			if(!picked[i])
				grid[ri][i] = 0;
	}
	bool c = ci != N;
	if(c) FOR(i,0,N) {
		if(grid[i][ci] && grid[i][ci] != lines[idx][i])
			c = false;
		if(ci && grid[i][ci-1] && grid[i][ci-1] >= lines[idx][i])
			c = false;
	}
	if(c) {
		vector<bool> picked(N);
		FOR(i,0,N) {
			picked[i] = grid[i][ci];
			grid[i][ci] = lines[idx][i];
		}
		auto res = pick(idx+1, ri, ci+1);
		if(res) return res;
		FOR(i,0,N)
			if(!picked[i])
				grid[i][ci] = 0;
	}
	if(sr == -1 && ri != N) {
		sr = ri;
		auto res = pick(idx, ri+1, ci);
		if(res) return res;
		sr = -1;
	}
	return nullptr;
}

int main() {
    ll T; cin >> T;
    FOR(t,0,T) {
        cout << "Case #" << t+1 << ":";
		cin >> N;
		lines.clear();
		sr = -1;
		FOR(i,0,N) FOR(j,0,N)
			grid[i][j] = 0;

		lines.resize(2*N-1);
		for(auto& l : lines) {
			l.resize(N);
			for(auto& x : l)
				cin >> x;
		}
		sort(begin(lines),end(lines));

		auto res = *pick(0,0,0);
		for(int x : res)
			cout << ' ' << x;

		cout << endl;
    }
}
