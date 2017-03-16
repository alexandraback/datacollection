#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1000200;
int a[MAX];

int rev(int t)
{
	int inp = t;
	int k = 0;
	while (t > 0)
	{
		k = k * 10 + (t % 10);
		t /= 10;
	}
	return max(k,inp-1);
}

void precalc()
{
	a[MAX] = 0;
	a[0] = 0;


}
void solve()
{
	int n;
	cin >> n;

	a[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = a[i + 1] + 1;
		if (rev(i) > i + 1 && rev(i) <= n)
			a[i] = min(a[i], a[rev(i)] + 1);
	}
	cout << a[0];

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	precalc();
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}