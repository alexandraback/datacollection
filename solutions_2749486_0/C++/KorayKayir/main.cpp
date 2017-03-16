#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

int n,c ,d,x,y,M;
double a,b;
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
int comb(int a, int b)
{
	int k=1;
	For(i,0,b)
		k*=b-i;
	For(i,0,b)
		k/=i+1;
	return k;
}
int main() {
	ifstream myfile;
	myfile.open("input.txt");
	ofstream myfile2;
	myfile2.open("output.txt");
	
	myfile >> N;
	
	for (long long u = 0; u < N; u++) {
		bool ns= false, ew= false;
		myfile >> a >> b;
		if(a<0){
			a=-a;
			ew= true;
		}
		if(b<0){
			b=-b;
			ns=true;
		}
		int count=1;
		bool m1=false,m2=false;
		myfile2<<"Case #"<<u+1<<": ";
		while(!(m1 && m2)){
			
			if(a<0){
				a=-a;
				ew= !ew;
			}
			if(b<0){
				b=-b;
				ns= !ns;
			}

			if((a<=b && !m1)|| m2){
				while(a>0){
				if(a<count){
				a+=count;
				count++;
				if(!ew)
					myfile2<<"W";
				else
					myfile2<<"E";
				}
				else{
				a-=count;
				count++;
				if(ew)
					myfile2<<"W";
				else
					myfile2<<"E";
				}
				}
			}
			if((b<a && !m2) || m1)
			{
				while(b>0){
					if(b<count){
					b+=count;
					count++;
					if(!ns)
					myfile2<<"S";
					else
					myfile2<<"N";
					}
				else{
				b-=count;
				count++;
				if(ns)
					myfile2<<"S";
				else
					myfile2<<"N";
				}
				}
			}
			if(a==0)
				m1=true;
			if(b==0)
				m2=true;
		}
		//myfile2<<"Case #"<<u+1<<": "<<result<<endl;
		myfile2<<endl;
		
	}
	system("pause");
}