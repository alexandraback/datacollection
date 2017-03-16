#include <bits/stdc++.h>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define dbg(e)  cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define REP(i,n) FOR(i,0,n)
#define pb  push_back
#define mp make_pair
#define INF (1 << 29)

int main() {
	int t;
	cin >> t;
	REP(tt, t) {
		string s;
		cin >> s;
		string res = "";
		REP(i,sz(s)) {
			if(res == "") res += s[i];
			else {
				if(res[0] > s[i]) res += s[i];
				else res = s[i] + res;
			}
		}
		cout << "Case #" << tt+1 << ": " << res << endl;
	}
}
