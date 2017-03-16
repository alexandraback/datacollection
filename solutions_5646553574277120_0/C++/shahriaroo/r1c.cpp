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

int c, d, v;
int dp[101], a[101];

void add(int x){
	for (size_t j = 0; j < c; j++)
	{
		for (int k = v; k >= x; k--){
			if (dp[k - x])
				dp[k] = 1;
		}
	}
}

int main(){

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("program.out", "w", stdout);

	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		cin >> c >> d >> v;
		for (size_t i = 0; i < d; i++)
			cin >> a[i];
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (size_t i = 0; i < d; i++)
		{
			add(a[i]);
		}
		int r = 0;
		for (size_t i = 1; i <= v; i++)
		{
			if (!dp[i]){
				add(i);
				r++;
			}
		}
		printf("Case #%d: %d\n", ti,r);
	}

	return 0;
}