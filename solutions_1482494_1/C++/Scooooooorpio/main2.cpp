//#include "LongInt.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;
ifstream fin; 
ofstream fout;

//  越界 问题  浮点 除 变 整除，  abs 问题


void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[])
{
	//preWork();
	QCoreApplication a(argc, argv);

	//	char * inputName="A-large.in";
	//	fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO2_input.txt");

	int now =clock();
	sorttime=0;
	fout.open("output.txt");
	int n;
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		work();
		fout<<endl;
	}


	fin.close();

	fout.close();
	int now2= clock();
	
	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	cout<<sorttime<<endl;

	//	return a.exec();
}


void preWork()
{


}
struct PP
{
	int a,b;
	int star;
};
void work()
{
	int n;
	PP  z[ 2000];
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fin>>z[i].a>>z[i].b;
		z[i].star= 0;
	}
	int nowstar=0;
	int step=0;

	while (true)
	{
		if (nowstar == n*2) break;
		bool change = false;
		for (int i=0; i<n; i++)
		{
			if (z[i].star ==2 ) continue;
			if (z[i].b<=nowstar)
			{
				step++;
				nowstar+=2-z[i].star;
				z[i].star =2;
				change = true;
			}
		}
		if (change) continue;
		
		int index= -1;
		int max= -1;
		for (int i=0; i<n; i++)
		{
			if (z[i].star>0) continue;
			if (z[i].a>nowstar) continue;
			if (z[i].b>max) 
			{
				max= z[i].b;
				index= i;
			}
		}
		if (index==-1)
		{
			fout<<"Too Bad";
			return;
		}
		z[index].star =1;
		nowstar++;
		step++;
	}
	fout<<step;
}

