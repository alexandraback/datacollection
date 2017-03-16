#include<iostream>
#include<cstdio>
using namespace std;

double cal(double a,double b,double c)
{
//	cout<<"\t"<<a<<"\t"<<c<<'\n';
	return double((double)a/(double)c);
}

int main()
{

	int t,z=1;
	double c,f,x,prev,sum=0;

	cin>>t;

	while(t--)
	{
		prev = 0;
		double prev2 = 0;
		double rate = 2;
		double next =0;
		cin>>c>>f>>x;	
		sum =0;
		
		
	while(true)
	{
		
		prev = cal(x,f,rate);
		
		prev2 = cal(c,f,rate);
		next = cal(x,f,rate+f);
		//cout<<"prev"<<prev<<'\t'<<prev2<<'\t'<<rate<<'\n';
		
		//cout<<"sum_display"<<prev+sum<<'\t'<<prev2+next+sum<<'\n';
		if(sum+prev2+next < sum+prev)
			sum+=prev2;
		else
		{
			sum+=prev;
			break;
		}
		rate = rate+f;
	}

	 cout<<"Case #"<<z<<": ";
	printf("%.6f\n",sum);

z++;
	}
}
