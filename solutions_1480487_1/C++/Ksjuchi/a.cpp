#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int s[300];
double res[300];

bool comp(pii a,pii b)
{
	if (a.first>b.first) return true;
	return false;
}

int main()
{
	vector<pii> s(250);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t,x,n,cur;
	double p;
	cin >> t;
	for (int cnt=1;cnt<=t;cnt++)
	{
		x=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&s[i].first);
			s[i].second=i;
			x+=s[i].first;
		}
		sort(s.begin(),s.begin()+n);
		for (int i=0;i<n;i++)
		{
			cur=0;
			p=0;
			for (int j=0;j<i;j++)
				cur+=s[i].first-s[j].first;
			if (cur<x)
			{
			for (int j=i+1;j<n;j++)
			{
				if (cur+j*(s[j].first-s[j-1].first)<=x)
				{
					cur+=(s[j].first-s[j-1].first)*j;
					p+=(s[j].first-s[j-1].first);
				}
				else
				{
					p+=(double)(x-cur)/j;
					cur=x;
					break;
				}
			}
			}
			if (cur<x)
				p+=(double)(x-cur)/n;
			res[s[i].second]=100*p/x;
		}
		printf("Case #%d: ",cnt);
		for (int i=0;i<n;i++)
			printf("%0.6f ",res[i]);
		printf("\n");
	}
	return 0;
}