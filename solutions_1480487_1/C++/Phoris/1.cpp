#include <iostream>
#include <iomanip>

using namespace std;

#define MAKS(X,Y) (((X)>(Y))?(X):(Y))

int main()
{
	int t;
	cin>>t;
	for(int it=1; it<=t; it++)
	{
		double n;
		cin>>n;
		double tab[300], sum=0, pn=0.0;
		double dt[300];
		bool bt[300];
		for(int i=0; i<300; i++)
		{
			tab[i]=0;
			dt[i]=0.0;
			bt[i]=0;
		}
		
		for(int i=0; i<n; i++)
		{
			cin>>tab[i];
			sum+=tab[i];
		}
		
		for(int i=0; i<n; i++)
		{
			tab[i]=tab[i]/sum;
		}
		sum=1.0;
		double np=n;
		
		etykieta:
		for(int i=0; i<n; i++)
		{
			if(tab[i]>(sum+1.0)/np && bt[i]==0)
			{
				bt[i]=1;
				sum-=tab[i];
				np-=1.0;
				goto etykieta;
			}
		}
		
		cout<<"Case #"<<it<<":";
		
		cout<<setprecision(8)<<fixed;
		for(int i=0; i<n; i++)
		{
			cout<<setprecision(6)<<fixed;
			cout<<" "<<MAKS( (1.0+sum)/np-tab[i], 0.0)*100.0;
		}
		cout<<"\n";
	}
}
