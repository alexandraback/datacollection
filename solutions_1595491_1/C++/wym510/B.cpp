/*
 * File: B.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-04-14 10:50:00
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

int f[200][200];

void renew(int nn,int ds,int dt,int s)
{
	for(int i=0;i<=s;i++)
		f[nn+1][i+ds]=max(f[nn+1][i+ds],f[nn][i]+dt);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);

	ios_base::sync_with_stdio(false);

	int test;

	cin>>test;
	for(int no=1;no<=test;no++)
	{
		int n,s,p;

		cin>>n>>s>>p;
		for(int i=0;i<=n+10;i++) for(int j=0;j<=s+10;j++) f[i][j]=(int)-1e9;
		f[0][0]=0;
		for(int tt=0;tt<n;tt++)
		{
			int sum;

			cin>>sum;
			for(int i=0;i<=10;i++)
				for(int j=i;j<=10;j++) if(j-i<=2)
					for(int k=j;k<=10;k++) if(k-i<=2 && i+j+k==sum)
						renew(tt,k-i==2,k>=p,s);
		}
		printf("Case #%d: %d\n",no,f[n][s]);
	}

	return 0;
}

/* vim: set ts=4 sw=4: */

