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
	int N;
	scanf("%d", &N);
	if(!N){
		puts("INSOMNIA");
		return;
	}
	bool seen[10];
	rep(i,0,10)seen[i]=0;
	for(int i=1; true; ++i){
		int j=i*N;
		while(j){
			seen[j%10]=1;
			j /= 10;
		}
		bool ok=1;
		rep(j,0,10)
			if(!seen[j])
				ok=0;
		if(ok){
			printf("%d\n", i*N);
			return;
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
}
