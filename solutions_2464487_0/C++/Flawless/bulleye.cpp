// Shashank Jain
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define LL long long int
#define LD long double
using namespace std;
int main()
{
	int tc,ans,i;
	LD r,t,paint;
	scanf("%d",&tc);
	i=1;
	while(i<=tc)
	{
		cin>>r>>t;
		ans=0;
		while(t>0)
		{
			paint=((r+1)*(r+1))-(r*r);
			if(paint<=t)
			{
				ans++;
				t-=paint;			
			}
			else
				break;
			r+=2.0;						
		}
		printf("CASE #%d: %d\n",i,ans);
		i++;
	}
	return 0;
}
