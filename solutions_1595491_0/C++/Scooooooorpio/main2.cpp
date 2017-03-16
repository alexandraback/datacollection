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

void work()
{
	int n,s,p;
	fin>>n>>s>>p;
	int z[400];
	int result = 0;
	for (int i=0; i<n; i++)
	{
		int t;
		fin>>t;
		if (t>= p*3-2) 
		{
			result ++;
			continue;
		}
		if (t<2) continue;
		if (t>= p*3-4)
		{
			result ++;
			s--;
		}
	}
	if (s<0)
	{
		result +=s;
	}
	fout<<result;
}

