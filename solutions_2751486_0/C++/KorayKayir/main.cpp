#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <string>

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
bool iss(char a)
{
	if(a=='a' || a=='i' || a=='o' || a=='u' || a=='e')
	{
		return true;
	}
	return false;
}
int main() {
	ifstream myfile;
	myfile.open("input.txt");
	ofstream myfile2;
	myfile2.open("output.txt");
	long long count=0;
	int size;
	myfile >> N;
	
	for (long long u = 0; u < N; u++) {
		if(u==8)
		{
			cout<< u;
		}
		count = 0;
		string s;
		myfile >> s >> size;
		int num1=0,num2=0;
		int tr=0;
		//straight
	    int k= s.size();
		//int *arr;
		vector<int> arr;
		int prev=-1;
		For(i,0,k-size+1){
			
			
				num2=0;
				For(j,0,size)
				{
					if(!iss(s[i+j]))
						num2++;
					else break;
				}
				if(num2==size){
					count += (i-prev)*(k-i-size+1);
					arr.push_back(i);
					prev=i;
					tr++;
				}
		}
	/*	For(i,0,arr.size()){
			For(j,i+1,arr.size()){
				count -=(arr[i]+1)*(k-arr[j]-size+1);
			}
		}*/
		//straight
		//0 5 3
		myfile2<<"Case #"<<u+1<<": "<<count<<endl;
		//cout<<"Case #"<<u+1<<": "<<count<<endl;
		
	}
	system("pause");
}