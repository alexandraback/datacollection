//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

int a[100], b[100];
int n, ans;
bool v[100];

void dfs(int m) {
	bool update = true;
	for (int i = 0; i < m; ++i) {
		int l, r;
		l = (i-1+m)%m;
		r = (i+1)%m;
		if (!(a[b[i]] == b[l] || a[b[i]] == b[r])) {
			update = false;
			break;
		}
	}
	if (update) ans = max(ans, m);
	for (int i = 1; i <= n; ++i)
	if (!v[i]) {
		b[m] = i;
		v[i] = true;
		dfs(m + 1);
		v[i] = false;
	}
}

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		b[0] = i;
		v[i] = true;
		dfs(1);
		v[i] = false;
	}
	printf("%d\n", ans);
}
	
	

int main( int argc , char *argv[] )
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; ++i) {
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
