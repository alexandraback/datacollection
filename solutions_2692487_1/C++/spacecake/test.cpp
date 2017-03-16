#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std; 

typedef vector<int> VI; 
#define i64 long long 
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define ALL(x) (x).begin(), (x).end() 
#define REP(i,n) for(int i = 0;i<(int)n;++i) 

int T, A, N;
int motes[105];

int solve() {
	if(A == 1) {
		return N;
	}
	int ret = N;
	sort(motes,motes + N);
	int addedMotes = 0;
	for(int i = 0;i < N;++i) {
		if(A > motes[i]) {
			A += motes[i];
			continue;
		}
		ret = min(ret,addedMotes + N - i);
		while(A <= motes[i]) {
			A = A + A - 1;
			addedMotes++;
		}
		A += motes[i];
	}
	ret = min(ret,addedMotes);
	return ret;
}

void readData() {
	cin>>A>>N;
	
	REP(i,N) {
		cin>>motes[i];
	}
}


int main()
{
	freopen("test.in","r",stdin); freopen("test.out","w",stdout);
	cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	cin>>T;
	for(int t = 1;t <= T;++t) { 
		readData();
		cout<<"Case #"<<t<<": "<<solve()<<"\n";
	}
  
	return 0;
} 

