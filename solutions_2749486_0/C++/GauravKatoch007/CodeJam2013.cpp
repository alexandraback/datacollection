//============================================================================
// Name        : CodeJam2013.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<stack>
#include<math.h>
#include<fstream>
#include<string.h>
using namespace std;

int limit=500;
vector<char> v;
bool found;


void eval(char X,int Y){
	int step=1;
	if(X>0)while(X!=0){
		v.push_back('W');
		X+=step;
		step++;

		v.push_back('E');
		X-=step;
		step++;
	}
	else
		while(X!=0){


				v.push_back('E');
				X-=step;
				step++;
				v.push_back('W');
								X+=step;
								step++;
			}
	if(Y>0)while(Y!=0){

		v.push_back('S');
		Y+=step;
		step++;

		v.push_back('N');
		Y-=step;
		step++;

	}
	else
		while(Y!=0){

			v.push_back('N');
							Y-=step;
							step++;
			v.push_back('S');
				Y+=step;
				step++;



			}

	int i;
	for(i=0;i<v.size();i++)
		printf("%c",v[i]);
}

int main() {

	ofstream file;
	file.open("out.txt");
	int i,j,k,T,X,Y;



	scanf("%d",&T);

	for(i=0;i<T;i++){

		scanf("%d %d",&X,&Y);

		v.clear();
		found=false;
		printf("\nCase #%d: ",i+1);
		eval(X,Y);
	}

	//file<<"Case #"<<i+1<<": "<<eval(str,N)<<"\n";

}

