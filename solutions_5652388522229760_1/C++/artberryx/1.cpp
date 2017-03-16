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
		int n;
		cin>>n;
		if(!n)
		{
			printf("INSOMNIA\n");
			continue;
		}
		set<int> s;
		for(i=1;;i++)
		{
			int u=n*i;
			while(u)
			{
				s.insert(u%10);
				u/=10;
			}
			if(s.size() == 10)
			{
				printf("%d\n", n*i);
				break;
			}
		}
	}
	return 0;
}
//*/