#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int n,s,p;
		cin>>n>>s>>p;
		
		int t[n];
		for(int i=0;i<n;i++)
			cin>>t[i];

		int res=0,ans=0;
		for(int i=0;i<n;i++)
		{	
			int x=t[i];
			
			int chk1=1,chk2=1;
			for(int j=0;j<=x;j++)
			{
				for(int k=j;k<=j+2;k++)
				{
					for(int l=j;l<=j+2;l++)
					if(j+k+l==x)
					{
						if(k!=j+2 and l!=j+2 and max(j,max(k,l))>=p)chk1=0;
						if(((k==j+2) or (l==j+2)) and max(j,max(k,l))>=p)chk2=0;	
					}
				}
			}
			if(!chk1)ans++;
			else if(!chk2 and res<s)res++;
		}
		printf("Case #%d: %d\n",tt,ans+res);
	}
	return 0;
}
