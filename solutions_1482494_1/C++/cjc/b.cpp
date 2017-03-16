#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <assert.h>
#include <stack>
#include <sstream>
#include <list>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))

#define fr(x,a,b) for( int x=a; x < b; ++x )
#define frr(x,a,b) for( int x=a;x>=b;--x)

#define pf printf
#define sf scanf

#define pb push_back
#define mp make_pair


int flag[10001][2];
int a[10001],b[10001];

int main()
{
	int t;
	sf("%d",&t);
	fr(ca,0,t)
	{
		int n;
		sf("%d",&n);
		fr(i,0,n)
		{
			sf("%d %d",&a[i],&b[i]);
		}
		int now = 0;
		clr(flag);
		int ans = 0;
		while( 1 )
		{
			int ok = 0;
			fr(i,0,n)
			{
				if( flag[i][1] ) continue;
				if( now >= b[i] )
				{
					now += 2 - flag[i][0];
					flag[i][1] = 1;
					flag[i][0] = 1;
					++ans;
					ok = 1;
				}
			}
			if( ok ) continue;
			int tmp = -1;
			fr(i,0,n)
			{
				if( flag[i][1] ) continue;
				if( flag[i][0] ) continue;
				if( now >= a[i] && ( tmp == -1 || b[i] > b[tmp] ) )
				{
					tmp = i;
				}
			}
			if( tmp != -1 )
			{
				++ans;
				now++;
				flag[tmp][0] = 1;
				ok = 1;
			}
			if( !ok )break;
		}
		int ok = 1;
		fr(i,0,n)
		{
			if( flag[i][1] == 0 )
			{
				ok = 0;
				break;
			}
		}
		printf("Case #%d: ",ca+1);
		if( ok )
		{
			printf("%d\n",ans);
		}
		else
		{
			printf("Too Bad\n");
		}
	}
}
