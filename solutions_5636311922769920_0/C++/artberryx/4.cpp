//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll po[100];

int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		printf("Case #%d: ", T);
		ll n, m, p;
		cin>>n>>m>>p;
		ll u=max(n-m+1, 1ll);
		if(p < u)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		po[0]=1;
		for(i=1;i<100;i++) po[i]=po[i-1]*n;
		ll base=0;
		for(i=0;i<n-u;i++)
		{
			base+=i*po[m-i-1];
		}
		for(i=n-u;i<n;i++) printf("%lld ", base+i+1);
		cout<<endl;
	}
	return 0;
}
//*/