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
#define N 1000001
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int rev(int x)
{
	int w[7], j = 0;
	while (x)
	{
		w[j++] = x%10;
		x/=10;
	}
	int ans = 0;
	for (int i = 0; i < j; i++) ans = ans*10 + w[i];
	return ans;
}

int tc,caso;
int d[1000005];
int q[N], sz;

int main(){
	d[1] = 1;
	q[sz++] = 1;
	f(i,0,sz)
	{
		int x = q[i];
		if (x >= N)
		{
			debug(x);
			break;
		}
		if (x+1 < N && d[x+1] == 0) q[sz++] = x+1, d[x+1] = d[x] + 1;
		int y = rev(x);
		if (d[y] == 0) q[sz++] = y, d[y] = d[x] + 1;
	}
	

	cin >> tc;
	while(tc--)
	{
		int n; cin >> n;
		printf("Case #%d: ", ++caso);
		cout << d[n] << endl;
	}
}

