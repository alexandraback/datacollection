#include <stdio.h>
#include <fstream>
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	long t,X,Y,x,y,moves,i,k;


	ifstream fin;
	ofstream fout;
	fin.open("cji1.txt");
	fout.open("cjo1.txt");
	double result=0;
	fin>>t;
	for(i=0;i<t;i++)
	{
		moves=1;
		x=0;
		y=0;
		fin>>X>>Y;
		fout<<"Case #"<<i+1<<": ";
		if(X>0)
		{
			for(k=0;k<X;k++)
				fout<<"WE";
		}
		if(X<0)
		{
			for(k=0;k<(abs(X));k++)
				fout<<"EW";
		}
		if(Y>0)
		{
			for(k=0;k<Y;k++)
				fout<<"SN";
		}
		if(Y<0)
		{
			for(k=0;k<(abs(Y));k++)
				fout<<"NS";
		}

		fout<<endl;
	}
	fin.close();
	fout.close();
}
