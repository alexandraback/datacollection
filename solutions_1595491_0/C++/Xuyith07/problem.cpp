#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int f1(int n){
	if(n==1)return 1;
	return 3*n-2;
}
int f2(int n){
	if(n==1)return 1;
	return 3*n-4;
}

int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("B-small-attempt0.in");
	out.open("out.txt");
	in>>CaseNum;
	int T,S,p,t,type1,type2,th1,th2;
	for(int Case=0;Case<CaseNum;Case++){
		in>>T>>S>>p;
		th1=f1(p);th2=f2(p);
		type1=0;type2=0;
		for(int i=0;i<T;i++){
		 in>>t;
		 if(t>=th1)type1++;
		 else if(t>=th2)type2++;
		}
		if(type2>S)type2=S;

	out<<"Case #"<<Case+1<<": "<<type1+type2<<endl;
	}
	out.clear();
	out.close();
	return 0;
}