// code jam 3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
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
	int count;
	int maxlen;
	long long a,b;
	long long start, end, testnumber,temp,checknumber,temp_checknumber;

	op = fopen("input.txt","r");
	fout.open("output.txt");

	fscanf(op,"%d",&t);

    for(int i=0;i<t;i++) {
		count = 0;
		fscanf(op,"%llu %llu",&a,&b);

		for(int j=1;j<=7;j++) {
			if((j%2)==1) maxlen = (j/2)+1;
			else maxlen = (j/2);
			
			start = 0;
			end = 1;

			for(int k=1;k<=maxlen;k++) {
				start *=10;
				end *=10;
				if(k==1) start +=1;
			}

			while(start < end) {
				testnumber = start;

				if(j>=2) {
					temp = start;

					if(j%2==0) {
						while(temp>=1){
							int digit = temp % 10;
							testnumber *= 10;
							testnumber += digit;
							temp/=10;
						}
					}

					if(j%2==1) {
						temp/=10;

						while(temp>=1) {
							int digit = temp % 10;
							testnumber *= 10;
							testnumber += digit;
							temp/=10;
						}
					}
				}

				start +=1;

				checknumber = (testnumber*testnumber);

				if(checknumber>b) break;

				else if(checknumber>=a && checknumber <=b) {
					int checkarray[40];
					int checkcnt = 0;

					temp_checknumber = checknumber;

					while(checknumber>0) {
						checkarray[checkcnt++] = checknumber%10;
						checknumber/=10;
					}

					if(checkcnt == 1) { 
						count +=1;
						//cout<< temp_checknumber << endl;
					}

					else {
						int ok = 0;
						for(int x=0;x<checkcnt/2;x++) {
							if(checkarray[x] !=checkarray[checkcnt-1-x]) ok =1;
						}
						if(ok==0) {
							count+=1;
							//cout<< temp_checknumber << endl;
						}
					}
				}
			}

		}
		fout << "Case #" <<i+1<<": " << count <<endl;
	}



	return 0;
}

/*
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

*/