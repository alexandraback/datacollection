#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<veci> vecveci;
/// Hey yo man, lets do some contest in 5:30 AM!
int N;
int visited[1010];
int BFF[1010];
veci RBFF[1010];
veci state;
vector<pii> besties;
int maxAns;
int check() {
	int zz, xx;
	for (int k = 0;k < state.size();k++) {
		zz = (k + 1) % state.size();
		xx = (k + int(state.size())-1) % state.size();
		if (BFF[state[k]] != state[zz] && BFF[state[k]] != state[xx])return 0;
	}
	maxAns = max(maxAns, (int)state.size());
	return 1;
}
void go(int, int);
void okthen() {
	/// try 1 back
	if (state.size()) {
		int top = state[int(state.size()) - 1];
		for (int myfriends : RBFF[top]) {
			if (visited[myfriends] == 0) {
				go(myfriends, -1);
			}
		}
	}
	/// try good last
	if (state.size()) {
		if (visited[BFF[state[0]]] == 0) {
			go(BFF[state[0]], -1);
		}
	}
	/// try 2 back
	for (pii p : besties) {
		if (visited[p.first] == 0 && visited[p.second] == 0) {
			go(p.first, p.second);
			go(p.second, p.first);
		}
	}
}
void go(int a,int b) {
	int i;
	int ok=0;
	if (b != -1) {
		visited[a] = 1;
		state.push_back(a);
		check();
		visited[b] = 1;
		state.push_back(b);
		check();
		ok = 1;
	}else{
		if (visited[BFF[a]] && state.size()>0 && state[state.size() - 1] == BFF[a]) {
			ok = 1;
		}
		visited[a] = 1;
		state.push_back(a);
		check();
		if (ok == 0) {
			if (visited[BFF[a]] == 0) {
				go(BFF[a], -1);
			}
		}
	}

	if (ok) {
		okthen();
	}
	visited[a] = 0;
	state.pop_back();
	if (b != -1) {
		visited[b] = 0;
		state.pop_back();
	}
}
int solve() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		RBFF[i].clear();
	}
	besties.clear();
	for (int i = 0;i < N;i++) {
		cin >> BFF[i];
		BFF[i]--;
		RBFF[BFF[i]].push_back(i);
		if (BFF[i] < i && BFF[BFF[i]] == i) {
			besties.push_back(pii(i, BFF[i]));
		}
	}
	
	maxAns = 0;
	okthen();
	for (int i = 0;i < N;i++) {
		go(i, -1);
	}
	return maxAns;
}
int main() {
	int n, test, t, i, tmp;
	string inp;
	cin >> t;
	for (test = 1;test <= t;test++) {

		cout << "Case #" << test << ": "<<solve()<< endl;
	}
	
	return 0;
}
