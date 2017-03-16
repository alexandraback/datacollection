#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int A,B;
	double p[100000];
	double cor[100000];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>A>>B;
		for (int j=0;j<B;j++)
			cor[j]=1;
		for (int j=1;j<=A;j++)
		{
			cin>>p[j];
			cor[j]=cor[j-1]*p[j];
		}
		int num=(int)pow(2.0,A);
		double mini=B+2;
		for (int k=0;k<=A;k++)
		{
			double res=0;
			res = cor[A-k]*(k+B-(A-k)+1)+(1-cor[A-k])*(k+B-(A-k)+1+B+1);
			if (res<mini)
				mini=res;
		}
		printf("Case #%d: %.6f\n",i,mini);
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}