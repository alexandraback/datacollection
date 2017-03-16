#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

int main()
{
	int tests;
	double C, F, X;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		double per = 2;
		double sum = 0;
		double ans = 1e20;
		for (int x = 0; ans >= sum + X / per; x++)
		{
			ans = sum + X / per;
			sum += C / per;
			per += F;
		}
		printf("Case #%d: %.7lf\n", test, ans);
	}
}