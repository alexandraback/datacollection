#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <sstream>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef pair<ll,ll> PL;
typedef vector<ll> VL;
typedef vector<VL> VVL;

int T, R, E, N;
VI v;
VVI dp;

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> E >> R >> N;
		
		v = VI(N);
		dp = VVI ( E+1, VI( N+1, 0 ) );
		
		for (int i = 0; i < N; i += 1)
		{
			cin >> v[i];
		}
		
		for (int i = N-1; i >= 0; i -= 1)
		{
			for (int e = 0; e <= E; e += 1)
			{
				for (int f = 0; f <= e; f += 1)
				{
					dp[e][i] = max(dp[e][i], v[i]*f+dp[min(E,e-f+R)][i+1]);
				}
			}
		}
		cout << "Case #" << cs << ": " << dp[E][0] << '\n';
	}
	
	return 0;
}











