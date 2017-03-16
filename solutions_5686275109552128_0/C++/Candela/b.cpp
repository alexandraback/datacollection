#include <algorithm>
#include <bitset>
#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define FT first
#define SD second
#define VI vector<int> 
#define MII map<int,int>
#define SI set<int>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long LL;
typedef long double LD;
const int INF = 0x7FFFFFFF;
const LL LINF = 0x7FFFFFFFFFFFFFFFll;

using namespace std;

int a[1111];

int main(){

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int casenum, n, hh;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int maxn = a[n - 1];
		//printf("%d\n", maxn);
		hh = maxn;
		for (int i = 1; i <= maxn; i++){
			int cutnum = 0;
			for (int j = n - 1; j >= 0; j--){
				if (a[j] <= i) break; 
				cutnum += (a[j] - 1) / i;
			}
			hh = min(hh, i + cutnum);
		}

		printf("Case #%d: %d\n", z, hh);
	}

 	fclose(stdin);
 	fclose(stdout);
	
}