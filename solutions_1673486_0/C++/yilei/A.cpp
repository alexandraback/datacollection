#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int A,B;
	double p[5];
	double pro[10];
	double res[10][5];
	int cnt[10][5];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>A>>B;
		for (int j=0;j<A;j++)
		{
			cin>>p[j];
		}
		int num=(int)pow(2.0,A);
		if (A==1)
		{
			pro[0]=p[0];
			pro[1]=1-p[0];

			cnt[0][0]=B;
			cnt[0][1]=1+B+1;
			cnt[0][2]=1+B+1;

			cnt[1][0]=B+B+1;
			cnt[1][1]=1+B+1;
			cnt[1][2]=1+B+1;
		}

		else if (A==2)
		{
			pro[0]=p[0]*p[1];
			pro[1]=p[0]*(1-p[1]);
			pro[2]=(1-p[0])*p[1];
			pro[3]=(1-p[0])*(1-p[1]);

			cnt[0][0]=B-1;
			cnt[0][1]=1+B;
			cnt[0][2]=1+B+1;

			cnt[1][0]=B-1+B+1;
			cnt[1][1]=1+B;
			cnt[1][2]=1+B+1;

			cnt[2][0]=B-1+B+1;
			cnt[2][1]=1+B+B+1;
			cnt[2][2]=1+B+1;

			cnt[3][0]=B-1+B+1;
			cnt[3][1]=1+B+B+1;
			cnt[3][2]=1+B+1;
		}
		else if (A==3)
		{		

			pro[0]=p[0]*p[1]*p[2];
			pro[1]=p[0]*p[1]*(1-p[2]);
			pro[2]=p[0]*(1-p[1])*p[2];
			pro[3]=p[0]*(1-p[1])*(1-p[2]);

			pro[4]=(1-p[0])*p[1]*p[2];
			pro[5]=(1-p[0])*p[1]*(1-p[2]);
			pro[6]=(1-p[0])*(1-p[1])*p[2];
			pro[7]=(1-p[0])*(1-p[1])*(1-p[2]);

			cnt[0][0]=B-2;
			cnt[0][1]=1+B-1;
			cnt[0][2]=1+B+1;

			cnt[1][0]=B-2+B+1;
			cnt[1][1]=1+B-1;
			cnt[1][2]=1+B+1;

			cnt[2][0]=B-2+B+1;
			cnt[2][1]=1+B-1+B+1;
			cnt[2][2]=1+B+1;

			cnt[3][0]=B-2+B+1;
			cnt[3][1]=1+B-1+B+1;
			cnt[3][2]=1+B+1;

			cnt[4][0]=B-2+B+1;
			cnt[4][1]=1+B-1+B+1;
			cnt[4][2]=1+B+1;

			cnt[5][0]=B-2+B+1;
			cnt[5][1]=1+B-1+B+1;
			cnt[5][2]=1+B+1;

			cnt[6][0]=B-2+B+1;
			cnt[6][1]=1+B-1+B+1;
			cnt[6][2]=1+B+1;

			cnt[7][0]=B-2+B+1;
			cnt[7][1]=1+B-1+B+1;
			cnt[7][2]=1+B+1;

		}
		double mini=B+10;
		for (int k=0;k<3;k++)
		{
			double res=0;
			for (int j=0;j<num;j++)
				res+=pro[j]*cnt[j][k];
			if (res<mini)
				mini=res;
		}
		printf("Case #%d: %.6f\n",i,mini);
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}