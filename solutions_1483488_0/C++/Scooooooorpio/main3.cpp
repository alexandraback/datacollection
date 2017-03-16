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
#include <QString>
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();
void work1();

//const int MAX = 2000010;
const int MAX = 20010;
int mm[MAX];

int main(int argc, char *argv[])
{
	preWork();
	QCoreApplication a(argc, argv);

	//char * inputName="A-large.in";
	//fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO3_input.txt");

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



	//	return a.exec();
}



void preWork()
{
	QString s;
	for (int i= 1; i<MAX-2; i++)
	{
		s = QString::number(i);

		int min = i;
		for (int j=1; j<s.size(); j++)
		{
			if (s[j]=='0') continue;
			int x =0;
			for (int k=j; k<j+s.size(); k++)
			{
				x= x*10 + (s[ k%s.size()].toAscii() -'0');
			}
			if (x<min) min =x;
		}
		mm[i] = min;
	}

	int z =1;
	z=2;
}

void work()
{
	int a,b;
	fin>>a>>b;
	int count[MAX];
	memset(count,0,sizeof(count));
	for (int i=a; i<=b; i++)
	{
		count[mm[i]] ++;
	}
	__int64 result,x,y;
	result =0;
	for (int i=0; i<MAX; i++)
	{
		if (count[i]<=1) continue;
		x = count[i];
		y= x-1;
		result+= x*y/2;
	}
	fout<<result;
}


