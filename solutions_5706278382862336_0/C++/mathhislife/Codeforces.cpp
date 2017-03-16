#define _CRT_SECURE_NO_DEPRECATE
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <complex>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

const double PI = acos(-1.0);
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int M = INF;
const double RRR = 180.0 / PI;
const long double EPS = 1e-8;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
ll n, m;
vector<ll> mas;


ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}



int main()
{
	/*
	double TIME_START = clock();
#ifndef ONLINE_JUDGE
	freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT","w",stdout);
#endif
	*/
	freopen("INPUT.TXT", "r", stdin);
	freopen("OUTPUT.TXT","w",stdout);
	


	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		cout << "Case #" << test << ": ";
		ll p, q;
		ll count = 0;
		scanf("%I64d/%I64d", &p, &q);
		while (p < q)
		{
			p *= 2;
			count++;
		}
		p -= q;
		ll d = gcd(p, q);
		p /= d;
		q /= d;
		ll mmm = ((ll)1 << (40 - count));
		p *= mmm;
		d = gcd(p, q);
		p /= d;
		q /= d;
		if (q == 1)
		{
			cout << count << endl;
		}
		else
		{
			cout << "impossible" << endl;
		}
	}
	return 0;
}