#include<iostream>
using namespace std;
int main()
{	int t,n,s,p,gp,i=1,j,max,g;
	cin>>t;
	while(i<=t)
	{	cin>>n>>s>>p;
		max=0;
		for(j=1;j<=n;j++)
		{	cin>>gp;
			if(p==0)
			{	max=n;
				continue;
			}
			g=gp/3;
			if(g>=p)
					max++;
			else if(gp%3==0)
			{	
				if(g==(p-1) && g!=0)
				{	s--;
					if(s>=0)
						max++;
				}
			}
			else if(gp%3==1)
			{	if(g==(p-1))
					max++;
			}
			else if(gp%3==2)
			{	if(g==(p-1))
					max++;
				else if(g==(p-2))
				{	s--;
					if(s>=0)
						max++;
				}
			}
		}
		cout<<"Case #"<<i<<": "<<max<<endl;
		i++;
	}
	return 0;
}