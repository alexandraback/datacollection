#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <functional>
#include <time.h>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define double long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define piii pair<int, pair<int, int> >
#define plll pair<ll, pair<ll, ll> >
 
 

 
ll EPS = 1000000007;
double PI = 3.14159265358979323846;
const int MAXN = 1000010;
 
 


ll abss(ll h)
{
	return max(h, -h);
}
 
 
double fabss(double h)
{
	return max(h, -h);
}
 
ll ceill(ll x, ll y)
{
	if (x % y != 0)
	{
		return (x / y) + 1;
	}
	return x / y;
}
 
string itos(ll num)
{
	string str = "";
	if (num == 0)
	{
		return "0";
	}
	while (num != 0)
	{
		str += ((num % 10) + '0');
		num /= (ll)10;
	}
	reverse(str.begin(), str.end());
	return str;
}


ll n, m, k, r, t, q, x, y;


int a[MAXN];
int b[MAXN];
int c[MAXN];



int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	cin >> t;
	int r, c, w;
	for (int y = 0; y < t; y++)
	{
		cin >> r >> c >> w;
		int count = r*(c/w) + w - (c % w == 0);
		cout << "Case #" << y + 1 << ": " << count << endl;
	}

}