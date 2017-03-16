#include <iostream>
using namespace std;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin>>T;
	for (int qq=1;qq<=T;qq++)
	{
		int a[101][101]={0};
		int b[101][101]={0};
		int n,m;
		cin >>n>>m;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				cin >> a[i][j];
				b[i][j]=0;
			}
		}
		for (int i=0;i<n;i++)
		{
			int h=0;
			for (int j=0;j<m;j++)
			{
				if (h<a[i][j]) h=a[i][j];
			}
			for (int j=0;j<m;j++)
			{
				if (h==a[i][j]) b[i][j]=1;
			}
		}
		for (int i=0;i<m;i++)
		{
			int h=0;
			for (int j=0;j<n;j++)
			{
				if (h<a[j][i]) h=a[j][i];
			}
			for (int j=0;j<n;j++)
			{
				if (h==a[j][i]) b[j][i]=1;
			}
		}
		cout << "Case #"<< qq<< ": ";
		bool flag=true;
		for (int i=0;i<n;i++)
		{
			int j;
			for (j=0;j<m;j++)
			{
				if (b[i][j]==0) {flag=false; cout << "NO"<<endl;break;}
			}
			if (!flag) {break;}
		}
		if (flag) cout <<"YES"<<endl;


	}


	return 0;
}