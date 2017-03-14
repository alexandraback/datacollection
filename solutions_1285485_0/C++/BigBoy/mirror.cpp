// mirror.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream> 
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <deque>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin(argv[1]);
	std::ofstream cout(argv[2]);

	int T;
	cin>>T;

	char grid[50][50];

	for(int i = 0 ; i < T ; i++){
		int H, W;
		double D;
		cin>>H>>W>>D;

		int num = 0;

		double x,y;

		for(int j = 0 ; j< H ; j++){
			for( int k = 0 ; k < W ; k++){
				cin>>grid[j][k];
				if(grid[j][k] == 'X'){
					y = j+0.5;
					x = k+0.5;
				}
			}
		}

		//cout<<x<<" "<<y<<endl;

		double a1 = 1, b1 = 1;
		double a2 = W- 1, b2 = 1;
		double a3 = 1, b3 = H - 1;
		double a4 = W - 1, b4 = H - 1;

		deque<double> xx;
		deque<double> yy;

		vector<double> xxx;
		vector<double> yyy;

		xx.push_back(x);
		yy.push_back(y);


		double tx = xx.front();
			double ty = yy.front();

			xx.pop_front();
			yy.pop_front();

			if(ty > b1){
				double kx = tx;
				double ky = ty - (ty - b1)*2;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D ){
					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}

			if(ty < b3){
				double kx = tx;
				double ky = ty + (b3 - ty)*2;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D  ){

						int mm;
						for(mm = 0 ; mm < xxx.size() ; mm++){
							if(xxx[mm] == kx && yyy[mm] == ky)
								break;
						}
						if(mm == xxx.size()){
							xxx.push_back(kx);
							yyy.push_back(ky);

							xx.push_back(kx);
							yy.push_back(ky);
						}
					
				}
			}

			if(tx > a1){
				double kx = tx - (tx-1)*2;
				double ky = ty ;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D  ){

					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}

			if(tx < a4){
				double kx = tx + (a4-tx)*2;
				double ky = ty ;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D  ){

					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}


		while(xx.size() != 0){
			double tx = xx.front();
			double ty = yy.front();

			xx.pop_front();
			yy.pop_front();

			if(ty > b1){
				double kx = tx;
				double ky = ty - (ty - b1)*2;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D && (ty- y)*(tx - kx) != (ty - ky)*(tx-x) ){
					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}

			if(ty < b3){
				double kx = tx;
				double ky = ty + (b3 - ty)*2;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D  &&(ty- y)*(tx - kx) != (ty - ky)*(tx-x)){



						int mm;
						for(mm = 0 ; mm < xxx.size() ; mm++){
							if(xxx[mm] == kx && yyy[mm] == ky)
								break;
						}
						if(mm == xxx.size()){
							xxx.push_back(kx);
							yyy.push_back(ky);

							xx.push_back(kx);
							yy.push_back(ky);
						}
					
				}
			}

			if(tx > a1){
				double kx = tx - (tx-1)*2;
				double ky = ty ;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D && (ty- y)*(tx - kx) != (ty - ky)*(tx-x) ){

					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}

			if(tx < a4){
				double kx = tx + (a4-tx)*2;
				double ky = ty ;

				if( sqrt((kx-x)*(kx-x) + (ky - y)*(ky-y)) <= D && (ty- y)*(tx - kx) != (ty - ky)*(tx-x) ){

					int mm;
					for(mm = 0 ; mm < xxx.size() ; mm++){
						if(xxx[mm] == kx && yyy[mm] == ky)
							break;
					}
					if(mm == xxx.size()){
						xxx.push_back(kx);
						yyy.push_back(ky);

						xx.push_back(kx);
						yy.push_back(ky);
					}
				}
			}

		}

			for(int j = 0 ; j < xxx.size() - 1 ; j++){
				for(int k = j+1 ; k < xxx.size() ; k++ ){
					if( ( (xxx[j]-xxx[k])*(yyy[j] - y ) == (yyy[j] - yyy[k])*(xxx[j] - x) ) && (( x-xxx[j] )*(x-xxx[k]) > 0)   ){
						if( (xxx[j] - x)*(xxx[j] -x) + (yyy[j] - y)*(yyy[j]-y ) >
							(xxx[k] - x)*(xxx[k] -x) + (yyy[k] - y)*(yyy[k]-y )
							){
								xxx.erase(xxx.begin() + j);
								yyy.erase(yyy.begin() + j);
						}
						else{
								xxx.erase(xxx.begin() + k);
								yyy.erase(yyy.begin() + k);
						}
					}
				}
			}
		

		num = xxx.size();

		cout<<"Case #"<<i+1<<": ";
		cout<<num;
		cout<<endl;
	}

	return 0;
}

