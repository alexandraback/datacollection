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
	//char zzzz[100];
	//fin.getline(zzzz,100);
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
	
}
double prob[ 200000];

void work()
{
	int A,B;
	fin>>A>>B;
	for (int i=0;i<A; i++)
	{
		fin>>prob[i];
	}
	prob[A]=0;
	long double result;
	result = B+2;
	long double p =1;
	for (int i=0; i<=A; i++)
	{
		long double r;
		r=   ( (A-i)*2 + B -A +1 ) + (1-p) * (B+1);
		if (r<result) result =r;
		p = p*prob[i];
	}
	fout<<setprecision(15)<<result;
}