#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;


#define LOGSZ 17

int t;
int a, b, k, cnt;

int main (int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	
	cin >> t;
	for (int cs = 1; cs <= t; ++cs)
	{
		cin >> a >> b >> k;
		cnt = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				if((i&j) < k)
					cnt++;
		printf("Case #%d: %d\n", cs, cnt);
	}
	
	return 0;
}
