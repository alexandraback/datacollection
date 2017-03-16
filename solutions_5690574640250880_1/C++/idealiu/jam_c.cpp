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
	cout<<"Start"<<endl;
	ifstream input("C-large.in");
	if(!input.is_open()) cout<< "problem"<<endl;
	
	int number;
	input>>number;
	vector<size_t> R(number+1),C(number+1), M(number+1);
	vector<vector<char>> result(number+1,0);

	for(int i=1;i<= number; i++){
		//loading
		
		input>>R[i]>>C[i]>>M[i];
		size_t r=R[i],c=C[i],m=M[i];


		//solving 
		size_t l_min= min(r,c);
		size_t l_max= max(r,c);
		size_t white=r*c-m;
		
		//easy case
		if(l_min==1)
		{	
			result[i].resize(r*c,'*');
			result[i][0]='c';
			size_t next=1;
			while(next<white){
				result[i][next]='.';
				next++;
			}
			continue;
		}
		if(white==1){
			result[i].resize(r*c,'*');
			result[i][0]='c';
			continue;
		}
		
		if(l_min==2)
		{	
			if( white%2==0 && white>=4){
				result[i].resize(r*c,'*');
				result[i][0]='c';
				size_t next=1;
				while(next<white){
					result[i][next]='.';
					next++;
				}
			}
			continue;
		}

		//general case
		if ( white>=l_min*2+2){
			result[i].resize(r*c,'*');
			result[i][0]='c';
			size_t next=1;
			while(next<white){
				result[i][next]='.';
				next++;
			}
			if (white%l_min==1){
				size_t row=white/l_min;
				result[i][row*l_min-1]='*';
				result[i][next]='.';
			}
			continue;
		}
		//difficult case
		if(white%2==0){
			if(white>=4){
				result[i].resize(r*c,'*');
				for (int j=0; j < white/2;j++){
					result[i][j*l_min  ]='.';
					result[i][j*l_min+1]='.';
				}
				result[i][0]='c';
			}
			continue;
		}

		if( white%2==1 ){
			if(white>=9){
				result[i].resize(r*c,'*');
				for (int j=0; j < (white-3)/2;j++){
					result[i][j*l_min  ]='.';
					result[i][j*l_min+1]='.';
				}
				result[i][0*l_min+2]='.';
				result[i][1*l_min+2]='.';
				result[i][2*l_min+2]='.';
				result[i][0]='c';
			}
			continue;
		}
	}

	//===writing
	ofstream output("answer_large.txt");
	for(int i=1;i<= number; i++){
		size_t r=R[i],c=C[i],m=M[i];
		//cout<< r<<" "<<c<<" "<<m<<endl;
		output<<"Case #"<<i<<":"<<endl;
		
		if (result[i].size()==0){
			output<<"Impossible"<<endl;
			//cout<<"impo"<<endl;
			continue;
		}

		for (size_t x=0; x<r; x++){
			for (size_t y=0; y<c; y++){
				if (r<=c){
					output<<result[i][y*r+x];
					//cout<<result[i][y*r+x];
				}else{
					output<<result[i][x*c+y];
					//cout<<result[i][x*c+y];
				}
			}
			output<<endl;
			//cout<<endl;
		}
	}
	output.close();


	return 0;
}

