#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("C.in");
ofstream fout ("C.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

int main() {
	ll T, N, M, K, A, B, c;
	fin >> T;
	for (c = 1; c <= T; c++) {
		fin >> N >> M >> K;
		ll res = K;
		for (A = 0; A < N; A++) {
			for (B = 0; B < M; B++) {
				if (A*B + 2*A + 2*B >= K && A + 2 <= N && B + 2 <= M && res > 2*A + 2*B - (A*B - K)) res = 2*A + 2*B - (A*B + 2*A + 2*B - K);
			}
		}
		fout << "Case #" << c << ": " << res << endl;
	}
	return 0;
}
