#include<iostream>

using namespace std;

int main()
{
	int t,s[200],y,n;
	double avg,req,frc;
	int i,j,x,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cout<<"\nCase #"<<(i+1)<<": ";
		y = 0;
		for(j=0;j<n;j++)
		{
			cin>>s[j];
			y = y + s[j];
		}
		avg = 2.0 * y / n;
		x = n;
		z = 0;
		for(j=0;j<n;j++)
			if(s[j]>avg)
			{
				z = z + s[j];
				x--;
			}
		avg = ((2.0 * y) - z) / x;
		for(j=0;j<n;j++)
		{
			if(s[j]>=avg)
				frc = 0.0;
			else
			{
				req = avg - s[j];
				frc = req / y;
				frc = frc * 100.0;
			}
			printf("%f ",frc);
		}
	}
	return 0;
}
			
