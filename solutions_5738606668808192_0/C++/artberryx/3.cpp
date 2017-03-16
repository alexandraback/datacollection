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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	printf("Case #1:\n");
	for(i=0;i<50;i++)
	{
		printf("11");
		for(j=0;j<6;j++)
		{
			if(i&(1<<j)) printf("11");
			else printf("00");
		}
		printf("11 ");
		for(j=2;j<=10;j++) printf("%d ", j+1);
		printf("\n");
	}
	return 0;
}
//*/