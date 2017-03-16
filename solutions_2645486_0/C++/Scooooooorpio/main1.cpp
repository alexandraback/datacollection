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
struct Node{
	int a,index;
	bool operator <(const Node & b) const {
		if (a>b.a) return true;
		return false;
	}
};
void work()
{
	long long int E,R,N;
	fin>>E>>R>>N;
	Node z[20000];
	int e_left[20000];
	for (int i=0; i<N; i++) {
		fin >> z[i].a;
		z[i].index = i;
		e_left[i] = -1;
	}
	
	e_left[0]= E;
	e_left[N]= R;
	sort(z,z+N);
	long long int result = 0;
	for (int i=0; i<N; i++) {
		int x = z[i].index;
		int y = x+1;
		while (e_left[y]<0) y++;
		long long int left2 = e_left[y] - R* (y-x);
		if (left2<0) left2 = 0;
		y = x;
		while(e_left[y]<0) y--;
		long long int left1 = e_left[y] + R* (x-y);
		if (left1>E) left1 = E;

		e_left[x+1] = left2 +R;
		e_left[x] = left1;
		if (e_left[x+1] >E) e_left[x+1] = E;
		result += (left1- left2) * z[i].a;
	}	
	fout<< result;
}