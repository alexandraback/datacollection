#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

void solve(){
	int X,R,C;
	scanf("%d%d%d", &X, &R, &C);
	if(X >= 7 || X > max(R,C) || (R*C)%X || X > 2*min(R,C)){
		puts("RICHARD");
		return;
	}
	if(X < 2*min(R,C)-1){
		puts("GABRIEL");
		return;
	}
	if(X == 2*min(R,C)){
		if(X == 2){
			puts("GABRIEL");
			return;
		}
		puts("RICHARD");
		return;
	}
	if(X == 2*min(R,C)-1){
		if(X == 5 && max(R,C) == 5){
			puts("RICHARD");
			return;
		}
		puts("GABRIEL");
		return;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
