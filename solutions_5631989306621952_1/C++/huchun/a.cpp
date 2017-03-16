#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

string func(const string& s){
	string res="";
	int len=s.length();
	for (int i=0;i<len;++i){
		string resb=res+s[i];
		res=s[i]+res;
		if (res<resb) res=resb;
	}
	return res;
}

int main(){
	ofstream myfile;
  	myfile.open ("outputa.txt");
  	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		string s;
		cin>>s;
		myfile<<"Case #"<<i<<": ";
		myfile<<func(s)<<endl;
	}
  	myfile.close();
  	return 0;
}
