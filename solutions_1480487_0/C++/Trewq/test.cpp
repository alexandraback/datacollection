#include<iostream>
using namespace std;
double J[200];
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int ts;
	cin>>ts;
	for(int cs=1;cs<=ts;cs++)
	{
		int n;
		double sum=0,t,X=0;
		cin>>n;
		int N=n;
		for(int i=0;i<n;i++)
		{
			cin>>J[i];
			X+=J[i];
		}
		sum=X;
		for(int i=0;i<n;i++)
		{
			if(J[i]>2*X/n)
			{
				N--;
				sum-=J[i];
			}
		}
		cout<<"Case #"<<cs<<':';
		for(int i=0;i<n;i++)
		{
			t=100*((X+sum)/N/X-J[i]/X);
			printf(" %.6lf",(t>0?t:0));
		}
		cout<<endl;
	}
	return 0;
}