#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <string.h>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1<<20
#define EPS 1e-5

int dp[50][50];
int sums[50];
vector<int> v;
int V;
int solve(int ind, int sum) {
	if (sum > V)
		return 0;
	sums[sum] = 1;
	if (ind == sz(v))
		return 0;
	if (dp[ind][sum] != -1)
		return dp[ind][sum];

	return dp[ind][sum] = solve(ind + 1, sum + v[ind]) | solve(ind + 1, sum);
}

int main() {

	freopen("txt.in", "r", stdin);
	freopen("txt.out", "w", stdout);

	int TC;
	cin >> TC;
	int CC = 1;

	while (TC--) {
		int C, D;
		cin >> C >> D >> V;
		v.clear();
		int ret = 0;

		for (int i = 0; i < D; i++) {
			int x;
			cin >> x;
			v.pb(x);
		}
		sort(all(v));
		while (1) {
			memset(dp, -1, sizeof dp);
			memset(sums, 0, sizeof sums);
			solve(0, 0);
			int less = -1;
			for (int i = 1; i <= V; i++) {
//				cout << sums[i] << " ";
				if (sums[i] == 0) {
					less = i;
					break;
				}
			}
//			cout << endl;
			if (less == -1)
				break;
			v.pb(less);
			ret++;
			sort(all(v));
		}
		printf("Case #%d: ", CC++);
		cout << ret << endl;
	}
}
