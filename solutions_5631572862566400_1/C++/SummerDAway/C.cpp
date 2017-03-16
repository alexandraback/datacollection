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

int a[5100], d[5000];
int n, ans;
bool v[5000], v1[5000];


int circle(int x) {
	int ret = 0;
	memset(v, 0, sizeof(v));
	for (int i = a[x]; !v[i]; i = a[i]) {
		v[i] = true;
		ret++;
		if (a[i] == x) return ret + 1;
	}
	return 0;
}


void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, circle(i));
	}
	memset(v, 0, sizeof(v));
	memset(d, 0, sizeof(d));
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == a[a[i]] && !v[i]) {
	 		v[a[i]] = v[i] = true;
	 		now += 2;
		}
	}
	for (int i = 1; i <= n; ++i) 
	if (!v[i]) {
		memset(v1, 0, sizeof(v1));
		int len = 0;
		for (int j = i; !v1[j]; j = a[j]) {
			v1[j] = true;
			len++;
			if (v[j]) {
				d[j] = max(d[j], len-1);
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i]) now += d[i];
	}
	printf("%d\n", max(ans, now));
	
}
	
	

int main( int argc , char *argv[] )
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; ++i) {
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
