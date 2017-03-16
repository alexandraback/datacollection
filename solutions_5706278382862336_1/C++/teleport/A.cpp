#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh

ll gcd(ll a, ll b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for (int g = 1; g <= t; g++)
	{
		cout << "Case #" << g << ": ";
		ll a, b;
		scanf("%I64d/%I64d", &a, &b);
		ll nod = gcd(a, b);  
		a /= nod, b /= nod;
		
		if ((b & (b - 1)) != 0)
		{
			cout << "impossible\n";
			continue;
		}
		
		for (int i = 1; i <= 40; i++)
		{
			a *= 2;
			if (a >= b)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
