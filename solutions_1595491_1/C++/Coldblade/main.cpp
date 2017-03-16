#include<iostream>

using namespace std;

int main()
{
	int t, n, s, p, x;
	int ptot, psup, count, sup;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		count=0;
		sup = 0;
		cin>>n>>s>>p;		
		if(p>=2)
		{
			ptot=3*p-2;
			psup=ptot-2;
			for(int j=0; j<n; j++)
			{
				cin>>x;
				if(x >= ptot)
					count++;
				else if(x >= psup)
					sup++;
			}
		count=sup>s?count+s:count+sup;
		cout<<"Case #"<<i+1<<": "<<count<<"\n";
		}		
		else if(p==1)
		{
			for(int j=0; j<n; j++)
			{
				cin>>x;
				if(x)
				count++;
			}
			cout<<"Case #"<<i+1<<": "<<count<<"\n";
		}
		else
		{
			for(int j=0; j<n; j++)
			cin>>x;
			cout<<"Case #"<<i+1<<": "<<n<<"\n";
		}	
	}
}
