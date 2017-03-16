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
#define int ll
typedef pair<int,int>pii;
typedef vector<int> vi;
int m[5][5];
const ll inf = 1LL << 60;
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
int power(int a,int b){
	if(!b)	return 1;
	int c = power(a, b/2);
	c = f(c, c);
	if(b % 2)
		c = f(c,a);
	return c;
}
main(){
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
		s = t;
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
		int al = h[n-1];
		cur = 1;
		if((ll)n * x < 3LL){
			cout << "NO\n";
			continue;
		}
		rof(i,n-1,-1){
			cur = f(a[i], cur);
			suf[i] = cur;
		}
		ll fi = inf;
		For(i,0,n){
			cur = 1;
			int v;
			For(j,0,min(60LL, x)){
				v = f(cur, h[i]);
				if(v == 2)
					smin(fi, j * (ll)n + i);
				cur = f(cur, al);
			}
		}
		if(fi == inf or fi >= n * x){
			cout << "NO\n";
			continue;
		}
		bool fnd = false;
		For(i,0,n){
			cur = 1;
			int v,u;
			For(j,0,min(x, 257LL)){
				v = f(cur, h[i]);
				if(i + (1LL * j * n) > fi){
					int t = x - j - 1;
					int k = (i + 1)%n;
					if(!k)
						-- t;
					if(t >= 0){
						u = f(suf[k], power(al, t));
						if(v == 4 && u == 4)
							fnd = true;
					}
				}
				cur = f(cur, al);
			}
		}
		cout << (fnd ? "YES" : "NO") << endl;
	}

}


