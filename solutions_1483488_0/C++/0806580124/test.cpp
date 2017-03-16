#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
set <int> ha;
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,l,r,t,p,co=1;
	int a[10],s,ss,len,ans;
	scanf("%d",&t);
	while (t--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for (s=l;s<=r;s++)
		{
			ha.clear();
			ss=s;
			len=0;
			p=1;
			while (ss>0)
			{
				a[len++]=ss%10;
				ss/=10;
				p*=10;
			}
			p/=10;
			ss=s;
			for (i=0;i<len;i++)
			{
				ss=ss/10+a[i]*p;
				if (ss<=r&&ss>=l&&a[i]!=0&&s<ss&&ha.find(ss)==ha.end())
					ha.insert(ss);
			}
			ans+=ha.size();
		}
		printf("Case #%d: %d\n",co++,ans);
	}
	return 0;
}