#include <bits/stdc++.h>
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)  for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio(false)
#define sqr(a)  (((a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
#define umap  unordered_map
#define smax(x, y)	x = max((x), (y))
#define smin(x, y)	x = min((x), (y))
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
string s;
int m;
inline bool check(int x){
	if(s.size() == 1)
		return true;
	int t = x + s[0] - '0';
	For(i,1,s.size()){
		if(t < i)	return false;
		t += s[i] - '0';
	}
	return true;
}
int main(){
	iOS;
	int T;
	cin >> T;
	For(TT, 1, T + 1){
		cout << "Case #" << TT << ": ";
		cin >> m >> s;
		int l = 0, r = 1500;
		while(l < r){
			int mid = (l+r)/2;
			if(check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		cout << l << endl;
	}
}



