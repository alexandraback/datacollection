#include <cstdio>
#include <cmath>
#include <ciso646>
#include <iostream>
#include <cstdint>

using namespace std;

void findbounds(uint64_t start, uint64_t end, uint64_t& lowerbound, uint64_t& upperbound){
	lowerbound=floor(sqrt(start));
	upperbound=ceil(sqrt(end));
}

int palindrome(uint64_t input){
	int digits[15];
	int i;
	for(i=0; input>0; digits[i]=input%10,input/=10,i++);

	for(int limit=i/2-1,iterator=0; iterator<=limit; iterator++){
		if(digits[i-iterator-1]!=digits[iterator])
			return 0;
	}

	return 1;
}

uint64_t count(uint64_t lowerBound, uint64_t upperBound, uint64_t strictLB, uint64_t strictUB){
	uint64_t count=0;
	for(uint64_t iterator=lowerBound; iterator<=upperBound; iterator++){
		uint64_t square=iterator*iterator;
		if(palindrome(iterator) and palindrome(square)){
			if(square>=strictLB and square<=strictUB)
				count++;
		}
	}
	return count;
}

int main(){
	int numCases;
	cin>>numCases;
	for(int i=0;i<numCases;i++){
		uint64_t start,end;
		cin>>start>>end;

		uint64_t lowerbound,upperbound;
		findbounds(start,end,lowerbound,upperbound);

		//lowerbound and upperbound are the ranges we search between
		printf("Case #%d: %d\n",i+1,count(lowerbound,upperbound,start,end));
	}
	return 0;
}