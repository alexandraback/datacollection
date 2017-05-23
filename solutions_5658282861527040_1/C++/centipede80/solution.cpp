#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int SAME=0,BIGGER=1,SMALLER=2;

int getNewStatus(int N, int bit, int comp, int isOn) {
	if(isOn) {
		if((1<<bit)&N) {
			return comp;
		}
		if(comp==SMALLER) return SMALLER;
		return BIGGER;
	}
	else {
		if(!((1<<bit)&N)) {
			return comp;
		}
		if(comp==BIGGER) return BIGGER;
		return SMALLER;
	}
}

long long mem[31][3][3][3];

long long doit2(int A, int B, int K, int bit, int comp1, int comp2, int comp3) {
	long long ret=0;
	if(bit==-1) return (comp3==SAME)||(comp3==SMALLER);
	if(mem[bit][comp1][comp2][comp3]!=-1)
		return mem[bit][comp1][comp2][comp3];
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) {
		int newComp1=getNewStatus(A,bit,comp1,i);
		int newComp2=getNewStatus(B,bit,comp2,j);
		int newComp3=getNewStatus(K,bit,comp3,i&j);
		if(newComp1==BIGGER) continue;
		if(newComp2==BIGGER) continue;
		if(newComp3==BIGGER) continue;
		ret=ret+doit2(A,B,K,bit-1,newComp1,newComp2,newComp3);
	}
	return mem[bit][comp1][comp2][comp3]=ret;
}

long long doit(int A, int B, int K) {
	memset(mem,-1,sizeof(mem));
	return doit2(A-1,B-1,K-1,30,SAME,SAME,SAME);
}

int main()
{
	ifstream infile;
	//string prefix = "B-large-practice";
	//string prefix = "practice";
	string prefix = "B-large";
	//string prefix = "B-small-attempt0";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		int A,B,K;
		infile>>A>>B>>K;
		long long ret=doit(A,B,K);
		outfile << "Case #" << (i+1) << ": " << ret << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}