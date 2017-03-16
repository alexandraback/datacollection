//============================================================================
// Name        : problemC.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#define rep(i,n) for(int i = 0;i<n;i++)
#define repit(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef unsigned long long ull;
using namespace std;
int T=1,R=100,N=3,M=5,K=7;

int main() {
	cin >> T >> R >> N >> M >> K;
	cout << "Case #1:"<<endl;
	rep(r,R){
		bool n_2 = false;
		bool n_5 = false;
		bool n_3 = false;
		bool n_64 = false;
		bool n_9 = false;
		bool n_25 = false;
		bool n_27 = false;
		bool n_125=false;
		bool n_8 = false;
		rep(k,K){
			int a;
			cin >> a;
				if(a % 5 == 0) n_5 = true;
				if(a % 3 == 0) n_3 = true;
				if(a % 64 == 0) n_64 = true;
				if(a % 9 == 0) n_9 = true;
				if(a % 27 == 0) n_27 = true;
				if(a % 25 == 0) n_25 = true;
				if(a % 125 == 0) n_125 = true;
				if(a % 8 == 0) n_8 = true;
		}
		if(n_125){
			cout << "555" << endl;
			continue;
		}
		if(n_27){
			cout << "333" << endl;
			continue;
		}
		if(n_64){
			cout << "444" << endl;
			continue;
		}
		if(n_3 && n_5){
			cout << "35";
		}else if(n_25){
			cout << "55";
		}
		else if(n_9){
			cout << "33";
		}else if(n_8){
			if(rand()%2){
				cout << "222" << endl;
				continue;
			}else{
				cout << "24";
			}
		}else{
			if(!n_3){
				int nums[] = {2,4,5};
				cout << nums[rand()%3];
				cout << nums[rand()%3];
			}else
				if(!n_5){
					int nums[] = {2,4,3};
					cout << nums[rand()%3];
					cout << nums[rand()%3];
				}else{
					int nums[] = {2,5,3};
					cout << nums[rand()%3];
					cout << nums[rand()%3];
				}
		}

		if(!n_2 && !n_3){
			cout << "5" << endl;
		}
		else if(!n_5 && !n_3){
			if(rand()%2){
				cout << 2;
			}else{
				cout <<4;
			}
			cout << endl;
		}else if(!n_2 && !n_5){
			cout << 3 << endl;
		}else if(!n_2){
			if(rand()%2){
				cout << 3;
			}else{
				cout <<5;
			}
			cout << endl;
		}
		else if(!n_3){
			if(rand()%2){
				cout << 2;
			}else{
				cout <<5;
			}
			cout << endl;
		}else if(!n_5){
			if(rand()%2){
				cout << 2;
			}else{
				cout <<3;
			}
			cout << endl;
		}
		else{
			int nums[] = {2,4,3,5};
			cout << nums[rand()%4] << endl;
		}
	}
	return 0;
}
