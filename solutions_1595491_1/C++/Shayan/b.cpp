#include <iostream>
using namespace std;

int p,n,tedads,t;
int sgood[500][500],sbad[500][500],ugood[500][500],ubad[500][500];
int best[500][500],num[500];

int mymin(int a,int b,int c)
{
	return (min(min(a,b),c));
}

int mymax(int a,int b,int c)
{
	return (max(max(a,b),c));
}

int main()
{
	for (p=0;p<=10;p++)
	for (int i=0;i<=30;i++)
	{
		for (int k1=0;k1<=10;k1++)
			for (int k2=0;k2<=10;k2++)
				for (int k3=0;k3<=10;k3++)
				{
					if (k1+k2+k3==i)
					{
						if (mymax(k1,k2,k3)-mymin(k1,k2,k3)>2) 
							continue;
						if (mymax(k1,k2,k3)-mymin(k1,k2,k3)==2) 
						{
							if (mymax(k1,k2,k3)>=p)
								sgood[p][i]=true;
							else sbad[p][i]=true;
						}
						if (mymax(k1,k2,k3)-mymin(k1,k2,k3)<2) 
						{
							if (mymax(k1,k2,k3)>=p)
								ugood[p][i]=true;
							else ubad[p][i]=true;
						}
					}
				}
		//cout << ugood[p][i] << ' ' << sgood[p][i] << endl;
	}
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n;
		cin >> tedads;
		cin >> p;
		for (int j=1;j<=n;j++) cin >> num[j];
		best[0][0]=0;
		for (int j=1;j<=tedads;j++) best[0][j]=-99999;

		for (int j=1;j<=n;j++)
			for (int k=0;k<=tedads;k++)
			{
				best[j][k]=-9999;
			//	cout << best[j][k] << endl;
				if (k==0)
				{
					if (ugood[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k]+1);
					if (ubad[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k]);
				}
				if (k>0)
				{
					if (sgood[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k-1]+1);
					if (sbad[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k-1]);
					if (ugood[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k]+1);
					if (ubad[p][num[j]])
						best[j][k]=max(best[j][k],best[j-1][k]);
				}
			}
		cout <<"Case #" <<i <<": "<< best[n][tedads] << endl;
	}
	return 0;
}
