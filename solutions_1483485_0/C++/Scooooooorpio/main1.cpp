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
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();
vector<char> dic;
int main(int argc, char *argv[])
{
	preWork();
	QCoreApplication a(argc, argv);

//	char * inputName="A-large.in";
//	fin.open(inputName);
//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO1_input.txt");

	fout.open("output.txt");
	int n;
	fin >>n;
	char zzzz[100];
	fin.getline(zzzz,100);
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
	dic.resize(500);
	char a[300] = "y qeeejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char b[300] = "a zooour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	int size = strlen(a);
	bool x[300];
	for (int i=0; i<300;i++)
	{
		x[i] = false;
	}
	for (int i=0; i<size; i++)
	{
		dic[ a[i] ] = b[i];
		x[b[i]] = true;
	}
	for (int i='a'; i<'z'; i++)
	{
		if (x[i]!=true)
		{
			dic['z'] = char(i);
			assert(i==113);
			break;
		}
	}
	//dic['z'] = char(113);
	int z;
	z=1;
}

void work()
{
	char z[300];
	fin.getline(z,200);
	for (int i=0; i<strlen(z); i++)
	{
		fout<<dic[z[i]];
	}
}