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

int N, J;

void rec(string s){
	if(s.size() > N-2)
		return;
	if(!J)
		return;
	if(s.size() == N-2){
		--J;
		s.push_back('1');
		s.push_back('1');
		cout << s;
		rep(i,2,11)
			cout << " " << (i+1);
		cout << endl;
		return;
	}
	string t=s;
	t.push_back('0');
	rec(t);
	s.push_back('1');
	s.push_back('1');
	rec(s);
}

void solve(){
   	scanf("%d%d", &N, &J);
	printf("\n");
	rec("11");
	assert(!J);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
}
