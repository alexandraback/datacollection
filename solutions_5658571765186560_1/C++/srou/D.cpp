#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool win(int X, int R, int C) {
	if (R > C) swap(R,C);

	if ((R*C)%X != 0) return false;
	if (C<X) return false;
	if (R < (X+1)/2) return false;
	if (X>6) return false;
	if (X==4 && R==2) return false;
	if (X==5 && R==3 && C<10) return false;
	if (X==6 && R==3) return false;

	return true;
}

// X==3, ok
// X==4, if R==2, then false
// X==5, if R==3, then C>=10
// X==6, if R==3, then false
// Check that X==1 ok

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t<T; ++t) {
		int X, R, C;
		scanf("%d%d%d",&X,&R,&C);
		printf("Case #%d: %s\n", t+1, win(X,R,C)? "GABRIEL" : "RICHARD");
	}
	return 0;
}