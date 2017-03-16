// recycle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream> 
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	std::ifstream cin(argv[1]);
	std::ofstream cout(argv[2]);

	 int T;

	cin>>T;

	//cout<<(int)pow((double)2,30);

	//cout<<(int)pow((double)10,2);
	//cout<<(int)log10((double)100);

	for(int i= 0 ; i < T ; i++ ){
		 int A,B;

		cin>>A>>B;
		 int num = 0;

		for(int j = A ; j <= B ; j++){
			
			int wei = (int)(log10((double)j));

			vector<int> exist;

			for(int  k = 0 ; k < wei  ; k++){
				 int bigger = j/ (( int)pow((double)10, k+1))+ (j%((int)pow( (double)10, k+1)) )* (( int)pow((double)10, wei -k)) ; 
				 if(bigger > j && bigger >=A && bigger <= B){
					 int kk = 0;
					 for(kk= 0 ; kk < exist.size() ; kk++){
						if(bigger == exist[kk])
							break;
					 }					
					 if(kk == exist.size()){
						num ++;
						exist.push_back(bigger);
					 }
					
				 }
			}
		}

		cout<<"Case #"<<i+1<<": ";
		cout<<num;
		cout<<endl;
	}

	return 0;
}

