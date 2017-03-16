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

const int maxn = 20;

string s[maxn], t[maxn];

void solve(){
	int n;
	cin >> n;
	rep(i,n)
		cin >> s[i] >> t[i];
	int m = 1<< n;
	int ans = 0;
	rep(i,m){
		set<string> a,b;
		int cnt = 0;
		rep(j,n)
			if((i>>j)&1){
				a.insert(s[j]);
				b.insert(t[j]);
			}
		bool ok = true;
		rep(j,n)
			if(!((i>>j)&1)){
				cnt++;
				if(a.find(s[j]) == a.end() || b.find(t[j]) == b.end()){
					ok = false;
					break;
				}
			}
		if(ok)
			ans = max(cnt, ans);
	}
	cout << ans << endl;
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
