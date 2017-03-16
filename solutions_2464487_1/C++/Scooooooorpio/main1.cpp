#include "LongInt.h"
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

void work()
{
	long long int r,t;
	fin>>r>>t;
	long long int x0,x1;
	x0 = 1;
	x1 =1000000000;
	while (x0+1<x1) {
		long long int m = (x0+x1) /2;
		long long int z;
		double f;
		f= 2*double(r)*m + 2*double(m)*m-m;
		if (f>t+10000) {
			x1 = m;
		}
		else {
			z= 2*r*m+ 2*m*m - m;
			if (z>t) {
				x1 = m;
			}
			else {
				x0 = m;
			}
		}
	}
	fout<<x0;
}