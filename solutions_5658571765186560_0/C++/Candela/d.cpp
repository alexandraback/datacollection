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

int a[4][4][4]={
{{1, 2, 1, 2}, {2, 2, 2, 2}, {1, 2, 1, 2}, {2, 2, 2, 2}},   
{{2, 1, 1, 2}, {1, 2, 2, 1}, {1, 2, 2, 2}, {2, 1, 2, 1}},    
{{2, 2, 1, 1}, {2, 1, 2, 2}, {1, 2, 2, 1}, {1, 2, 1, 1}},
{{2, 2, 2, 1}, {2, 1, 1, 1}, {2, 1, 2, 2}, {1, 1, 2, 2}}};

int main(){

	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	
	int x,y,z,casenum, hh;
	scanf("%d", &casenum);
	for (int i = 1; i <= casenum; i++){
		scanf("%d%d%d", &x, &y, &z);
		hh = a[x - 1][y - 1][z - 1];
		if (hh == 1) printf("Case #%d: RICHARD\n", i);
		else printf("Case #%d: GABRIEL\n", i);
	}

 	fclose(stdin);
 	fclose(stdout);
	
}