#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory.h>
#include <cassert>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;


void solve(int test) {
	printf("Case #%d: ", test);
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
	if (k - 1 > s) {
		puts("IMPOSSIBLE");
		return;
	}
	if (k > 1 && s == 1) {
		puts("IMPOSSIBLE");
		return;
	}
	if (c == 1 && k > s) {
		puts("IMPOSSIBLE");
		return;
	}
	if (s == k) {
		for (int i = 1; i <= s; i++) {
			printf("%d", i);
			if (i == s) puts(""); else printf(" ");
		}
		return;
	}
	long long almost = 1LL;
	for (int i = 1; i < c; i++) {
		almost = almost * 1LL * k;
	}
	for (int i = 1; i < k; i++) {
		cout << 1LL * i * almost;
		if (i == k - 1) cout << endl; else cout << " ";
	}
}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int tc;     
  scanf("%d", &tc);
  for (int i = 1; i <= tc; i++) {
  	solve(i);
  }
	return 0;
}