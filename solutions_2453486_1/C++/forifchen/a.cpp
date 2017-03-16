#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc;

string a[4];

int main(){
	cin >> tc;
	int caso = 0;
	while (tc--) {
		f(i,0,4) cin >> a[i];

		printf("Case #%d: ",++caso);
		int O = 0, X = 0;
		int emp = 0;
		f(i,0,4) f(j,0,4) if (a[i][j] == '.') emp++;

		f(i,0,4) {
			int todo = 1;
			f(j,0,4) if (a[i][j] == 'O' || a[i][j] == '.') todo = 0;
			if (todo) X = 1;

			todo = 1;
			f(j,0,4) if (a[i][j] == 'X' || a[i][j] == '.') todo = 0;
			if (todo) O = 1;
		}
		f(j,0,4) {
			int todo = 1;
			f(i,0,4) if (a[i][j] == 'O' || a[i][j] == '.') todo = 0;
			if (todo) X = 1;

			todo = 1;
			f(i,0,4) if (a[i][j] == 'X' || a[i][j] == '.') todo = 0;
			if (todo) O = 1;
		}

		int todo;
		todo = 1;
		f(i,0,4) if (a[i][i] == 'O' || a[i][i] == '.') todo = 0;
		if (todo) X = 1;
		todo = 1;
		f(i,0,4) if (a[i][i] == 'X' || a[i][i] == '.') todo = 0;
		if (todo) O = 1;
		todo = 1;
		f(i,0,4) if (a[i][3-i] == 'O' || a[i][3-i] == '.') todo = 0;
		if (todo) X = 1;
		todo = 1;
		f(i,0,4) if (a[i][3-i] == 'X' || a[i][3-i] == '.') todo = 0;
		if (todo) O = 1;

		string res;
		if (O && X) res = "Draw";
		else if (O && X==0) res = "O won";
		else if (X && O==0) res = "X won";
		else if (emp) res = "Game has not completed";
		else res = "Draw";

		cout << res << endl;
	}
}

