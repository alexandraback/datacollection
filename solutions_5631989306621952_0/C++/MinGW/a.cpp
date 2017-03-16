#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=2007;

int i,j,k,n,m,t,x,y,tcase,xcase;
int mx[MAXN];
bool f[MAXN];
char c[MAXN];
string s;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&tcase);
	xcase=0;
	while (xcase<tcase)
	{
		xcase++;
		memset(mx,0,sizeof(mx));
		memset(f,0,sizeof(f));
		s="";
		scanf("%s",&c);
		n=strlen(c);
		mx[0]=0;
		for (i=1;i<n;i++)
		{
			if (c[i]>=c[mx[i-1]])
			{
				mx[i]=i;
			}
			else
			{
				mx[i]=mx[i-1];
			}
		}
		i=n-1;
		while (i>=0)
		{
			s+=c[mx[i]];
			f[mx[i]]=true;
			i=mx[i]-1;
		}
		for (i=0;i<n;i++)
		{
			if(!f[i])
			{
				s+=c[i];
			}
		}
		cout<<"Case #"<<xcase<<": "<<s<<endl;
	}
	return 0;
}

