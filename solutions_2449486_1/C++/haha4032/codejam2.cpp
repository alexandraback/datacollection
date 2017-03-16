// codejam2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int s[100][100];
int p[100];
int q[100];

int main()
{
	ofstream fout("d:\\out.txt");
	ifstream fin("d:\\in.txt");
	int t(0);
	fin>>t;
	for (int i=0;i<t;++i)
	{
		bool ans = true;
		int n,m;
		fin>>n;
		fin>>m;
		for(int u=0;u<n;++u)
			for(int v=0;v<m;++v)
				fin>>s[u][v];
		//row
		for(int k=0;k<n;++k)
		{
			int  max(0);
			for(int u=0;u<m;++u)
				if (s[k][u]>max)
					max = s[k][u];
			p[k] = max;
		}
		//column
		for(int k=0;k<m;++k)
		{
			int max(0);
			for(int u=0;u<n;++u)
				if (s[u][k]>max)
					max = s[u][k];
			q[k] = max;
		}
		for(int u=0;u<n;++u)
			if (ans)
			{
				for(int v=0;v<m;++v)
					if (p[u]>s[u][v] && q[v]>s[u][v])
					{
						ans = false;
						break;
					}
			}
		if (ans)
			fout<<"Case #"<<i+1<<": YES"<<endl;
		else
			fout<<"Case #"<<i+1<<": NO"<<endl;
	}
	return 0;
}