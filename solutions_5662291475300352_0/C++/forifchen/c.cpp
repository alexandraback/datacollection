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

int tc,caso;

int main()
{
	cin >> tc;
	while(tc--)
	{
		vector< pii > v;
		int n; cin >> n;
		f(t,0,n)
		{
			int d,h,m;
			cin >> d >> h >> m;
			f(i,0,h) v.pb( make_pair(d, m + i) );
		}
		int ans = 0;
		if (v.size() >= 2)
		{
			if (v[0].fst < v[1].fst) swap(v[0], v[1]);

			ll t1 = (ll)v[0].snd * (360 - v[0].fst);
			ll t2 = t1 + (ll)v[0].snd * 360;

			ll u1 = (ll)v[1].snd * (360 - v[1].fst);
			if (u1 >= t2) ans = 1;
			else if (u1 >= t1) ans = 0;
			else
			{
				ll u2 = u1 + (ll)v[1].snd * 360;
				if (u2 <= t1)
				{
					ans = 1;
				} else ans = 0;
			}
		}
		printf("Case #%d: ", ++caso);
		cout << ans << endl;
	}
}

