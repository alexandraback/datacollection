/*
 * File: C.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-04-14 11:05:37
*/

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

int main()
{
	int test;

	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	ios_base::sync_with_stdio(false);
	
	cin>>test;
	for(int no=1;no<=test;no++)
	{
		int st,en,ans=0;

		cin>>st>>en;
		for(int i=st;i<=en;i++)
		{
			int tmp=i,base,k;

			for(base=10;base<=tmp;base*=10);
			base/=10;
			while(1)
			{
				k=tmp/base;
				tmp%=base;
				tmp=tmp*10+k;
				if(tmp<i && tmp>=base && st<=tmp) ans++;
				if(tmp==i) break;
			}
		}
		printf("Case #%d: %d\n",no,ans);
	}
	return 0;
}

/* vim: set ts=4 sw=4: */

