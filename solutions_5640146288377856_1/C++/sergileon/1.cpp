#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
typedef long long LL;
using namespace std;
int Cnt(int len, int w){
	if (w * 2 > len)
		return 1;
	else return 1 + Cnt(len - w, w);
}
int Calc(int len, int w)
{
	if (w == len)
		return w;
	if ( w * 2 > len)
		return w + 1;
	return 1 + Calc(len - w, w);
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	for ( int i = 0 ; i < t; i ++)
	{
		int r , c , w;
		cin >> r >> c >> w;
		printf("Case #%d: %d\n", i + 1, Calc(c,w) + (r - 1) * Cnt(c , w));
	}
	return 0;
}