#include <iostream>
#include <cstdio>

using namespace std;


long long gcd (long long a, long long b)
{
	return (b==0) ? a : gcd(b, a%b);
}


int main ()
{

	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	cin >> t;
	
	long long pow2[42];
	pow2[0]=1;

	for (int i=1;i<42;i++)
		pow2[i]=2*pow2[i-1];


	for (int i=0;i<t;i++)
	{
		long long P,Q,d;
		char c;
		cin >> P >> c >> Q;
		
		d=gcd(P,Q);
		P/=d;
		Q/=d;

		int flag=0;

		for (int j=1;j<42;j++)
		{
			if (Q==pow2[j])
				flag=1;
		}

		if (flag==0)
		{
			cout << "Case #"<<i+1<<": "<<"impossible"<<'\n';
			continue;
		}

		else
		{	
			int tmp=1;
			for (int j=1;j<42;j++)	
			{
				if (pow2[j]>= (Q+P-1)/P )
				{
					tmp=j;
					break;
				}
			}
			cout << "Case #"<<i+1<<": "<<tmp<<'\n';		
		}
	}

}
