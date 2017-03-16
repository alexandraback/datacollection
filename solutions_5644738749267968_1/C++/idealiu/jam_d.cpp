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
#include <algorithm>    // std::sort

using namespace std;

int main(int argc,char*argv[]) {
	cout<<"Start"<<endl;
	ifstream input("D-large.in");
	if(!input.is_open()) cout<< "problem"<<endl;
	
	int number;
	input>>number;
	
	vector<size_t> result_DW(number+1,0),result_W(number+1,0);

	for(int i=1;i<= number; i++){
		//loading
		size_t round;
		input>>round;
		
		vector<float> Nao(round), Ken(round);
		for(int id =0; id < round ; id++)
			input>> Nao[id];

		for(int id =0; id < round ; id++)
			input>> Ken[id];


		std::sort(Nao.begin(),Nao.end());
		std::sort(Ken.begin(),Ken.end());
		// D_ war
		size_t N_win=0;
		size_t K_los=0;
		while (N_win<round && K_los<round){
			while(Nao[N_win]<Ken[K_los] && N_win<round){
				N_win++;
			}
			if (N_win < round){
				result_DW[i]++;
				N_win++;
				K_los++;
			}
		}
		// war
		size_t K_id=round-1;
		for (int N_id= round-1; N_id >= 0; N_id --){
			if(Nao[N_id]>Ken[K_id]){
				result_W[i]++;
			}else{
				K_id--;
			}
		}

		
	}

	//===writing
	ofstream output("answer.txt");
	for(int i=1;i<= number; i++){
		output<<"Case #"<<i<<": ";
		output<<result_DW[i]<<" "<< result_W[i]<<endl;
	}
	output.close();


	return 0;
}

