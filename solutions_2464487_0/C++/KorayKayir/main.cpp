#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

long long n, a, b,c ,d,x,y,M;
long long N,k,l;
#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i < _b; ++i)

/*
int** ary = new int*[sizeX];
for(int i = 0; i < sizeX; ++i)
    ary[i] = new int[sizeY];
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}*/

//qsort (arr, c, sizeof(int), compare);
int main() {
	ifstream myfile;
	myfile.open("input.txt");
	ofstream myfile2;
	myfile2.open("output.txt");
	
	myfile >> N;
	
	for (long long u = 0; u < N; u++) {

		myfile >> a>>b;
		c=0;
		while(b>=0)
		{
			c++;
			b -= (2*a+1);
			a+=2;
		}
		
		myfile2<<"Case #"<<u+1<<": "<<(c-1)<<endl;
	//	cout<<"Case #"<<u+1<<": "<<(c-1)<<endl;
		
	}
	system("pause");
}