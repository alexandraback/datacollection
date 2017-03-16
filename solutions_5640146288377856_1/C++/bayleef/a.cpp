#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T,ts,w,h,n,ans;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d%d%d",&w,&h,&n);
		ans=(w-1)*(h/n);
		ans+=h/n;
		if(h%n)
			ans+=n;
		else
			ans+=n-1;
		printf("Case #%d: %d\n",ts,ans);
	}
	return 0;
}