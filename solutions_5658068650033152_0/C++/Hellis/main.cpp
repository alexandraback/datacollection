#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long _int64;
int work3(int m , int k)
{
	int ans = k;
	if (m >= 3 && k >= 5) ans --;
	if (m >= 4 && k >= 8) ans --;
	if (m >= 5 && k >= 11) ans --;
	if (m >= 6 && k >= 14) ans --;
	return ans;
}

int work44(int k)
{
	if (k <= 9) return work3(4, k);
	int ans = k - 2;
	if (k >= 10) ans --;
	if (k >= 12) ans --;
	return ans;
}

int work45(int k)
{
	if (k <= 12) return work44(k);
	int ans = k - 4;
	if (k >= 14) ans --;
	if (k >= 16) ans --;
	return ans;
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int cas, T;
	
	for (cas = scanf("%d", &T); cas <= T; cas++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		if (n > m) swap (n, m);
		
		printf("Case #%d: ", cas);
		if (n < 3 || k < 5) { cout << k << endl; continue ; }
		
		int ans = 0;
		if (n == 3) ans = work3(m, k);
		if (n == 4 && m == 4) ans = work44(k);
		if (n == 4 && m == 5) ans = work45(k);
		cout << ans << endl; 
	}
	
	return 0;
}
