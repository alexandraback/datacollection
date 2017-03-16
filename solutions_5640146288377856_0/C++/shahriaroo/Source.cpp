/*	In the name of God	*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;


int main(){

	freopen("A-small-attempt2.in", "r", stdin);
	freopen("program.out", "w", stdout);

	int tc;
	int r, c, w;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		cin >> r >> c >> w;
		int ans = r*(c / w)+w-1;
		if (c%w)
			ans++;
		printf("Case #%d: %d\n", ti,ans);
	}

	return 0;
}