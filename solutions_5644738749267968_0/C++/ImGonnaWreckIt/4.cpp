#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
#include <iomanip>

using namespace std;

int main()
{
	int i,j,k;
	int T;
	int N;
	double *a,*b;
	int min;
	double temp;
	ifstream ip("D-small-attempt1.in");;
	ofstream op("output.txt");
	ip>>T;
	for(k=1;k<=T;k++)
	{
		op<<"Case #"<<k<<": ";
		ip>>N;
		a=(double *)malloc(sizeof(double)*N);
		b=(double *)malloc(sizeof(double)*N);
		for(i=0;i<N;i++)
			ip>>a[i];
		for(j=0;j<N;j++)
			ip>>b[j];
		for(i=0;i<N;i++)
		{
			min=i;
			for(j=i+1;j<N;j++)
			{
				if(a[j]<a[min])
					min=j;
			}
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}	
		
		for(i=0;i<N;i++)
		{
			min=i;
			for(j=i+1;j<N;j++)
			{
				if(b[j]<b[min])
					min=j;
			}
			temp=b[min];
			b[min]=b[i];
			b[i]=temp;
		}
	
		i=j=min=0;
		for(i=0;i<N;i++)
		{
			if(a[i]>b[j])
			{
				min++;
				j++;
			}
		}
		op<<min<<" ";
		j=min=0;
		for(i=0;i<N;i++)
		{
			if(b[i]>a[j])
			{
				min++;
				j++;
			}
		}
		op<<N-min<<"\n";
		//free(a);
		//free(b);
	}
	return 0;
}
