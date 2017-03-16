#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen ("input.in","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin>>t;
	int k=0;
	while(t--)
	{
		k++;
		int x,r,c;
		cin>>x>>r>>c;
		bool f=0;
		if(x>=7)
			f=1;
		else
		{
			int i=min(r,c),j=max(r,c);
			if(i<(x+1)/2)
			{
				f=1;
			}
			else if((i*j)%x!=0)
				f=1;
		}
		cout<<"Case #"<<k<<": ";
		if(f)
			cout<<"RICHARD\n";
		else
			cout<<"GABRIEL\n";
	}
	return 0;
}