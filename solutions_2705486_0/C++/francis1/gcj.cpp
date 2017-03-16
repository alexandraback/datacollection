#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#define fop freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
using namespace std;

int n,x,y;
int main()
{
	fop;
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&x,&y);
		int X,Y;
		if(x==0)X=y/2;
		else
		{
			if(x>0)x=-x;
			X=(y-x)/2;
		}
		Y=(x+2*X);
		double ans=0;
		for(int i=0;i<=X&&n;i++)
		{
			int get;
			if(4*i+1<n)
				n-=4*i+1,get=4*i+1;
			else
			{
				get=n;
				n=0;
			}
			if(i==X)
			{
				if(get==4*i+1)ans=1;
				else if(x==0)ans=0;
				else if(get-2*X>=Y+1)ans=1;
				else
				{
					double t=1;
					int cnt=get;
					for(int j=0;j<=get;j++)
					{
						if(j>=Y+1)
						{
							ans+=t;
						}
						t=t*(get-j)/(j+1);
						while(t>1e10&&cnt)
						{
							ans/=2;
							t/=2;
							cnt--;
						}
					}
					while(cnt--)ans/=2;
				}
			}
		}
		printf("Case #%d: %.10f\n",++cas,ans);
	}
}
