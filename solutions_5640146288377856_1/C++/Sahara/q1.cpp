# include<iostream>
# include<cmath>
using namespace std;

int main()
{
	int t;
	int a,b,c,n,m;
	cin>>t;
	for(int k=1; k<= t; k++)
	{
		cin>>a>>b>>c;
		n= a*(b/c);
		if(b%c == 0)
		{
			m = n+c-1;
		}
		else m = n+c;
		cout<<"Case #"<<k<<": "<<m<<endl;
	}	
	return 0;
}
