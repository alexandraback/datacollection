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

int T;
double r, t, k;

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> r >> t;
		k = sqrt( t/2.0 + (2.0*r-1.0)*(2.0*r-1.0)/16.0 ) - (2.0*r-1.0)/4.0;
		k = (int)(k+1e-7);
		cout << "Case #" << cs << ": " << (int)k << '\n';
	}
	
	return 0;
}











