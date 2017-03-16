// code jam 1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
FILE *op;
ofstream fout;

int _tmain(int argc, _TCHAR* argv[])
{
	int t,n,m;
	int data[110][110],check[110][110];
	int height[110],width[110];
	int hmax, wmax;
	int result;

	op = fopen("input.txt","r");
	fout.open("output.txt");

	fscanf(op,"%d",&t);

	    for(int i=0 ;i<t;i++) {
	    	fscanf(op,"%d %d",&n, &m);

	    	for(int j=0;j<n;j++) {

			    for(int k=0;k<m;k++) {
			    	fscanf(op,"%d",&data[j][k]);
			    	check[j][k] = 0;
					if(j==0) height[k] = 0;
			    }
				width[j] = 0;
	    	}

    		for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					if(width[j] < data[j][k]) width[j] = data[j][k];
					if(height[k] < data[j][k]) height[k] = data[j][k];
				}
			}

		   for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					if((width[j] == data[j][k]) || (height[k] == data[j][k])) check[j][k] = 1;
				}
			}	

		    result = 1;
		   	for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {

					if(check[j][k] == 0) result = 0;

				}
			}	

			fout << "Case #" <<i+1<<": ";
			if(result == 1) fout << "YES" <<endl;
			else fout <<"NO"<<endl;

	}

	return 0;
}

