#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
int ti,T;scanf("%d",&T);
for(ti=0;ti<T;ti++)
{
	double mn[1010],mk[1010];
	int n,i,pt1,pt2,ptsw,ptsdw;
	cin>>n;
	for(i=0;i<n;i++)cin>>mn[i];
	for(i=0;i<n;i++)cin>>mk[i];
	sort(&mn[0],&mn[n]);
	sort(&mk[0],&mk[n]);
	ptsw=0;//war
	pt1=n-1;pt2=n-1;
	while(1)
	{
		if(mn[pt1]>mk[pt2])
		{
			ptsw++;
			pt1--;
		}
		else
		{
			pt1--;pt2--;
		}
		if(pt1<0)break;
	}
	
	
	ptsdw=0;//deceiteful war
	pt1=0;pt2=0;
	while(1)
	{
		if(mn[pt1]<mk[pt2])
			pt1++;
		else
		{
			ptsdw++;
			pt1++;pt2++;
		}
		if(pt1==n)break;
	
	}
	
	printf("Case #%d: %d %d\n",ti+1,ptsdw,ptsw);
}
return 0;
}