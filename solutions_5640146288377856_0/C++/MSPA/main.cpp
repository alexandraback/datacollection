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

bool solve(int test)
{
	int n,m,w;
	scanf("%d%d%d",&n,&m,&w);
	printf("Case #%d: %d\n", test, n*(m+w-1)/w + w-1);
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