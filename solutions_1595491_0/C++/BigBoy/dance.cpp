// dance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

	int t[200];

	for(int i = 0 ; i < T ; i++){
		int N,S,p;
		cin>>N;
		cin>>S;
		cin>>p;
		for(int j = 0 ; j < N ; j++){
			cin>>t[j];
		}

		int num = 0;
		for(int j = 0 ; j < N ; j++){
			if(t[j] % 3 == 0 ){
				if(t[j]/3 >= p){
					num ++;
				} else if(t[j]/3+1 >= p && t[j]/3 >1 && S >0){
					num ++;
					S -- ;
				}
			} else if ( t[j] % 3 == 1 ){
				if(t[j]/3 + 1 >= p){
					num ++;
				} 
			} else {
				if( t[j]/3 + 1 >= p) {
					num ++;
				} else if ( t[j]/3 + 2 >= p && S > 0 ){
					num ++;
					S --;
				}
			}
		}

		cout<<"Case #"<<i+1<<": ";
		cout<<num;
		cout<<endl;
	}

	return 0;
}

