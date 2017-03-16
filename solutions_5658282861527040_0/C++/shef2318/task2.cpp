#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
#include <string>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

void solve(int test)
{
	int a, b, k, ans=0;
	cin>>a>>b>>k;
	for (int i=0; i<a; i++)
		for (int j=0; j<b; j++)
			ans+=((i&j)<k);
	printf("Case #%d: %d\n", test, ans);
}
int main()
{
	freopen("B-small-attempt0.txt", "r", stdin);
	freopen("B-small-ans.txt", "w", stdout);
	int test;
	cin>>test;
	for (int i=1; i<=test; i++)
		solve(i);
	return 0;
}
