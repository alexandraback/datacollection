/*
 * D.cpp
 *
 *  Created on: 9 Apr 2016
 *      Author: xing
 */

#include <iostream>

//#define DEBUG

using namespace std;


void solve(int index, int K, int C, int S){

	cout<<"Case #"<<index<<":";
	for(int j = 0;j<S;++j){
		cout<<" "<<(j+1);
	}
	cout<<endl;

}

int main(){
	int T,K,C,S;

	cin>>T;

	for(int i = 1;i<=T;++i){
		cin>>K>>C>>S;
		solve(i, K, C, S);
	}

}
