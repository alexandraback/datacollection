/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int V = 100100;
char s[V];
int _, n;
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d", &n);
		scanf("%s", s);
		int ret = 0;
		int pre = 0;
		for(int i = 0; i <= n; ++i)
		{
			if(pre < i)
			{
				ret += i - pre;
				pre = i;
			}
			pre += s[i] - '0';
		}
		printf("Case #%d: %d\n", ca, ret);
	}
	return 0;
}
