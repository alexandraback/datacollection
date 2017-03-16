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
		string a;
		cin>>a;
		int cnt=0;
		for(i=0;i<a.size()-1;i++)
		{
			cnt+=a[i]!=a[i+1];
		}
		if(a.back() == '-') cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
//*/