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

int N, T, X, Y, k, u, s;
double ans, C[3000][3000];

int main (int argc, char const* argv[])
{
	C[0][0] = 1.0;
	for (int n = 1; n < 2700; n += 1)
	{
		C[n][0] = C[n-1][0]/2.0;
		C[n][n] = C[n][0];
		
		for (int r = 1; r < n; r += 1)
		{
			C[n][r] = (C[n-1][r-1]+C[n-1][r])/2.0;
		}
	}
	
	cin >> T;

	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> N >> X >> Y;
		X = abs(X);
		
		for (k = 1; ; k += 2)
		{
			if (k*(k+1) <= 2*N && 2*N < (k+2)*(k+3))
			{
				break;
			}
		}
		k = (k-1)/2;
		if (X+Y <= 2*k)
		{
			ans = 1.0;
		}
		else if (X+Y > 2*(k+1))// || Y == 2*(k+1))
		{
			ans = 0.0;
		}
		else
		{
			X = abs(X);
			s = N-((2*k+1)*(k+1));
			u = Y+1;
			ans = 0.0;
			double baal = 0.0;
			for (int i = max(0,s-2*(k+1)); i <= min(s,2*(k+1)); i += 1)
			{
				baal += C[s][i];
			}
			for (int i = max(0,s-2*(k+1)); i <= min(Y,min(s,2*(k+1))); i += 1)
			{
				ans += C[s][i]/baal; 
			}
			ans = 1.0-ans;
		}
		//cout << N << ' ' << k << ' ' << s << ' ' << u << '\n';
		cout << "Case #" << cs << ": ";
		printf("%.9lf\n",ans);
	}
	
	return 0;
}














