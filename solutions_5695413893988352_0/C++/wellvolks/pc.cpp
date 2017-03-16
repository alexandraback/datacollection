#include <bits/stdc++.h>

using namespace std;

struct tri{
	int a, b;
	string aa, bb;
	tri (int a = 0, int b = 0, string aa = "", string bb = "") : a(a), b(b), aa(aa), bb(bb) {}
	bool operator < (const tri &k) const{
		int d1 = fabs(a-b);
		int d2 = fabs(k.a-k.b);
		if( d1 != d2 ) return d1 < d2;
		if( a != k.a ) return a < k.a;
		return b < k.b;
	}
};

vector < tri > ans;
vector < pair < int, string > > va, vb;
string a, b;

void solve(int pos, string at, bool f){
	if( f ){
		if( pos >= a.size() ){
			int val;
			sscanf((char*)at.data(), "%d", &val);
			va.push_back(make_pair(val, at));
			return ;
		}
		if( a[pos] == '?' ){
			for(int i = 0; i <= 9; i++){
				solve(pos+1, at+char(i+'0'), f);
			}
		}
		else solve(pos+1, at+a[pos], f);
	}
	else{
		if( pos >= b.size() ){
			int val;
			sscanf((char*)at.data(), "%d", &val);
			vb.push_back(make_pair(val,at));
			return ;
		}
		if( b[pos] == '?' ){
			for(int i = 0; i <= 9; i++){
				solve(pos+1, at+char(i+'0'), f);
			}
		}
		else solve(pos+1, at+b[pos], f);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t, k = 1;
	cin >> t;
	while(t--){
		
		cin >> a >> b;
		solve(0, "", 0);
		solve(0, "", 1);
		for(int i = 0; i < va.size(); i++){
			for( int j = 0; j < vb.size(); j++ ){
				ans.push_back(tri(va[i].first, vb[j].first, va[i].second, vb[j].second));
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << k++ << ": " << ans[0].aa << " " << ans[0].bb << '\n';
		ans.clear();
		va.clear();
		vb.clear();
	}
	return 0;
}