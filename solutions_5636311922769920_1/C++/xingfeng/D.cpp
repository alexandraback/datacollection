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
	int required;

	if(C > K)
		C = K;

	required = K/C;
	if(K%C != 0)
		++required;

#ifdef DEBUG
	cout<<"required S "<<required<<" "<<S<<endl;
#endif

	if(required > S){
		cout<<"Case #"<<index<<": IMPOSSIBLE"<<endl;
		return;
	}


	long * pos = new long[required];
	for(int j = 0;j<required;++j){
		pos[j] = 1+j*C;
	}

	required = K/C;

	for(int i = 1;i<C;++i){
		for(int j = 0;j<required;++j){
			pos[j] = (pos[j] - 1)*K+ j*C + i + 1;
		}

#ifdef DEBUG
		cout<<"i "<<i<<endl;
		for(int j = 0;j<required;++j){
			cout<<" "<<pos[j];
		}
		cout<<endl;
#endif
	}

	cout<<"Case #"<<index<<":";
	for(int j = 0;j<required;++j){
		cout<<" "<<pos[j];
	}

	if(K%C != 0){
		//not complete one
		int jOffset = K/C, reminder = K%C;
		for(int i = 1;i<reminder;++i){
			pos[required] = (pos[required] - 1)*K+ jOffset*C + i + 1;
	#ifdef DEBUG
			cout<<"i "<<i<<endl;
			for(int j = 0;j<required;++j){
				cout<<" "<<pos[j];
			}
			cout<<endl;
	#endif
		}

		for(int i = reminder;i<C;++i){
			pos[required] = (pos[required] - 1)*K + reminder;
		}

		cout<<" "<<pos[required];
	}
	cout<<endl;

	delete[] pos;
}

int main(){
	int T,K,C,S;

	cin>>T;

	for(int i = 1;i<=T;++i){
		cin>>K>>C>>S;
		solve(i, K, C, S);
	}

}
