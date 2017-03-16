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
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		K = min(K, S);
		//vector<vector<int> > all;
		//for (int i = 1; i <= J; ++i){
		//	for (int j = 1; j <= P; ++j){
		//		for (int k = 1; k <= S; ++k){
		//			vector<int> cur(3);
		//			cur[0] = i;
		//			cur[1] = j;
		//			cur[2] = k;
		//			all.push_back(cur);
		//		}
		//	}
		//}

		//int ans = 0;
		//int max_count = 0;
		//int m1[10][10];
		//int m2[10][10];
		//int m3[10][10];
		//for (int i = 0; i < (1 << all.size()); ++i){

		//	mems(m1, 0);
		//	mems(m2, 0);
		//	mems(m3, 0);
		//	//map<pair<int, int>, int> m1, m2, m3;
		//	bool good = true;
		//	int count = 0;
		//	for (int j = 0; j < all.size(); ++j){
		//		if (!good) break;
		//		if (i & (1 << j)){
		//			count++;
		//			m1[all[j][0]][all[j][1]]++;
		//			m2[all[j][1]][all[j][2]]++;
		//			m3[all[j][0]][all[j][2]]++;

		//			good &= m1[all[j][0]][all[j][1]] <= K;
		//			good &= m2[all[j][1]][all[j][2]] <= K;
		//			good &= m3[all[j][0]][all[j][2]] <= K;
		//		}
		//	}

		//	if (good && max_count < count){
		//		max_count = count;
		//		ans = i;
		//	}
		//}

		set<vector<int> > alr;

		for (int kk = 0; kk < K; ++kk){

		for (int i = 1; i <= J; ++i){
			int cycle = i - 1;
			for (int j = 1; j <= P; ++j){
				vector<int> cur(3);
				cur[0] = i;
				cur[1] = j;
				cur[2] = (j - 1 + cycle + kk) % S + 1;
				alr.insert(cur);
			}
		}

		}

		cout << "Case #" << tcn + 1 << ": ";
		cout << alr.size() << endl;
		for (auto it: alr){
	
			cout << it[0] << " " << it[1] << " " << it[2] << endl;
	
		}
	}


	return 0;
}