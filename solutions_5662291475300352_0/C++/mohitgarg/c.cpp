#include <iostream>

using namespace std;

int main()
{
	long long int t,tt,n,d[101],no[101],m[101],i,ans;
	double ti,dist;
	cin>>t;
	tt=1;
	while (tt<=t)
	{
		cin>>n;
		for (i=0;i<n;i++)
		{
			cin>>d[i]>>no[i]>>m[i];
		}
		if (n==1)
		{
			cout<<"Case #"<<tt<<": "<<0<<endl;
		}
		else
		{
			ans=2;
			if (d[0]>d[1])
			{
				d[2]=d[0];
				d[0]=d[1];
				d[1]=d[2];
				no[2]=no[0];
				no[0]=no[1];
				no[1]=no[2];
				m[2]=m[0];
				m[0]=m[1];
				m[1]=m[2];
			}
			ti=(360-d[0])/m[0];
			dist=ti*d[1];
//			if (dist<(360-d[i]) or dist>(360+(360-d[i])))
//			if (m[0]==m[1])
//					ans=0;				
			if (m[0] < m[1])
			{
				ti=((360-d[0])*m[0])/360.0;
				dist=(360.0*ti)/m[1];
				double defe=(360.0*ti)/m[0];
	//			cout<<m[0]<<" "<<m[1]<<" "<<ti<<" "<<dist<<" "<<d[0]<<" "<<d[1]<<" "<<defe<<endl;
				if (dist > 360-d[1])
					ans=0;
				else
				{
					d[0]=0;
					d[1]+=dist;

					ti=((360-d[1])*m[1])/360.0;
					dist=(360.0*ti)/m[0];
					if (dist>=360)
						ans=1;
					else
						ans=0;
//					ans=-11;
				}
			}
			else
			{
				ti=((360-d[0])*m[0])/360.0;
				dist=(360.0*ti)/m[1];
				if (dist>=360+(360-d[1]))
					ans=1;
				else
					ans=0;
			}
			cout<<"Case #"<<tt<<": "<<ans<<endl;
		}
		tt+=1;
	}
	return 0;
}