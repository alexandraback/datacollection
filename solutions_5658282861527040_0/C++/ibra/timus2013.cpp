#include <cstdio>
#include <vector>
#include<cmath>
#include<ctime>
#include<sstream>
#include <algorithm>
#include<iostream>
#include<set>
#include <cstring>
#include<string>
#include<map>
#include<queue>
#include <cassert>
using namespace std;
typedef unsigned long long ull;
int nextint(){int a;scanf("%d",&a);return a;}
const double EPS = 1e-6;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		int a = nextint();
		int b = nextint();
		int k = nextint();
		int res = 0;
		for(int i = 0; i < a; i++)
		{
			for(int j = 0; j < b; j++)
			{
				if((i&j)<k)
				{
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", test, res);
	}

	return 0;
}