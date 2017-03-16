/*
 * C.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: xing
 */



#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//#define DEBUG

long isPrime(long num){
	for(long i = 2;i*i<=num;++i){
		if(num%i == 0)
			return i;
	}
	return -1;
}

long translateNum(long num, int base){
	long rv = 0, tmpNum = num, weight = 1;
	int m;
	do{
		m = tmpNum%2;
		rv += m*weight;
		tmpNum /= 2;
		weight *= base;

	}while(tmpNum);

	return rv;

}


void printBinaryNum(long num, int len){
	long rv = 0, tmpNum = num, weight = 1;
	int *digits = new int[len], count=0;

	do{
		digits[len - count - 1] = tmpNum%2;
		tmpNum /= 2;
		count++;

#ifdef DEBUG
		//cout<<"offset digits[offset] "<<i<<" "<<N<<endl;
#endif

	}while(tmpNum);

	for(int i = 0;i<len;i++){
		cout<<digits[i];
	}

	delete[] digits;
	return;

}
void solve(int N, int J){
	long startNum = 1<<(N-1), tranNum;
	int base, count = 0;
	long prime[11];


	for(long i = startNum; ;i++){
#ifdef DEBUG
		cout<<"begin of iteration i  "<<i<<endl;
#endif


		if(i%2==0)
			continue;
		base = 2;
		tranNum = i;
		prime[base] = isPrime(tranNum);

#ifdef DEBUG
		cout<<"tranNum base isPrime(tranNum)  "<<tranNum<<" "<<base<<" "<<prime[base]<<endl;
#endif

		if(prime[base] == -1)
			continue;


		for(base=3;base<11;base++){
			tranNum = translateNum(i, base);
			prime[base] = isPrime(tranNum);

#ifdef DEBUG
		cout<<"tranNum base isPrime(tranNum)  "<<tranNum<<" "<<base<<" "<<prime[base]<<endl;
#endif

			if(prime[base] == -1)
				goto ENDOFSOLVE;

		}


#ifdef DEBUG
		cout<<"i N "<<i<<" "<<N<<endl;
#endif

		printBinaryNum(i, N);
		for(base = 2;base<11;base++){
			cout<<" "<<prime[base];
		}
		cout<<endl;

		count++;
		if(count == J)
			break;

		ENDOFSOLVE:
			;
	}

}

int main(){
	int T, N, J;
	cin>>T;

	for(int i = 0;i<T;i++){
		cin>>N>>J;
		cout<<"Case #"<<(i+1)<<":"<<endl;

		solve(N, J);
	}

}
