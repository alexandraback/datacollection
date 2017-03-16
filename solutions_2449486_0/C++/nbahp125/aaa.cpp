#include "stdafx.h"

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	int t,n,m,i,j;
	cin>>t;
	int a[100][100];
	bool b[100][100],c[100][100];
	ofstream file;
	file.open("d:\\aa.txt");
	for(int times=1;times<=t;times++)
	{
		cin>>m>>n;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int mi[100]={},mj[100]={};
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>mi[i])
					mi[i]=a[i][j];
				if(a[i][j]>mj[j])
					mj[j]=a[i][j];
			}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				if(a[i][j]<mi[i])
					b[i][j]=1;
				if(a[i][j]<mj[j])
					c[i][j]=1;
			}
		bool p=1;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(b[i][j]&&c[i][j])
					p=0;
		file<<"Case #"<<times<<": ";
		if(p)
			file<<"YES"<<endl;
		else
			file<<"NO"<<endl;

	}
	return 0;
}