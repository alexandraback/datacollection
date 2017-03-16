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

int main(){

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int casenum, hh;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){
		hh = 0;
		int smax;
		char c;
		int tot = 0;
		scanf("%d%c", &smax, &c);
		for (int i = 0; i <= smax; i++){
			scanf("%c", &c);
			if (hh + tot < i) hh = i - tot;
			tot += c - 48;
		}
		printf("Case #%d: %d\n", z, hh);
	}

 	return 0;

 	fclose(stdin);
 	fclose(stdout);
	
}