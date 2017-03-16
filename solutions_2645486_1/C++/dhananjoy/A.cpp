#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

#define B    0
#define X    1
#define Y    1
#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef pair<ll,ll> PL;
typedef vector<ll> VL;
typedef vector<VL> VVL;

int T, N;
ll E, R;

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> E >> R >> N;
		
		VI d, r = VI(N,-1);
		VL v = VL(N);
		
		for (int i = 0; i < N; i += 1)
			cin >> v[i];
		
		for (int i = N-1; i >= 0; i -= 1)
		{
			while (!d.empty() && v[i] > v[d.back()])
			{
				d.pop_back();
			}
			if (!d.empty())
				r[i] = d.back();
			d.pb(i);
		}
		
		ll e = E, f, tot = 0;
		
		for (int i = 0; i < N; i += 1)
		{
			if (r[i] == -1)
			{
				tot += v[i]*e;
				e = 0;
			}
			else
			{
				f = e + ((ll)(r[i]-i))*R;
				tot += v[i]*max(0LL,min(e,f-E));
				e -= max(0LL,min(e,f-E));
			}
			e += R;
		}
		cout << "Case #" << cs << ": " << tot << '\n';
	}
	
	return 0;
}










