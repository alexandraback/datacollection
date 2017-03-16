#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (a); i >= (b); i--)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define itr iterator

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

bool tried[30]; 

int main(){
	int r, c, w;
	int t;
	cin >> t;
	REP(caso, t){
		int ans = 0;
		cin >> r >> c >> w;
		ans += (r)*(c/w);
		ans += (w-1);
		if(c % w != 0)
			ans++;
		cout << "Case #" << caso+1 << ": " << ans << endl;
	}
	return 0;
}