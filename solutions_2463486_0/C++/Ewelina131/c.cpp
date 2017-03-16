#include<iostream>
using namespace std;

int main()
{
	int n, x, a, b, p[5];
	cin>>n;
	p[0]=1;
	p[1]=4;
	p[2]=9;
	p[3]=121;
	p[4]=484;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>b;
		x=0;
		for(int j=0; j<5; j++)
		{
			if(a<=p[j] && p[j]<=b)
			x++;
		}
		cout<<"Case #"<<i<<": "<<x<<"\n";
	}
	return 0;
}
		
