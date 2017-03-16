#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <float.h>
#include <time.h>
#include <queue>
#include <cstdint>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-12
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define sqr(a) (a) * (a)

using namespace std;

#define FILE "sort"
//#define OUT "put.txt"

template<class telem>telem MAX(telem a, telem b)
{
	return (a > b) ? a : b;
}

template<class telem>telem MIN(telem a, telem b)
{
	return (a < b) ? a : b;
}

template<class telem>telem GCD(telem a, telem b)
{
	return b ? GCD(b, a % b) : a;
}

template<class telem>telem LCM(telem a, telem b)
{
	return a / GCD(a, b) * b;
}

template<class telem>telem UNSIGNED(telem a)
{
	return (a > 0) ? a : a * (-1);
}

template<class telem>void bez_swop(telem &a, telem &b)
{
	telem c = a;
	a = b;
	b = c;
}

void swop(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int T;
int n;
int a, b, k;

int main()
{

#ifndef ONLINE_JUDGE
#ifdef OUT
	freopen("in"OUT, "r", stdin);
	freopen("out"OUT, "w", stdout); 
#endif

#ifdef FILE
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout); 
#endif
#endif

	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	time_t start = clock();

	scanf("%d", &T);

	for(int test = 1; test <= T; test++)
	{
		scanf("%d %d %d", &a, &b, &k);

		int ans = 0;

		printf("Case #%d: ", test);

		for(int i = 0; i < a; i++)
		{
			for(int j = 0; j < b; j++)
			{
				if((i & j) < k)
					ans++;
			}
		}

		printf("%d\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	fprintf(stderr, "\n%0.3lf\n", (clock() - start) * 1.0 / CLOCKS_PER_SEC);
#endif

	return 0;
}