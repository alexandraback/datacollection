
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std; 




#define MAX_LEN	1024

unsigned long long r=0;
unsigned long long t=0;

unsigned long long transfer(){
	unsigned long long i=0,j=0,k=0;
	int m=0,n=0;

	unsigned long long res=0;
	unsigned long long sum=0;


	double b;
	double bb;
	b=2*r-1;

	bb=b*b;
	bb+=((double)t)*4*2;
	bb=sqrt((double)bb);
	bb-=b;
	bb/=4;
	res=bb;
	



	return res;
}

int main() {
	long i=0,j=0,k=0;
	int T;
	unsigned long long res=0;

	char str[MAX_LEN];
	char *ps;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	fstream fin("A-large.in", ios::in);
	fstream fout("result.txt", ios::out);


	fin >> T;
	fin.getline(str,1024);
	ps=str;

	for (i=0;i<T;i++){

		fin>>r;
		fin>>t;
		fin.getline(str,1024);
		ps=str;

		res=transfer();
//		system("pause\n");

		//double precision
		//fout.setf(ios::fixed);
		//fout.precision(6);

			fout << "Case #" << i+1 << ": " << res << endl;
	}



	return 0;
}
