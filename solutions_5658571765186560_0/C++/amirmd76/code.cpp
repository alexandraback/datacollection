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
string y = "GABRIEL";
string n = "RICHARD";
int main(){
	iOS;
	int T;
	cin >> T;
	For(test, 1, T + 1){
		cout << "Case #" << test <<": ";
		int x,r,c;
		cin >> x >> r >> c;
		if(r < c)	swap(r, c);
		if(x > r or (r * c) % x){
			cout << n << endl;
			continue;
		}
		if(x < 3)
			cout << y << endl;
		else if(x == 3){
			if(r == 3 && c == 2)
				cout << y << endl;
			else if(r == 3 && c == 3)
				cout << y << endl;
			else if(r == 4 && c == 3)
				cout << y << endl;
			else
				cout << n << endl;
		}
		else{
			if(r == 4 && c == 3)
				cout << y << endl;
			else if(r == 4 && c == 4)
				cout << y << endl;
			else
				cout << n << endl;
		}

	}

}



