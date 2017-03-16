
#include <iostream>
#include <fstream>
using namespace std;

double P[100001];
double keepmoving(int a,int b,int d)
{
	double res=0;
	double tmp1=1;
	for(int i=0;i<a;i++)
		tmp1*=P[i];
	res=(b-a+1+d)*tmp1+(b-a+1+b+1+d)*(1-tmp1);
	return res;
}
int main()
{
	int T;
	int A,B;
	freopen("a4.in","r",stdin);
	freopen("a4.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>A>>B;
		for(int i=0;i<A;i++)
			cin>>P[i];
		double min=B+2;
		if(keepmoving(A,B,0)<min)
			min=keepmoving(A,B,0);
		for(int i=1;i<=A;i++)
		{
			double tmpmin=keepmoving(A-i,B,i);
			if(tmpmin<min)
			{
				min=tmpmin;
			//	cout<<i<<endl;
			}
		}
		cout<<"Case #"<<t+1<<": ";
		printf("%.6f\n",min);
	}
	
	return 0;
}
