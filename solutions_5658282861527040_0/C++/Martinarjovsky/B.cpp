#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

int main() {
	ll T, c, A, B, K, i, j, res, x;
	fin >> T;

	for (c = 1; c <= T; c++) {
		fin >> A >> B >> K;

		res = 0;
		for (x = 0; x < K; x++) {
			for (i = 0; i < A; i++) {
				for (j = 0; j < B; j++) {
					if (x == (i & j)) {
						res++;
					}
				}
			}
		}
		fout << "Case #" << c <<": " << res << endl;

	}



	return 0;
}
