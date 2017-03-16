#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std; 

typedef vector<int> VI; 
#define i64 long long 
#define pii pair<int,int>
#define mp make_pair
#define ALL(x) (x).begin(), (x).end() 
#define REP(i,n) for(int i = 0;i<(int)n;++i)
#define x first
#define y second

int T;
char g[8][8];
const string states[] = {"X won","O won","Draw","Game has not completed"};
int state, emptyCells;
int xs, os, hasT;

void readData() {
	REP(i,4) {
		cin.getline(g[i],8);
	}
	cin.get();
}

void checkState() {
	if(xs + hasT == 4) {
		state = 0;
	} else
	if(os + hasT == 4) {
		state = 1;
	}
}

void solve(int t) {
	state = -1, emptyCells = 0;
	REP(i,4) {
		os = xs = hasT = 0;
		REP(j,4) {
			if(g[i][j] == 'T') {
				hasT = 1;
			} else 
			if(g[i][j] == 'X') {
				xs++;
			} else 
			if(g[i][j] == 'O') {
				os++;
			} else {
				emptyCells++;
			}
		}
		checkState();
	}
	REP(i,4) {
		os = xs = hasT = 0;
		REP(j,4) {
			if(g[j][i] == 'T') {
				hasT = 1;
			} else 
			if(g[j][i] == 'X') {
				xs++;
			} else 
			if(g[j][i] == 'O') {
				os++;
			} 
		}
		checkState();
	}
	os = xs = hasT = 0;
	REP(i,4) {
		if(g[i][i] == 'T') {
			hasT = 1;
		} else 
		if(g[i][i] == 'X') {
			xs++;
		} else 
		if(g[i][i] == 'O') {
			os++;
		} 
	}
	checkState();
	os = xs = hasT = 0;
	REP(i,4) {
		if(g[i][3 - i] == 'T') {
			hasT = 1;
		} else 
		if(g[i][3 - i] == 'X') {
			xs++;
		} else 
		if(g[i][3 - i] == 'O') {
			os++;
		} 
	}
	checkState();
	if(state == -1) {
		state = emptyCells > 0 ? 3 : 2; 
	}
	cout<<"Case #"<<t<<": "<<states[state]<<"\n";
}

int main()
{
	//freopen("test.in","r",stdin); freopen("test.out","w",stdout);cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	cin>>T;
	cin.get();
	REP(t,T) {
		readData();
		solve(t + 1);
	}
	return 0;
}
