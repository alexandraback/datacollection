// Password.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream> 
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream cin(argv[1]);
	std::ofstream cout(argv[2]);

	int T,A,B;

	double r[100008];

	cin>>T;

	for(int i = 0 ; i < T ; i++){
		double num, num2;

		cin>>A>>B;

		for(int j = 0 ; j < A ; j++){
			cin>>r[j];
		}



		double ratio = 1;
		for(int j = 0 ; j < A ; j++){
			ratio *= r[j];
		}

		num = (B-A + 1)*ratio + (B-A + 1 + B + 1)*(1- ratio);


		for(int k = 1 ; k <= A ; k++){
		
			ratio = 1;
			for(int j = 0 ; j < A-k ; j++){
				ratio *= r[j];
			}

			num2 = (B-A + 1 + k*2)*ratio + ( B-A + 1 + k*2 + B + 1)*(1- ratio);

			if (num2 < num){
				num = num2;
			}
		}

		if(num > (double)(1+B+1)){
			num = (double)(1+B+1);
		}



		
		cout<<"Case #"<<i+1<<": ";
		cout<<fixed<<setprecision(6)<<num;  
		//printf("%.6f",num);
		cout<<endl;
	}

	return 0;
}

