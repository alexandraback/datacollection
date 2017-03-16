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

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

int K;
int N;
vector<int> start, type;
vector< vector<int> > chest;

int dp[1<<21];
int par[1<<21];

int memo(int state, vector<int> keys) {
	if( state == ((1<<N)-1) )  return 1;
	if( dp[state] != -1 ) return dp[state];

	for(int i = 0; i < N; i++) {
		if( state & (1<<i) ) continue;
		vector<int> temp;
		temp = keys;
		int j;
		for(j = 0; j < temp.size(); j++)
			if( temp[j] == type[i] ) break;
		if( j < temp.size() ) {
			temp.erase(temp.begin() + j);
			for(j = 0; j < chest[i].size(); j++)
				temp.push_back(chest[i][j]);

			int res = memo(state | (1<<i), temp);
			if( res == 1 ) {
				par[state] = i;
				return dp[state] = 1;
			}
		}
	}
	return dp[state] = 0;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		cin >> K >> N;
		start = takeInput<int>(K);
		type.clear();
		chest.clear();
		for(int i = 0; i < N; i++) {
			int a; cin >> a; type.push_back(a);
			int b; cin >> b;
			vector<int> v;
			v = takeInput<int>(b);
			chest.push_back(v);
		}

		memset(dp, -1, sizeof(dp));
		memset(par, -1, sizeof(par));

		memo(0, start);
		printf("Case #%d:", cases);
		if( par[0] == -1 ) cout << " IMPOSSIBLE\n";
		else {
			vector<int> res; res.clear();
			int state = 0;
			while(state != ( (1<<N) - 1) ) {
				res.push_back(par[state]);
				state |= (1<< par[state]);
			}
			for(int i = 0; i < res.size(); i++) {
				cout << " " << res[i]  + 1;
			}
			cout << endl;
		}
	}
	return 0;
}
