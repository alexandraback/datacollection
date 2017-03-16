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
char s[N];
void sol()
{
	int i, n=0;
	scanf("%s", s);
	for(i=0; s[i]; i++)
		if(i>0 && s[i]!=s[i-1]) n++;
	if(s[i-1]=='-') n++;
	printf("%d\n", n);
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		sol();
	}
	return 0;
}