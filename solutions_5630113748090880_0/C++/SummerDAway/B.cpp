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

int a[5000];

void work() {
	int n;
	scanf("%d", &n);
	int N = (n << 1) - 1;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			a[x]++;
		}
	}
	for (int i = 0; i <= 3000; ++i) {
		if (a[i] & 1) printf(" %d", i);
	}
	printf("\n");
}
	
		
		

int main( int argc , char *argv[] )
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; ++i) {
		printf("Case #%d:", i);
		work();
	}
	return 0;
}
