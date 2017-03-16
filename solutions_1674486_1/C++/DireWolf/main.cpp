//File: main.cpp
//Autor: Vukasin Rankovic
#pragma comment(linker, "/STACK:268435456")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stack>

using namespace std;

ifstream myin("A-large (1).in");
ofstream myout("A-large (1).out");

int min(int a,int b){
	return a<b?a:b;
}

void main2(){
	int veza[1000][1000];
	bool found = false;
	int lenght = 1,n,temp,temp1;
	myin >> n;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n; j++){
			veza[i][j]=0;
		}
	}
	for(int i=0 ; i<n ; i++){
		myin >> temp;
		for(int j=0; j<temp; j++){
			myin >> temp1;
			veza[i][temp1-1]=lenght;
		}
	}
	for(int k=0; k<n ; k++){
		for(int i=0 ; i<n; i++){
			if(veza[i][k]>0){
				for(int j=0 ; j<n ; j++){
					if(veza[k][j] > 0){
						if((veza[i][j]>0 && j!=k)){
							found = true;
						}
							veza[i][j]=veza[i][k]+veza[k][j];
					}
				}
			}
		}
	}
	if(found){
		myout << "Yes";
	}
	else{
		myout << "No";
	}
}

//Multiple test cases
int main(){
	int t;
	myin >> t;
	for(int i=1 ; i<=t ; i++){
		myout << "Case #" << i << ": ";
		main2();
		myout << endl;
	}
}