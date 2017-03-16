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

int k, n, m, mp[1001], mxc;
ll y;
double r;
char s[10001], t[10001], p[10001];
bool f[1001];
void rec(int x){
	if (x == m){
		p[m] = 0;
		int c = 0;
		for (size_t i = 0; i < m; i++)
		{
			if (strncmp(t, p + i, n) == 0)
				c++;
		}
		mxc = max(mxc, c);
		r += c / (double)y;
		return;
	}
	for (size_t i = 0; i < k; i++)
	{
		//if (!f[i]){
		p[x] = s[i];
		//f[i] = 1;
		rec(x + 1);
		//f[i] = 0;
		//}
	}
}
int main(){

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("program.out", "w", stdout);
	
	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		memset(mp, 0, sizeof mp);
		memset(f, 0, sizeof f);
		cin >> k >> n >> m;
		scanf("%s %s", s, t);
		for (size_t i = 0; i < k; i++)
			mp[s[i]]++;
		y = 1;
		for (size_t i = 0; i < m; i++)
		{
			y *= k;
		}
		r = 0;
		mxc = 0;
		rec(0);
		printf("Case #%d: %lf\n", ti, mxc - r);
	}

	return 0;
}