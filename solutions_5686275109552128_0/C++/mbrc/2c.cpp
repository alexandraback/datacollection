#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

priority_queue<int> Q;

void solve(int t) {
	int n; cin>>n; int p;
	Q = *new priority_queue<int>();
	REP(i,1,n) {
		cin>>p; Q.push(p); 
	}
	int best = Q.top(); int moves = 0;
	while (Q.top() > 1) {
		int x = Q.top(); Q.pop(); Q.push((x+1)/2); Q.push(x/2);
		moves++;
		best = MIN(best	, moves + Q.top());
	}
	cout<<"Case #"<<t<<": "<<best<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin>>t;
	REP(q,1,t) solve(q);
	return 0;
}
