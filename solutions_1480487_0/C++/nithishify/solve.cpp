#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	int N,i,j,k,T,l;
	int *points,count;
	double *aud,min,neg;
	double total;
		
	ifstream ip("A-small-attempt3.in");
	ofstream op("write.txt");
	op.precision(6);
	op.setf(ios::fixed,ios::floatfield);
	ip>>T;
	for(i=0;i<T;i++)
	{
		ip>>N;
		points=new int[N];
		aud=new double[N];
		for(j=0;j<N;j++)
			ip>>points[j];
		total=0;
		count=N;
		neg=0;
		for(j=0;j<N;j++)
			total=total+points[j];
		total=total*2;
		min=total/N;
		for(j=0;j<N;j++)
		{
			aud[j]=(double)(min-points[j]);
			aud[j]=aud[j]*100/(double)(total/2);
			if(aud[j]<0)
			{
				count--;
				neg=neg-aud[j];
			}
		}
		if(count!=N)
			neg=neg/count;		
		if(count!=N)
			for(j=0;j<N;j++)
			{
				if(aud[j]<0)
				{
					aud[j]=0;
					continue;
				}
				aud[j]=aud[j]-neg;		
			}
		op<<"Case #"<<i+1<<": ";
		for(j=0;j<N;j++)
		{
			op<<aud[j]<<" ";
		}
		op<<"\n";
		delete points;
		delete aud;
	}
	ip.close();
	op.close();
	return 0;
}
