#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
#define N 100100

void sol()
{
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
	for(int i=0; i<k; i++)
	{
		printf(" %d", i+1);
	}
	printf("\n");
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d:", t);
		sol();
	}
	return 0;
}