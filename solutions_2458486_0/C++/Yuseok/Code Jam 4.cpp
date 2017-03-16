// Code Jam 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
using namespace std;
FILE *op;
ofstream fout;

int keys[300];
int accesskeys[300];
int roomkeys[300][300];
int roomkeys_count[300];
int recure_check[300];
int promise_key[300];
int root[300];
int ok = 0;
int t,k,n;




void recur(int index) {
	int i,j;
	int totalcount[300];

	if(ok==1) return;

	if(index == n) {
		ok = 1;

		for(i=0;i<n;i++) {
			fout << root[i];
			if(i!=n-1) fout <<" ";
		}
		fout << endl;
		return;
	}

	else {

		int stops = 0;

		for(i=0;i<n;i++) {
			if(recure_check[i] == 0  &&  keys[accesskeys[i]]>=1) {
				
				promise_key[accesskeys[i]] -=1;

				for(j=0;j<300;j++) {
					totalcount[j] = 0;
				}

				for(j=0;j<n;j++) {
					if(recure_check[j] == 0 && i!=j) {
						totalcount[accesskeys[j]]+=1;
					}					
				}

				stops = 0;

				for(j=0;j<300;j++) {
					if(totalcount[j]>=1 &&  promise_key[j] < totalcount[j]) {
						stops = 1;
						break;
					}
				}

				if(stops==1) { promise_key[accesskeys[i]] +=1; continue; }


				recure_check[i] = 1;
				root[index] = (i+1);

				keys[accesskeys[i]] -=1;

				for(j=0;j<roomkeys_count[i];j++) {
					keys[roomkeys[i][j]] +=1;
				}
			
				recur(index+1);

				promise_key[accesskeys[i]] +=1;
				keys[accesskeys[i]] +=1;

				for(j=0;j<roomkeys_count[i];j++) {
					keys[roomkeys[i][j]] -=1;
				}

				recure_check[i] = 0;

				if(roomkeys_count[i]==0) {
					break;
				}
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	int i,j,key,room_key;
	
	op = fopen("input.txt","r");
    fout.open("output.txt");

	fscanf(op,"%d",&t);

	for(i=0;i<t;i++) {
		fout << "Case #"<<i+1<<": ";
		fscanf(op,"%d %d",&k, &n);

		for(j=0;j<300;j++) { keys[j] = 0; promise_key[j] = 0;}

		for(j=0;j<k;j++) {
			fscanf(op,"%d", &key);
			keys[key] +=1;
			promise_key[key] +=1;
		}
		
		for(j=0;j<n;j++) {
			fscanf(op,"%d",&accesskeys[j]);
			fscanf(op,"%d",&roomkeys_count[j]);
			for(int x=0;x<roomkeys_count[j];x++) {
				fscanf(op,"%d",&roomkeys[j][x]);
				promise_key[roomkeys[j][x]] +=1;
			}
		}
		ok = 0;
		recur(0);
		if(ok ==0) fout << "IMPOSSIBLE" <<endl;
		else cout <<endl;
	}

	return 0;
}

