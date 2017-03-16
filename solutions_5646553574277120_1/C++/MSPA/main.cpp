#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

const int N = 15e5+3;
const int inf = 1e9;

using namespace std;

int a[111];

bool solve(int test)
{
	int ans = 0;
	int c,d,v, x;
	ll h=0;
	scanf("%d%d%d",&c,&d,&v);
	for (int i = 0; i < d; ++i) {
		scanf("%d",&x);
		while (h + 1 < x) {
			ans++;
			h += (h+1)*c;
		}
		h += c * x;
	}
	while (h < v) {
		ans++;
		h += (h+1)*c;
	}
	printf("Case #%d: %d\n", test, ans);
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
		solve(i+1);
	return 0;
}