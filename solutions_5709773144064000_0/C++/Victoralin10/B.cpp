#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define fi first
#define se second
#define pii pair < int, int >
#define mp make_pair
#define pb push_back
#define scan1(_x) scanf("%d", &(_x))
#define scan2(_x,_y) scanf("%d%d", &(_x), &(_y))
#define scan3(_x,_y,_z) scanf("%d%d%d", &(_x), &(_y), &(_z))
#define FOR(_i,_a,_b) for(int (_i) = (_a); (_i) < (_b); (_i)++)
#define SETALL(_M,_v) memset((_M), (_v), sizeof (_M))
#define TEST() puts(" *** LIGERZERO *** ")
#define MAXN 100005
#define MOD 1000000007

using namespace std;

int main(int nargs, char * args[])
{
	//int _inicio = clock();
	
	int tc;
	cin >> tc;
	double C, F, X;
	double t, v, ans;
	for(int caso = 1; caso <= tc; caso++){
		cin >> C >> F >> X;
		t = 0;
		v = 2;
		ans = (1LL<<50);
		while( t < ans ){
			ans = min(ans,t + X/v);
			t += C/v;
			v += F;
		}
		printf("Case #%d: %.7lf\n", caso, ans);
	}
	
	//printf("\nTime elapsed: %d ms", clock() - _inicio);
}
