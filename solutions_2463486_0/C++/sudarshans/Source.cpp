#include <cstdio>
#include <cmath>
#include <ciso646>
#include <iostream>

using namespace std;

void findbounds(int start, int end, int& lowerbound, int& upperbound){
	lowerbound=floor(sqrt(start));
	upperbound=ceil(sqrt(end));
}

int palindrome(int input){
	int digits[15];
	int i;
	for(i=0; input>0; digits[i]=input%10,input/=10,i++);

	for(int limit=i/2-1,iterator=0; iterator<=limit; iterator++){
		if(digits[i-iterator-1]!=digits[iterator])
			return 0;
	}

	return 1;
}

int count(int lowerBound, int upperBound, int strictLB, int strictUB){
	int count=0;
	for(int iterator=lowerBound; iterator<=upperBound; iterator++){
		int square=iterator*iterator;
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
		int start,end;
		cin>>start>>end;

		int lowerbound,upperbound;
		findbounds(start,end,lowerbound,upperbound);

		//lowerbound and upperbound are the ranges we search between
		printf("Case #%d: %d\n",i+1,count(lowerbound,upperbound,start,end));
	}
	return 0;
}