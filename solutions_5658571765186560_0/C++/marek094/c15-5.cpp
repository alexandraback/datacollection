#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ST first
#define ND second
#define MP(a,b) make_pair(a,b)
#define FOR(i,m,n) for(long long i=(long long)(m);i<(long long)(n);++i)
#define REP(i,n) for(long long i=0;i<(long long)(n);++i)
#define DREP(i,n) for(int i=(long long)(n)-1;i>=0;--i)
#define SGN(x) (x<0?-1:(x>0?1:0))
#define ABS(x) (x<0?-x:x)

using namespace std;





void test(int t) {
	cout << "Case #" << t+1 << ": ";
	int X, R, C; cin >> X >> R >> C;
	if (C<R) {int tmp = R; R=C; C=tmp;}
	//cout << R << " " << C << endl;
	bool G = true;
	if (R==1) {
		if (C==1 && X>1) G = false;
		if (C==2 && X>2) G = false;
		if (C==3 && X>1) G = false;
		if (C==4 && X>2) G = false;
	} else if (R==2) {
		if (C==2 && X>2) G = false;
		if (C==3 && X==4) G = false;
		if (C==4 && X>2) G = false;
	} else if (R==3) {
		if (C==3 && X%2==0) G = false;
	} else if (C==4 && X==3) G = false; 
	//cout << X%2 << " " << C << endl;
	cout << (G ? "GABRIEL" : "RICHARD") << endl;	
}


int main() {
	
	int T; cin >> T;
	REP (i, T) 
		test(i);

	return 0;
}

















