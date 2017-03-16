// R1A_A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

unsigned long long bsearch(unsigned long long n, unsigned long long r,unsigned long long t)
{
	unsigned long long b = n/2,top=n;
	r*=2;
	while(b<top){
		unsigned long long mid = (b+top)/2;
		if(mid*(r+2*mid-1)==t) return mid;
		if(mid*(r+2*mid-1)>t){
			if((mid-1)*(r+2*(mid-1)-1)<=t)
				return mid-1;
			top=mid;
		}
		else{
			if((mid+1)*(r+2*(mid+1)-1)==t)
				return mid+1;
			else if((mid+1)*(r+2*(mid+1)-1)>t)
				return mid;
			b=mid;
		}
	}
	return top;
}

int main()
{
	ifstream infile("A-large.in");
	ofstream outfile("out.txt");
	int T;
	infile>>T;
	unsigned long long r,t;
	for(int i=0;i<T;i++){
		infile>>r>>t;
		unsigned long long n=1;
		for(;;n*=2){
			if(t<n*(2*r+2*n-1)){
				n=bsearch(n,r,t);
				break;
			} 
		}
		char cval[5];
		sprintf(cval,"%d",i+1);
		string linehead="Case #"+string(cval);
		outfile<<linehead+": "+to_string(unsigned long long(n))<<endl;
	}
}

