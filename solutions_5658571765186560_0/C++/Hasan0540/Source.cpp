#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
bool dp[7][21][21];
int curR, curC;
bool can(int k, int R, int C){
	if (R == 0 || C == 0)
		return true;
	if (R > C)
		swap(R, C);
	if (curR == R && curC == C)
		return false;
	return dp[k][R][C];
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int k = 1; k <= 6; ++k)
	for (int R = 1; R <= 20; ++R)
	for (int C = R; C <= 20; ++C){
		dp[k][R][C] = R % k == 0 || C % k == 0;
		if (k == 3 && R == 1)
			dp[k][R][C] = false;
		if (k == 5 && R == 3 && C == 5)
			dp[k][R][C] = false;
		if (k == 6 && R <= 3)
			dp[k][R][C] = false;
		if (k >= 4 && R <= 2)
			dp[k][R][C] = false;
	}
	for (int k = 4; k <= 6; ++k)
	for (int R = 1; R <= 20; ++R)
	for (int C = R; C <= 20; ++C)
	for (int nR = 0; nR <= R; ++nR)
	for (int nC = 0; nC <= C; ++nC){
		int curR = R;
		int curC = C;
		vector<pair<int, int> > v;
		v.push_back(make_pair(nR, nC));
		v.push_back(make_pair(R - nR, nC));
		v.push_back(make_pair(nR, C - nC));
		v.push_back(make_pair(R - nR, C - nC));
		bool all = true;
		bool one = false;
		for (int i = 0; i < 4; ++i){
			if (v[i].first>v[i].second)
				swap(v[i].first, v[i].second);
			all &= v[i].first*v[i].second%k == 0;
			if (v[i].first >= (k + 1) / 2 + 1 && v[i].second >= (k + 1) / 2 + 1)
				one |= can(k, v[i].first, v[i].second);
		}
		dp[k][R][C] |= all && one;
	}
	int t, k, R, C;
	scanf("%d", &t);
	char s[2][16] = { "RICHARD", "GABRIEL" };
	for (int T = 1; T <= t; ++T){
		printf("Case #%d: ", T);
		scanf("%d%d%d", &k, &R, &C);
		if (R > C)
			swap(R, C);
		if (k >= 7)
			puts(s[0]);
		else
			puts(s[dp[k][R][C]]);
	}
	return 0;
}