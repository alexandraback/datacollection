#include <iostream>
#include <set>

using namespace std;

int war(int n, set<double> a, set<double> b)
{
	//a- Naomi
	//b- Ken
	int w = 0;
	while(!a.empty())
	{
		set<double>::iterator naomi = a.begin();
		naomi;
		double n = *naomi;
		set<double>::iterator ken =	b.upper_bound(n);
		if(ken == b.end())
		{ 
			ken = b.lower_bound(n);
			if(ken == b.end())
			{
				ken=b.begin();
			}
		}
		double k = *ken;
		
		if(n > k) w++;
		
		a.erase(naomi);
		b.erase(ken);
	}
	
	return w;
}
int deceitful_war(int n, set<double> a, set<double> b)
{
	int w = 0;
	while(!a.empty())
	{
		
		set<double>::iterator naomi = a.end();naomi--;
		set<double>::iterator ken =	b.end(); ken--;

		if(*naomi < *ken)
		{
			set<double>::iterator kenMax =	b.end(); kenMax--;
			set<double>::iterator naomiMin = a.begin();
		

			if(*naomiMin > *kenMax)
			{
					w++;
				
				a.erase(naomiMin);
				b.erase(kenMax);
			} else
			{
				a.erase(naomiMin);
				b.erase(kenMax);
			}
		} else {
			w++;
			a.erase(naomi);
			b.erase(ken);
		} 
		
	}
	return w;
}

int main()
{
	int t;
	cin>>t;
	
	for(int ti = 0; ti < t; ti++)
	{
		int n;
		cin>>n;
		
		set<double> a, b;
		double x;
		
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			a.insert(x);
		}
		for(int i = 0; i < n; i++)
		{	
			cin>>x;
			b.insert(x);
		}
		
		cout<<"Case #"<<ti+1<<": "<<deceitful_war(n, a, b)<<" "<<war(n, a, b)<<endl;
	}

	return 0;
}
