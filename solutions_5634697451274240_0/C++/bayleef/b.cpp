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

int T,ts;
char s[1000];
int i,ans;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%s",&s);
		for(i=0;s[i];i++);
		s[i]='+';
		s[i+1]=0;
		ans=0;
		for(i=1;s[i];i++)
			if(s[i]!=s[i-1])
				ans++;
		printf("Case #%d: %d\n",ts,ans);
	}
	return 0;
}