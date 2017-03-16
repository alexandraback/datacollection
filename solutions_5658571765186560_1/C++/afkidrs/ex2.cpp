#include <iostream>
#define N 4

using namespace std;
int t,x,r,c;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int aux=a%b;
		a=b;
		b=aux;
	}
	return a;
}

// ???????
int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>x;
		cin>>r;
		cin>>c;
		cout<<"Case #"<<i<<": ";
		bool winner=false;
		if((r*c)%x==0)
		{
			if(x%2==0 && x!=2)
			{
				if((r>=x && c>x/2 ) || (c>=x && r>x/2))
				{
					winner = true;
				}
			}
			else if(x==2)
			{
				if((r>=x && c>=x/2) || (c>=x && c>=x/2))
					winner = true;
			}
			else 
			{
				if((r>=x && c>x/2 ) || (c>=x && r>x/2))
				{
					winner = true;
				}
			}
		}	
		if(winner)
		{
			//cout<<"Case #"<<i<<": ";
			cout<<"GABRIEL"<<endl;
		}
		else
			cout<<"RICHARD"<<endl;
	}
	return 0;
}