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

const int N = 111;

int n;
char s[N];

void solve(int test) {
	gets(s + 1);
	n = (int)strlen(s + 1);
	char lst = s[1];
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (s[i] == lst) {
			continue;
		}
		if (s[i] != lst) {
			++ans;
			lst = s[i];
			continue;
		}
	}
	if (lst == '-') {
		++ans;
	}
	printf("Case #%d: %d\n", test, ans);
}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int tc;     
  scanf("%d\n", &tc);
  for (int i = 1; i <= tc; i++) {
  	solve(i);
  }
	return 0;
}