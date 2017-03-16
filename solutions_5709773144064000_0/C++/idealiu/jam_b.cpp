/** @Image calibration application
 ** @Estimate fundamental or homography matrix
 ** @author Zhe Liu
 **/
/*
Copyright (C) 2011-2013 Zhe Liu.
All rights reserved.

This file is part of the KVLD library and is made available under
the terms of the BSD license (see the COPYING file).
*/
#include<iostream>
#include<vector>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc,char*argv[]) {
	cout<<"Hello world"<<endl;
	ifstream input("B-small-attempt0.in");
	if(!input.is_open()) cout<< "problem1"<<endl;
	
	int number;
	input>>number;

	vector<double> result(number+1,0); 


	for(int i=1;i<= number; i++){
		//loading
		double c, f, x;
		input>>c>>f>>x;
		//solving 
		if (x==0) result[i]=0;

		double t=0;
		double speed=2;
		double up= c/f*(speed+f);
		while(up<x){
			t+=c/speed;
			speed+=f;
			up = c/f*(speed+f);
		}

		t+=x/speed;
		result[i]=t;
		cout<<c<<" "<<f<<" "<<x<<" "<<t<<endl;
	}

	ofstream output("answer.txt");

	for(int i=1;i<=number;i++){
		output<<"Case #"<<i<<": ";
		output<<std::setprecision(7)<< fixed  << showpoint<<result[i]<<endl;
	}
	output.close();

	return 0;
}

