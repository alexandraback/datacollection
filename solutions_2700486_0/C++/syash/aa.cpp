#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


long double fact(long x)
{
	long double ans=1;
	long i;
	for (i=1;i<=x;i++)
		ans = ans*i;
	return ans;
}

long sum(long x)
{
	long i, ans=0;
	for (i=1;i<=x; i++)
		ans+=i;
	return ans;
}

void main() {



	ifstream in;
	ofstream out;
	out.open("out.txt");
	in.open("input.txt");
	long T;
	long N, x,y;
	long need, pyramid;
	long double pr;
	long n,k,kk;


	in >> T;

	for (int i=0; i<T; i++)
	{
		in >> N >> x >> y;
		pyramid = sum(abs(x)+y+1);
		if (pyramid <= N)
		{
			pr = 1;
		}
		else
		{
			if (sum(abs(x)+y-1) >= N)
				pr=0;
			else
			{

				n = N-sum(abs(x)+y-1);
				k = y+1;
				if (x==0)
				{
					if (y*2+1<=n)
						pr=1;
					else
						pr=0;
				}
				else
				{
					if (n>=pyramid+k)
						pr=1;
					else
					{


					pr=0;
					if (k<=n)
					{
						for (kk=k; kk<=n; kk++)
						{
							pr+=((fact(n)) / (fact(n-kk)*fact(kk)));
						}
						for (kk=0;kk<n;kk++)
						{
							pr = pr/2;
						}
					}
					}
				}

			}
		}
		out << "Case #" << i+1 << ": " << pr << endl;
	}

	in.close();
	out.close();

}


