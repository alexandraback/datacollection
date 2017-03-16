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

int T, N, K, M, R;

double p ( int x, VI P )
{
	double cnt = 0;
	for (int i = 0; i < (1<<N); i += 1)
	{
		int u = 1;
		for (int j = 0; j < N; j += 1)
			if( (i&(1<<j)) )
				u *= P[j];
		if(u == x)
			cnt += 1.0;
	}
	return cnt;
}

double p ( VI X, VI P ) // X(K), P(N)
{
	double ret = 1.0;
	for (int i = 0; i < K; i += 1)
		ret *= p(X[i],P);
	return ret;
}

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> R >> N >> M >> K;
		
		VVI pat;
		VI v;
		VI X = VI(K);
 
		for (int i = 2; i <= M; i += 1)
		{
			v.pb(i);
			for (int j = 2; j <= M; j += 1)
			{
				v.pb(j);
				for (int k = 2; k <= M; k += 1)
				{
					v.pb(k);
					pat.pb(v);
					v.pop_back();
				}
				v.pop_back();
			}
			v.pop_back();
		}
		vector<double> prob;
		
		cout << "Case #1:\n";
		
		for (int r = 0; r < R; r += 1)
		{
			prob.clear();
			double mp = 0;
			
			for (int i = 0; i < K; i += 1)
			{
				cin >> X[i];
			}
			
			for (int i = 0; i < sz(pat); i += 1)
			{
				prob.pb(p(X,pat[i]));
				mp = max(mp,prob.back());
			}
//			cout << mp << '\n';
			for (int i = 0; i < sz(pat); i += 1)
			{
//				cout << mp << ' ' << prob[i] << 
				if (mp == prob[i])
				{
					for (int j = 0; j < N; j += 1)
					{
						cout << pat[i][j];
					}
					cout << '\n';
					break;
				}
				if (i == sz(pat)-1)
				{
					for (int j = 0; j < N; j += 1)
					{
						cout << pat[i][j];
					}
					cout << '\n';
					break;
				}
			}
		}
	}
	
	return 0;
}











