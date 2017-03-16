#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<sstream>
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define VI vector<int>

typedef pair<int,int> pi;

string num[] = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT", "ONE", "THREE", "FIVE", "SEVEN", "NINE"};
int dig[] = {0,2,4,6,8,1,3,5,7,9};
string id = "ZWUXGOHFVI";

int cntOcc(string s, char c){
	int cnt = 0;
	rep(i,s.length())
		if(s[i] == c)
			cnt++;
	return cnt;
}

int req[500];

string remove(string s, int cnt, string w){
	memset(req, 0, sizeof(req));
	rep(i, w.length())
		req[w[i]] += cnt;
	stringstream ss;
	rep(i,s.length())
		if(req[s[i]] > 0)
			req[s[i]]--;
		else
			ss << s[i];
	return ss.str();
}

void solve(){
	string s;
	cin >> s;
	VI ans;
	rep(i,10){
		int cnt = cntOcc(s, id[i]);
		rep(j,cnt)
			ans.pb(dig[i]);
		s = remove(s, cnt, num[i]);
	}
	sort(ans.begin(), ans.end());
	rep(i,ans.size())
		cout << ans[i] ;
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": ";
		solve();
	}
	return 0;
}
