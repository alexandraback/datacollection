#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define mem(a, v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<VI> matrix;
const ll MOD = 1000000007LL;

int ans[55][55];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		ll n, m;
		scanf("%lld %lld", &n, &m);
		if(m > (1LL << (n - 2))){
			printf("IMPOSSIBLE\n");
			continue;
		}
		mem(ans, 0);
		for(ll i=0; i<n-1; i++){
			for(ll j=i+1; j<n-1; j++){
				ans[i][j] = 1;
			}
		}
		ans[0][n-1] = 1;
		m--;
		for(ll i=52; i>=0; i--){
			if(m & (1LL << i)){
				ans[i+1][n-1] = 1;
			}
		}
		printf("POSSIBLE\n");
		for(ll i=0; i<n; i++){
			for(ll j=0; j<n; j++){
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}