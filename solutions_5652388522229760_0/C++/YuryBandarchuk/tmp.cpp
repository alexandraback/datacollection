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
	int n;
	scanf("%d", &n);
	set<int> s;
	int iter = 100;
	int add = n;
	int ans = -1;
	while (iter--) {
		int x = n;
		if (x == 0) {
			s.insert(0);
		}
		while (x > 0) {
			s.insert(x % 10);
			x /= 10;
		}
		if ((int)s.size() == 10) {
			ans = n;
			break;
		}
		n += add; 
	}
	printf("Case #%d: ", test);
	if (ans == -1) puts("INSOMNIA"); else printf("%d\n", ans);
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