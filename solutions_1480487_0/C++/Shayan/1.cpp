#include <iostream>
using namespace std;

const int maxn=50000;
const double ep=0.000000001;

int s[maxn],t,n;
double d[maxn];
double high,low,kol,q,mypoint,med,best;


int main()
{
	cin >> t;
	for (int ii=1;ii<=t;ii++)
	{
		cin >> n;
		double sumd=0,sum=0;
		for (int i=1;i<=n;i++)
		{
			cin >> s[i];
			sum+=s[i];
		}
		printf("Case #%d: ",ii);
		for (int i=1;i<=n;i++)
		{
			best=1;
			low=0;
			high=1;
			while (high-low>ep)
			{
				med=(low+high)/2;
				mypoint=s[i]+(sum*med);
				kol=med;
				for (int j=1;j<=n;j++)
				{
					if (j!=i)
					{
						q=(mypoint-s[j])/sum;
						if (q>0)
						kol+=q;
					}
				}
				if (kol>=1)
				{
					if (med<best)
						best=med;
					high=med;
				}
				else
					low=med;
			}
			printf("%.6lf ",best*100);
		}
		printf("\n");
	}
	return 0;
}
