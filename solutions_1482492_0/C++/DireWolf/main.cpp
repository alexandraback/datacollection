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

ifstream myin("B-small-attempt0 (2).in");
ofstream myout("B-small-attempt0 (2).out");

double max(double a,double b){
	if(a>b) return a;
	return b;
}

typedef struct pos{
	double time;
	double distance;
}Position;

void main2(){
	double d;
	int n,a;
	Position pozicije[3];
	double acc[15];
	myin >> d;
	myin >> n >> a;
	for(int i=0 ; i<n ; i++){
		myin >> pozicije[i].time >> pozicije[i].distance;
	}
	for(int i=0 ; i<a ; i++){
		myin >> acc[i];
	}
	myout << endl;
	if(n==1){
		for(int i=0 ; i<a ; i++){
			myout << sqrt(2*d/acc[i]);
			if(i!=a-1) myout << endl;
		}
	}
	else{
		for(int i=0 ; i<a ; i++){
			myout << max(sqrt(2*d/acc[i]),(d-pozicije[0].distance)/(pozicije[1].distance - pozicije[0].distance)*pozicije[1].time);
			if(i!=a-1) myout << endl;
		}
	}
}

//Multiple test cases
int main(){
	int t;
	myin >> t;
	myout.precision(8);
	myout.setf(ios::fixed,ios::floatfield);
	for(int i=1 ; i<=t ; i++){
		myout << "Case #" << i << ": ";
		main2();
		myout << endl;
	}
}