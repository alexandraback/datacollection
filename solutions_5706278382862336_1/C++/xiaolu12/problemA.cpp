//#define CMD
#ifdef CMD
#include <iostream>
#else
#include <fstream>
#endif

using namespace std;

#ifndef CMD
ifstream cin;
ofstream cout;
#endif

typedef long long BigInt;

BigInt maxCommon(BigInt p, BigInt q)
{
	BigInt y = q % p;
	while(y != 0)
	{
		q = p;
		p = y;
		y = q % p;
	}
	return p;
}

bool IsBinary(BigInt q)
{
	while(q != 1)
	{
		if(q % 2 == 1)
		{
			return false;
		}
		q = q / 2;
	}
}

int findMinParent(BigInt p, BigInt q)
{
	int k = 0;
	while(p < q)
	{
		q = q / 2;
		k++;
	}
	return k;
}


int main()
{
#ifndef CMD
	cin.open("A-large.in");
	cout.open("A-large.out");
#endif
	int t;
	cin>>t;
	BigInt p,q;
	char ch;
	for(int i=1; i<=t; ++i)
	{
		cin>>p>>ch>>q;
		BigInt com = maxCommon(p, q);
		p = p / com;
		q = q / com;
		if(IsBinary(q))
		{
			int k = findMinParent(p,q);
			cout<<"Case #"<<i<<": "<<k<<endl;
		}
		else
		{
			cout<<"Case #"<<i<<": "<<"impossible"<<endl;
		}
		
	}
	return 0;
}