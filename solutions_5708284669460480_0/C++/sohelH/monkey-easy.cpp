#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int K, L, S;
string keys;
string target;
vector<char> v;
int sum, maxi, tot;

void check() {
	string s;
	for (int i = 0; i < v.size(); i++)
		s += v[i];

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.substr(i, L) == target) {
			cnt++;
		}
	}
	maxi = max(maxi, cnt);
	sum += cnt;
	tot++;
}

void dfs(int u) {
	if (u == S) {
		check();
		return;
	}

	for (int i = 0; i < K; i++) {
		v.push_back(keys[i]);
		dfs(u+1);
		v.pop_back();
	}
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		cin >> K >> L >> S;
		cin >> keys;
		cin >> target;

		v.clear();
		sum = 0;
		maxi = 0;
		tot = 0;
		dfs(0);

		//DEBUG(sum);
		//DEBUG(maxi);
		//DEBUG(tot);

		double res = 1.0 * maxi * tot - sum;
		res /= tot;

		printf("Case #%d: %.8lf\n", cases, res);

	}
	return 0;
}
