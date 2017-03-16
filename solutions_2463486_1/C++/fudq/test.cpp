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
#define int64 __int64

int64 f[45]={
		1,
		4,
		9,
		121,
		484,
		10201,
		12321,
		14641,
		40804,
		44944,
		1002001,
		1234321,
		4008004,
		100020001,
		102030201,
		104060401,
		121242121,
		123454321,
		125686521,
		400080004,
		404090404,
		10000200001ll,
		10221412201ll,
		12102420121ll,
		12345654321ll,
		40000800004ll,
		1000002000001ll,
		1002003002001ll,
		1004006004001ll,
		1020304030201ll,
		1022325232201ll,
		1024348434201ll,
		1210024200121ll,
		1212225222121ll,
		1214428244121ll,
		1232346432321ll,
		1234567654321ll,
		4000008000004ll,
		4004009004004ll
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("testin.txt","r",stdin);
	//freopen("testout.txt","w",stdout);
#endif
	int T,res,cas=1;
	int64 a,b;
	scanf("%d",&T);
	while(T--)
	{
		res=0;
		scanf("%I64d%I64d",&a,&b);
		for(int i=0;i<39;i++)
			if(f[i]<=b && f[i]>=a)
				res++;
		printf("Case #%d: %d\n",cas++,res);
	}
    return 0;
}