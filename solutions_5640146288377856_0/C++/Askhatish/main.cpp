#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i,n) for((int)(i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inf int(2e9)
#define sz(x) int((x).size())
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()

const double eps = 1e-9;
const double pi = acos(-1.0);
typedef long long ll;


int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int T;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs){
	      int n, m, k;
	      cin >> m >> n >> k;
	      int ans = n / k + (n % k > 0) + k - 1;
	      printf("Case #%d: %d\n", cs, ans * m);
	}

	
	return 0; 
}