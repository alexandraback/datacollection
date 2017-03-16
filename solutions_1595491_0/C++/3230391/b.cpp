# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
using namespace std;
int main (void)
{
	int t,n,s,p,x,ys=0,max;
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n>>s>>p;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			cin>>x;
			max=-1;
			if (x%3==2)
			{
				if (x>1)
					max=(x-2)/3+1;
			}
			else 
				if (x%3==1)
				{
					if (x)
						max=(x-1)/3+1;
				}
				else max=x/3;
			if (max>=p)
				ans++;
			else
			{
				if (s)
				{
					max=-1;
					if (x%3==2)
					{
						if (x>1)
							max=(x+4)/3;
					}
					else
						if (x%3==1)
						{
							if (x>3)
								max=(x+2)/3;
						}
						else
						{
							if (x>2)
								max=(x+3)/3;
						}
					if (max>=p)
					{
						ans++;
						s--;
					}
				}
			}
		}
		printf("Case #%d: %d\n",++ys,ans);
	}
	return 0;
}
