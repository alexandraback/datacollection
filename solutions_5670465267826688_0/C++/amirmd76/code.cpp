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
int m[5][5];
inline int f(int x,int y){
	if(x > 0 && y > 0)
		return m[x][y];
	if(x * y > 0)
		return f(abs(x), abs(y));
	return - f(abs(x), abs(y));
}
const int maxn = 1e4 + 10;
string s, t;
int n,x;
int h[maxn], a[maxn];
int suf[maxn];
int main(){
	iOS;
	m[1][1] = 1;
	m[1][2] = 2;
	m[1][3] = 3;
	m[1][4] = 4;
	m[2][1] = 2;
	m[2][2] = -1;
	m[2][3] = 4;
	m[2][4] = -3;
	m[3][1] = 3;
	m[3][2] = -4;
	m[3][3] = -1;
	m[3][4] = 2;
	m[4][1] = 4;
	m[4][2] = 3;
	m[4][3] = -2;
	m[4][4] = -1;
	int T;
	cin >> T;
	For(test, 1, T + 1){
		cout << "Case #" << test <<": ";
		cin >> n >> x;
		cin >> t;
		s = "";
		n *= x;
		while((int)s.size() < n)
			s += t;
		For(i,0,n){
			if(s[i] == '1')
				a[i] = 1;
			else if(s[i] == 'i')
				a[i] = 2;
			else if(s[i] == 'j')
				a[i] = 3;
			else
				a[i] = 4;
		}
		int cur = 1;
		For(i,0,n){
			cur = f(cur, a[i]);
			h[i] = cur;
		}
		cur = 1;
		if(s.size() < 3){
			cout << "NO\n";
			continue;
		}
		rof(i,n-1,-1){
			cur = f(a[i], cur);
			suf[i] = cur;
		}
		bool ok = 0, fnd = 0;
		For(i,2,n){
			if(h[i-2] == 2)
				ok = 1;
			if(ok && h[i-1] == 4 && suf[i] == 4)
				fnd = 1;
		}
		cout << (fnd ? "YES" : "NO") << endl;


	}

}



