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



int tc, caso;
string a[55];
void solve(int m, int n, int M) {
	int q = m*n - M;
	if (m == 3) {
		if (q%3 == 2) {
			f(i,0,m) f(j,0,q/3) a[i][j] = '.';
			a[0][q/3] = a[1][q/3] = '.';
		} else if(q%3 == 0) {
			f(i,0,m) f(j,0,q/3) a[i][j] = '.';
		} else {
			f(i,0,m) f(j,0,q/3-1) a[i][j] = '.';
			a[0][q/3-1] = a[1][q/3-1] = '.';
			a[0][q/3] = a[1][q/3] = '.';
		}
	} else {
		if (M >= n) {
			solve(m-1, n, M-n);
		} else if(M < n-1) {
			f(i,0,m) f(j,0,n) a[i][j] = '.';
			f(j,0,M) a[m-1][j] = '*';
		} else {
			f(i,0,m) f(j,0,n) a[i][j] = '.';
			f(j,0,n-2) a[m-1][j] = '*';
			a[m-2][0] = '*';
		}
	}
}
int r,c,M;

int main(){
	cin >> tc;
	while(tc--) {
		cin >> r >> c >> M;
		int m = min(r,c), n = max(r,c);
		f(i,0,m) a[i] = string(n,0);
		printf("Case #%d:\n", ++caso);
		if (M == m*n-1) {
			f(i,0,m) f(j,0,n) a[i][j] = '*';
			a[0][0] = 'c';
		} else if (m == 1){
			f(i,0,M) a[0][i] = '*';
			f(i,M,n) a[0][i] = '.';
			a[0][n-1] = 'c';
		} else if (m == 2){
			if (M%2 || M == m*n-2) {
				puts("Impossible");
				continue;
			} else {
				f(i,0,2) f(j,0,n) a[i][j] = j<M/2? '*' : '.';
				a[0][n-1] = 'c';
			}
		} else {
			int q = m*n - M;
			if (q == 2 || q == 3 || q == 5 || q == 7) {
				puts("Impossible");
				continue;
			} else {
				f(i,0,m) f(j,0,n) a[i][j] = '*';
				if (q == 4 || q == 6) {
					f(i,0,2) f(j,0,q/2) a[i][j] = '.';
				} else {
					solve(m,n,M);
				}
			}
			a[0][0] = 'c';
		}

		if (r == m) {
			f(i,0,m) {
				f(j,0,n) putchar(a[i][j]);
				putchar(10);
			}
		} else {
			f(i,0,n) {
				f(j,0,m) putchar(a[j][i]);
				putchar(10);
			}
		}
	}
}


