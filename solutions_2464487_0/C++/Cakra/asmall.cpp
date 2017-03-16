#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
#define INF 2000000000
#define EPS 1e-9
#define sz(c) (int) (c).size()
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define uniq(c) sort(all(c)); (c).resize(unique(all(c)) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all(c), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all(c), (x)) - (c).begin())
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;

int T, r, t;

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d%d", &r, &t);
		
		int ans = 0;
		for(int i = 1; ; i++) {
			int area = (r+2*i-1)*(r+2*i-1)-(r+2*i-2)*(r+2*i-2);
			if(area > t) break;
			t -= area;
			ans++;
		}
		
		printf("Case #%d: %d\n", tc+1, ans);
	}
	
	return 0;
}
