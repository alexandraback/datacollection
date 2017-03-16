#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long t;
	cin >>t;
	for (long long i=0; i<t; ++i)
	{
		cout <<"Case #" <<i+1 <<":" <<endl;
		long long n;
		cin >>n;
		vector <long long> v(n);
		for (long long j=0; j<n; ++j)
			cin >>v[j];
		sort(v.begin(),v.end());
		long long res=1<<n;
		bool b=false;
		for (long long j=1; j<res/2; ++j)
		{
			long long sum=0;
			for (long long k=0; k<n; ++k)
				if (1<<k & j)
					sum+=v[k];
			long long mask=0;
			for (long long k=0; k<n; ++k)
				if (!(1<<k & j))
					mask+=1<<k;
			for (long long k=mask; k>0; k=(k-1) & mask)
			{
				long long sumn=0;
				for (long long l=0; l<n; ++l)
					if (1<<l & k)
						sumn+=v[l];
				if (sum==sumn)
				{
					for (long long l=0; l<n; ++l)
						if (1<<l & j)
							cout <<v[l] <<" ";
					cout <<endl;
					for (long long l=0; l<n; ++l)
						if (1<<l & k)
							cout <<v[l] <<" ";
					b=true;
					break;
				}
			}
			if (b)
				break;
		}
		if (!b)
				cout <<"Impossible";
		cout <<endl;
	}
	return 0;
}