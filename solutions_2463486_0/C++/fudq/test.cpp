/*
 * test.cpp
 *
 *  Created on: 2013-04-13
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

int main()
{
	int T,res,a,b,cas=1;
	int f[10]={1,4,9,121,484};
	scanf("%d",&T);
	while(T--)
	{
		res=0;
		scanf("%d%d",&a,&b);
		for(int i=0;i<5;i++)
			if(f[i]<=b && f[i]>=a)
				res++;
		printf("Case #%d: %d\n",cas++,res);
	}
    return 0;
}