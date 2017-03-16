#include "stdafx.h"

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	int t,n,m,i,j;
	cin>>t;
	int a[6]={1,4,9,121,484};
	int b[1001];
	b[0]=0;
	b[1]=1;
	int c=1;
	for(i=2;i<1001;i++){
		if(i==a[c]){
			b[i]=b[i-1]+1;
			c++;
		}
		else
			b[i]=b[i-1];
	}
	ofstream file;
	file.open("d:\\aa.txt");
	for(int times=1;times<=t;times++)
	{
		cin>>m>>n;
		file<<"Case #"<<times<<": "<<b[n]-b[m-1]<<endl;
	}
	return 0;
}