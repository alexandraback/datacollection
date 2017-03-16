#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int warCount(vector<long double> naomi,vector<long double> ken)
{
		/* war: ken tries to choose the smallest block that will beat naomi's */

	int ans=0;
	int n=ken.size();
		for(int i=0;i<n;++i)
		{
			bool flag=true;
			for(int j=n-1;j>=0;--j)
			{
				if(ken[j]>naomi[i])
				{
					ken[j]=-1;
					flag=false;
					break;
				}
			}
			if(flag)
				++ans;
		}
		return ans;
}

int dWarCount(vector<long double> naomi,vector<long double> ken)
{
		/* Naaoi tried to waste kens largest block at every turn */

	int ans=0;
	int n=ken.size();
		for(int i=n-1;i>=0;--i)
		{
			
			
				int j=n-1;
				/* get to ken's lowest */
				while(ken[j]<-1)
					--j;
				/* if naomi can beat it with her lowest, cheat and win*/
				if(naomi[i] > ken[j] )
				{
					ken[j]=-2;
					++ans;
				}
				/* else lose, can't cheat */
				else
				{
					// flag=false;
				}
			
		}
		return ans;
}
main(void)
{
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt)
	{
		printf("Case #%d: ",tt);

		int n;
		scanf("%d",&n);
		vector<long double> ken(n),naomi(n);
		for(int i=0;i<n;++i)
			cin>>naomi[i];
		for(int i=0;i<n;++i)
			cin>>ken[i];

		sort(ken.rbegin(),ken.rend());
		sort(naomi.rbegin(),naomi.rend());
		printf("%d %d\n",dWarCount(naomi,ken),warCount(naomi,ken));
		
	}
}