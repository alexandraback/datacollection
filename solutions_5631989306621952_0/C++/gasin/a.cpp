#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

string calc(string s){
	string ret;
	char M = 'A';
	rep(i,s.size()){
		if(M <= s[i]){
			M = s[i];
		}
	}
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == M){
			ret.push_back(s[i]);
			ret += calc(s.substr(0,i));
			ret += s.substr(i+1,s.size()-i-1);
			break;
		}
	}
	return ret;
}

void solve(){
	string s;
	cin >> s;
	cout << calc(s) << endl;
}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}