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
#define N 1005
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc, caso;
int n;
double a[N], b[N];

int main(){
	cin >> tc;
	while(tc--) {
		cin >> n;
		f(i,0,n) scanf("%lf", a + i);
		f(i,0,n) scanf("%lf", b + i);
		sort(a, a + n); sort(b, b + n);
//		adebug(a, n);
//		adebug(b, n);
		int pa,pb;
		int r1,r2;
		pa = pb = 0;
		r1 = r2 = 0;
		for(; pa < n; pa++) {
			for (;pb<n &&  b[pb] < a[pa]; pb++);
			if (pb < n) {
				r1++;
				pb++;
			}
		}
		pa = pb = 0;
		for(; pb < n; pb++) {
			for (; pa < n && a[pa] < b[pb]; pa++);
			if (pa < n) {
				r2++;
				pa++;
			}
		}
		printf("Case #%d: %d %d\n", ++caso, r2, n-r1);
	}
}


