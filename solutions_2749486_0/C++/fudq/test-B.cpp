/*
 * test.cpp
 *
 *  Created on: 2013-05-12
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

void worky(int x) {
	const char *p;
	if(x == 0)
		return ;
	if(x < 0)
	{
		p = "NS";
		x = -x;
	}
	else
		p = "SN";
	while(x--)
		printf(p);
}

void workx(int x) {
	const char *p;
	if(x == 0)
		return ;
	if(x < 0)
	{
		p = "EW";
		x = -x;
	}
	else
		p = "WE";
	while(x--)
		printf(p);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
#endif
	int T, x, y;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", t);
		workx(x);
		worky(y);
		putchar('\n');
	}
    return 0;
}
