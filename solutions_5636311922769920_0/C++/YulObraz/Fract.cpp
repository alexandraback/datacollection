//============================================================================
// Name        : Fract.cpp
// Author      : Yul Obraz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

long long int calc_point(int* point, int length, int size ){
	long long int result =0l;
	long long int step = 1;
	for(int i=0; i<size; i++){
		result += step * point[i];
		step = step * length;
	}
	return result + 1;
}
void calc(int Klength, int Ctransforms, int Stries){
	vector<int*> points;
	int n=0;
	int checked = 0;
	while(n<Stries && checked <Klength){
		int* point = new int[Ctransforms];
		for(int i=0; i< Ctransforms; i++){
			if(checked>=Klength){
				point[i]=0;
			}else{
				point[i]=checked++;
			}
		}
		points.push_back(point);
		n++;
	}
	if(n==Stries && checked <Klength){
		cout <<		" IMPOSSIBLE";
		return;
	}
	for(int i=0; i< n;i++){
		cout <<" "<< calc_point(points[i], Klength, Ctransforms);
		delete points[i];
	}
}

int main(int argc,char *argv[]) {
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	int tests;
	cin >> tests;
	for(int i=0; i<tests; i++){
		int Klength, Ctransforms, Stries;
		cin>>Klength>> Ctransforms>> Stries;
		cout << "Case #"<< (i+1)<<":";
		calc(Klength, Ctransforms, Stries);//result to cout
		cout << endl;
	}
	return 0;
}
