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

map<char,int> M;

void decrease(string s) {
	REP(i,sz(s)) {
		M[s[i]]--;
	}
}

int main() {
	int t;
	cin >> t;
	REP(tt, t) {
		M.clear();
		string str;
		cin >> str;
		REP(i,sz(str)) M[str[i]]++;
		string ans = "";
		while(1) {
			if(M['Z'] != 0) { decrease("ZERO"); ans += "0"; }
			else if(M['X'] != 0) { decrease("SIX"); ans += "6"; }
			else if(M['W'] != 0) { decrease("TWO"); ans += "2"; }
			else if(M['U'] != 0) { decrease("FOUR"); ans += "4"; }
			else if(M['O'] != 0) { decrease("ONE"); ans += "1"; }
			else if(M['G'] != 0) { decrease("EIGHT"); ans += "8"; }
			else if(M['H'] != 0) { decrease("THREE"); ans += "3"; }
			else if(M['F'] != 0) { decrease("FIVE"); ans += "5"; }
			else if(M['V'] != 0) { decrease("SEVEN"); ans += "7"; }
			else if(M['N'] != 0) { decrease("NINE"); ans += "9"; }
			else break;
		}
		sort(all(ans));
		cout << "Case #" << tt+1 << ": " << ans << endl;
	}
}
