#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("a.in");
	fout.open("a.out");
	int tr,rnd,m,n,i,j;
	double min,now;
	double a[100001],c[100001];
	fin>>tr;
	fout<<fixed<<setprecision(6);
	for (rnd=1;rnd<=tr;rnd++)
	{
		fin>>m>>n;
		for (i=1;i<=m;i++)
			fin>>c[i];
		a[0]=1.0;
		for (i=1;i<=m;i++)
			a[i]=a[i-1]*c[i];
		for (i=0;i<m;i++)
			a[i]=a[i]-a[i+1];
		min=n+2;
		for (i=0;i<=m;i++)
		{
			now=0.0;
			for (j=0;j<=m;j++)
				if (j>=i)
					now=now+a[j]*(m-i+n-i+1);
				else
					now=now+a[j]*(m-i+n-i+n+2);
			if (now<min)
				min=now;
		}
		fout<<"Case #"<<rnd<<": "<<min<<endl;
	}
	fin.close();
	fout.close();
}