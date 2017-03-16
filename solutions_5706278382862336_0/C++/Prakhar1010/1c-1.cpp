/*
 * 1c-1.cpp
 *
 *  Created on: May 11, 2014
 *      Author: prakhar
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
int main(int a, char** v)
{
	int numCases;
	scanf("%d",&numCases);
	int i;
	for (i = 0; i < numCases; ++i) {
		int64_t p,q;
		scanf("%llu/%llu",&p,&q);
		if(q%2 != 0 || p>q)
		{
			printf("Case #%d: impossible\n",i+1);
			continue;
		}
		int64_t den = q;
		int count = 0;
		while(den)
		{
			if((den = den>>1) & 1) count++;
			if(count >1) break;
		}
		if(count >1)
		{
			printf("Case #%d: impossible\n",i+1);
			continue;
		}
		if(p==q)
		{
			printf("Case #%d: 1\n",i+1);
			continue;
		}
		int64_t ans = 0;
		while(p<q)
		{
			ans++;
			p = p*2;
		}
		printf("Case #%d: %llu\n",i+1,ans);
	}
	return 0;
}
