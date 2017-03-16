#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#define llu long long unsigned
#define ld long
#define F first
#define S second
#define ll long long
using namespace std;
#define si(x) scanf("%d",&x)
#define sdb(x) scanf("%lf",&x)
#define sll(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define pi(x) printf("%d", x);

int main()
{
	int t,tst=1;
	si(t);
	while(t--)
	{
		int r,w,c,ans,temp;
		si(r);si(c);si(w);
		temp=(c/w)*r;
		if(c%w==0) ans=temp+w-1;
		else ans=temp+w;
		printf("Case #%d: %d\n",tst++, ans);
	}
	return 0;

}

