#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef deque<int> VI;
typedef deque<VI> VVI;
typedef pair<int,int> PI;
typedef deque<PI> VPI;
typedef deque<VPI> VVPI;
typedef pair<ll,ll> PL;
typedef deque<ll> VL;
typedef deque<VL> VVL;

int T, N, prev, w, e, s, ds, d, dd, dx, n, l, r, cnt;

struct attack
{
	int d, s, l, r;
	
	attack(){}
	attack( int w, int e, int _d, int _s )
	{
		l = w, r = e, d = _d, s = _s;
	}
	bool operator < ( const attack &a ) const
	{
		return d < a.d;
	}
};

deque < attack > v;
VI _L, L;

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> N;
		
		cnt = 0, l = 10000, r = -10000;
		v.clear();
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> d >> n >> w >> e >> s >> dd >> dx >> ds;
			
			for (int i = 0; i < n; i += 1)
			{
				v.push_back(attack(w,e-1,d,s));
				l = min (l, w);
				r = max (r, e-1);
				d += dd;
				w += dx;
				e += dx;
				s += ds;
			}
		}
		
		sort(all(v));
		for (int i = 0; i < sz(v); i += 1)
			v[i].l -= l, v[i].r -= l;
		L = VI(r-l+1000,0);
		_L = VI(r-l+1000,0);
		prev = -1, s = 0, l = 10000, r = -10000;
		for (int i = 0; i < sz(v); i += 1)
		{
			/*cout << "-------\n";
			cout << v[i].l << ' ' << v[i].r << ' ' << v[i].d << ' ' << v[i].s << '\n';
			for (int j = 0; j <= 10; j += 1)
			{
				cout << L[j] << ' ';
			}
			cout << "\n-----------\n";*/
			if(v[i].d > prev)
			{
				for (int j = l; j <= r; j += 1)
					{L[j] = max(L[j],_L[j]); _L[j] = 0;}
				l = 10000, r = -10000;
			}
			for (int j = v[i].l; j <= v[i].r; j += 1)
				_L[j] = max(_L[j], v[i].s);
			for (int j = v[i].l; j <= v[i].r; j += 1)
			{
				if(L[j] < v[i].s)
				{
					cnt++;
					break;
				}
			}
			prev = v[i].d;
			l = min(v[i].l,l);
			r = max(v[i].r,r);
		}
		
		
		cout << "Case #" << cs << ": " << cnt << '\n';
	}
	
	return 0;
}














