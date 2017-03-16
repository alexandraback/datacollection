#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
#define sz(a) (int)a.size()
#define pb push_back
const int MAXN = 2 * 1000 * 1000 + 500;
const double EPS = 1e-9;
typedef long long LL;
int n, b;
int D[55];

vector<vector<char> > good_mask;
int dfs(int v, vector<vector<char> > &g){
	if (D[v] != -1) return D[v];
	if (v == n - 1) return 1;
	int result = 0;
	for (int i = 0; i < g[v].size(); ++i){
		int to = g[v][i];
		if (D[to] == -1){
			D[to] = dfs(to, g);
		}

		result += D[to];
	}

	return D[v] = result;
}

int rec(vector<vector<char> > &mask, int pos){
	if (pos == n){
		if (mask[0][0] == 1 && mask[0][1] == 0 && mask[0][2] == 1 && mask[0][3] == 0 && mask[0][4] == 1
			&& mask[1][0] == 1 && mask[1][1] == 0 && mask[1][2] == 0 && mask[1][3] == 1
			&& mask[2][0] == 1 && mask[2][1] == 0 && mask[2][2] == 1
			&& mask[3][0] == 1 && mask[3][1] == 1
			&& mask[4][0] == 1){
			int tmp = 2;
		}
		vector<vector<char> > g(n);
		for (int i = 0; i < n - 1; ++i){
			for (int j = 0; j < mask[i].size(); ++j){
				if (mask[i][j]){
					g[i].push_back(i + j + 1);
				}
			}
		}

		mems(D, -1);
		int result = dfs(0, g);
		if (result == b) {
			good_mask = mask;
			return 1;
		}
		return 0;
	}

	int len = (n - 1 - pos);
	for (int i = 0; i < (1 << len); ++i){
		for (int j = 0; j < len; ++j){
			if (i & (1 << j)){
				mask[pos][j] = 1;
			}
			else
			{
				mask[pos][j] = 0;
			}
		}

		int res = rec(mask, pos + 1);
		if (res == 1) return 1;
	}
	return 0;
}

int main(int argc, char* argv[]) {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("numbers.in", "r", stdin); freopen("numbers.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	forn(tcn, 0, tc)
	{
		//n = 6;
		//mems(D, -1);
		//vector<vector<char> > g(6);
		//g[0].push_back(5);
		//g[0].push_back(1);
		//g[0].push_back(3);
		//g[1].push_back(5);
		//g[1].push_back(2);
		//g[2].push_back(5);
		//g[2].push_back(3);
		//g[3].push_back(5);
		//g[3].push_back(4);
		//g[4].push_back(5);
		//int tmp = dfs(0, g);

		cin >> n >> b;

		vector<vector<char> > mask(n - 1);
		for (int i = 0; i < n - 1; ++i){
			mask[i].resize(n - 1 - i);
		}

		int res = rec(mask, 0);

		cout << "Case #" << tcn + 1 << ": ";
		if (res == 1){
			cout << "POSSIBLE" << endl;

			vector<vector<char> > ans(n, vector<char>(n, '0'));



			for (int i = 0; i < n-1; ++i){
				for (int j = 0; j < good_mask[i].size(); ++j){
					if (good_mask[i][j] == 1){
						ans[i][i + j + 1] = '1';
					}
				}
			}

			forn(i, 0, n){
				forn(j, 0, n){
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}


	return 0;
}