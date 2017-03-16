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
int maxrr(long long *arr,int size)
{
	int max =0;
	int num=0;
	For(i,0,size)
	{
		if(arr[i]>max){
			max=arr[i];
			num=i;
		}
			
	}
	return num;
}
int main() {
	ifstream myfile;
	myfile.open("input.txt");
	ofstream myfile2;
	myfile2.open("output.txt");
	
	myfile >> N;
	
	for (long long u = 0; u < N; u++) {

		myfile >> a>>b>>c;
		long long *arr =new long long[c];
		For(i,0,c)
			myfile>>arr[i];
		long long tot=0;
		int ct=maxrr(arr,c);
		int am=0;
		d=a;
		int size=c;
		long long *arr2;
		while(c!=am)
		{
			
			For(i,0,ct)
			{
				
				n=min(a-d,b);
				tot+=arr[i]*(b-n);
				d+=n;
			}
			tot+=arr[ct]*d;
			d=b;
			am+=ct+1;
			
			long long *arr2 = new long long[size-am];
			For(i,0,c-am)
				arr[i]=arr[i+ct+1];
		//	*arr=*arr2;
			
				ct=maxrr(arr,c-am);
			
			//arr + ((sizeof(long long)/sizeof(int))*(ct+1));
			
			
		}
		
		myfile2<<"Case #"<<u+1<<": "<<tot<<endl;
		//cout<<"Case #"<<u+1<<": "<<tot<<endl;
		
	}
	system("pause");
}