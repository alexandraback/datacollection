#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	char ans[100][100];
	for (int ii=0;ii<t;ii++)
	{
		cout<<"Case #"<<ii+1<<":\n";
		int a,b,m;
		cin>>a>>b>>m;
		bool bo=false;
		if (a>b)
		{
			int temp=a;
			a=b;
			b=temp;
			bo=true;
		}
		for (int i=0;i<a;i++)
			for (int j=0;j<b;j++)
				ans[i][j]='*';
		bool tf=true;
		if (a==1)
		{
			for (int i=0;i<b-m;i++)
				ans[0][i]='.';
			for (int i=b-m;i<b;i++)
				ans[0][i]='*';
			ans[0][0]='c';
		}
		else if (a==2)
		{
			if (m % 2==1 && m!=a*b-1 || m==a*b-2)
				tf=false;
			else
			{
				for (int i=0;i<b-m/2;i++)
				{
					ans[0][i]='.';
					ans[1][i]='.';
				}
				for (int i=b-m/2;i<b;i++)
				{
					ans[0][i]='*';
					ans[1][i]='*';
				}
				ans[0][0]='c';
			}
		}
		else if (a>2)
		{
			m=a*b-m;
			if (m==1)
				ans[0][0]='c';
			else if (m==2)
				tf=false;
			else if (m==3)
				tf=false;
			else if (m==4)
			{
				ans[0][0]='c';
				ans[0][1]='.';
				ans[1][0]='.';
				ans[1][1]='.';
			}
			else if (m==5)
				tf=false;
			else if (m==6)
			{
				for (int i=0;i<2;i++)
					for (int j=0;j<3;j++)
						ans[i][j]='.';
				ans[0][0]='c';
			}
			else if (m==7)
				tf=false;
			else if (m==8)
			{
				for (int i=0;i<3;i++)
					for (int j=0;j<3;j++)
						ans[i][j]='.';
				ans[0][0]='c';
				ans[2][2]='*';
			}
			else if (m==9)
			{
				for (int i=0;i<3;i++)
					for (int j=0;j<3;j++)
						ans[i][j]='.';
				ans[0][0]='c';
			}
			else
			{
				int aa=3;
				while ((m-1)/aa+1>b) aa++;
				int bb=(m-1)/aa+1;
				int cc=m-aa*(bb-1);
				for (int i=0;i<aa;i++)
					for (int j=0;j<bb-1;j++)
						ans[i][j]='.';
				for (int i=0;i<cc;i++)
					ans[i][bb-1]='.';
				if (cc==1)
				{	
					ans[1][bb-1]='.';
					ans[aa-1][bb-2]='*';
				}
				ans[0][0]='c';
			}
		}
		if (!tf)
			cout<<"Impossible\n";
		else
			if (bo)
				for (int i=0;i<b;i++)
				{
					for (int j=0;j<a;j++)
					cout<<ans[j][i];
					cout<<"\n";
				}
			else
				for (int i=0;i<a;i++)
				{
					for (int j=0;j<b;j++)
					cout<<ans[i][j];
					cout<<"\n";
				}
	}
}