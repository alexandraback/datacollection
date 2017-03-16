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

const int N = 1e5+3;
const int inf = 1e9;

using namespace std;

bool us[N];

void upd(int v, int x)
{
	for (int i = v; i>=0; --i)
		if (us[i] && i + x <= v)
			us[i + x] = 1;
			
}

bool solve(int test)
{
	int ans = 0;
	memset(us, 0, sizeof(us));
	us[0] = 1;
	int c,d,v;
	scanf("%d%d%d",&c,&d,&v);
	for (int i = 0; i < d; ++i) {
		int x;
		scanf("%d", &x);
		upd(v, x);
	}
	
	for (int i = 1; i <= v; ++i)
		if (!us[i]) {
			ans++;
			upd(v, i);
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