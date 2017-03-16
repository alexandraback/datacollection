#include <fstream>
#include <iostream>

using namespace std;

const int maxn=100;

int a[maxn][maxn];
int row[maxn],col[maxn];
int t,tt,n,m,i,j,f;

ifstream fin("B-large.in");
ofstream fout("B.txt");

	int minab(int a,int b)
	{
		if (a<b)
			return a;
		else
			return b;
	}

int main()
{
	fin>>t;
	for(tt=1;tt<=t;tt++)
	{
		fin>>n>>m;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				fin>>a[i][j];
		for(i=0;i<n;i++)
		{
			row[i]=0;
			for(j=0;j<m;j++)
				if (row[i]<a[i][j])
					row[i]=a[i][j];
		}
		for(i=0;i<m;i++)
		{
			col[i]=0;
			for(j=0;j<n;j++)
				if (col[i]<a[j][i])
					col[i]=a[j][i];
		}
		f=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j]!=minab(row[i],col[j]))
					f=0;
		
		fout<<"Case #"<<tt<<": ";
		if (f)
			fout<<"YES";
		else
			fout<<"NO";
		fout<<endl;
	}
	return 0;
}