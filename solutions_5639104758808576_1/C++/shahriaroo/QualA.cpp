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

int n;
char s[10001];
int main(){

	freopen("A-large.in", "r", stdin);
	freopen("program.out", "w", stdout);

	int tc,m,x,r;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		scanf("%d %s", &n, s);
		m = r = 0;
		for (int i = 0; i < n+1; i++)
		{
			x = s[i] - '0';
			if (!x)
				continue;
			if (i > m){
				r += i - m;
				m = i;
			}
			m += x;
		}
		printf("Case #%d: %d\n", ti, r);
	}

	return 0;
}