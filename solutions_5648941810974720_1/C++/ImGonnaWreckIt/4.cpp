#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int getIdx(char ch){
	return ch - 'A';
}

void reduceCount(int countAlp[], string str){
	for(int i = 0 ; i < str.length() ; i++)
		countAlp[getIdx(str[i])]--;
	//return countAlp;
}

int getDigits(int countAlp[]){
	if(countAlp['Z' - 'A'] > 0)
	{	
		reduceCount(countAlp, "ZERO");
		return 0;
	}
	
	else if(countAlp[getIdx('W')] > 0)
	{
			reduceCount(countAlp, "TWO");
			return 2;
	}

	else if(countAlp[getIdx('F')] > 0){
			if(countAlp[getIdx('U')] > 0){
				reduceCount(countAlp, "FOUR");
				return 4;
			}
			else{
				reduceCount(countAlp, "FIVE");
				return 5;
			}
	}	

	else if(countAlp[getIdx('X')] > 0){
			reduceCount(countAlp, "SIX");
			return 6;
	}	
	
	else if(countAlp[getIdx('S')] > 0){
		reduceCount(countAlp, "SEVEN");
		return 7;
	}

	else if(countAlp[getIdx('G')] > 0){
			reduceCount(countAlp, "EIGHT");
			return 8;
	}	

	else if(countAlp[getIdx('O')] > 0){
		reduceCount(countAlp, "ONE");	
		return 1;
	}

	else if(countAlp[getIdx('N')] > 0){
		reduceCount(countAlp, "NINE");
		return 9;
	}

	else
		reduceCount(countAlp, "THREE");
	return 3;
}

int main(){
	int i,j,k,l;
	int N, T;
	cin>>T;
	int countAlp[26];
  int countNum[26];
	string str;
	for(l = 0 ; l < T ; l++)
	{
		cin>>str;
		//cout<<str<<"\n";
		for(i = 0 ; i < 26 ; i++)
			countAlp[i] = 0;
		for(i = 0 ; i < 10 ; i++)
			countNum[i] = 0;
		for(i = 0 ; i < str.length() ; i++)
			countAlp[str[i] - 'A']++;

		//for(i = 0 ; i < 26 ; i++)
			//cout<<countAlp[i];
		
		while(true){
			for(i = 0 ; i < 26 ; i++)
				if(countAlp[i] > 0)
					break;
			if(i == 26)
				break;
			int num = getDigits(countAlp);
			//cout<<num<<"\t";
			countNum[num]++;		
		}
		
		cout<<"Case #"<<l+1<<": ";
		for(i = 0 ; i < 10 ; i++){
			for(j = 0 ; j < countNum[i] ; j++)
				cout<<i;
		}
		cout<<"\n";
	}
}
