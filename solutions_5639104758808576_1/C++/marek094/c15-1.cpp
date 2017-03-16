#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ST first
#define ND second
#define MP(a,b) make_pair(a,b)
#define FOR(i,m,n) for(int i=int(m);i<int(n);++i)
#define REP(i,n) for(int i=0;i<int(n);++i)
#define DREP(i,n) for(int i=int(n)-1;i>=0;--i)

using namespace std;

double wn[1111], wk[1111];

void test(int t) {
	int N; cin >> N;
	
	char c = getchar();
	long long x=0, r = 0;
	REP (i, N+1) {
		c = getchar();
		if (x<i) {
			r += i-x;
			x += i-x;
			//cout <<" "<<r <<" "<< x;
		}
		x += int(c-'0');
		//cout << endl;
	}	
	cout << "Case #" << t+1 << ": " << r << endl;


	
}


int main() {
	int T; cin >> T;
	
	REP (i, T) 
		test(i);

	return 0;
}

















