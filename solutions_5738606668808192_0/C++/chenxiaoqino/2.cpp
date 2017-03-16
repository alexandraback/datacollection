#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N=16,J=50;

long long jz(string s,int j){
	long long ret=0;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[l-i-1]=='1')
		ret+=pow(j,i);
	return ret;
}

string verify(string s){
	for(int j=2;j<=10;j++)
		if(jz(s,j)%(j+1)!=0)return "!";
	string ans=" 3 4 5 6 7 8 9 10 11";
	return ans;
}

void checkall(){
	string s;
	//odd:p1=1 even:pN=1
	for(int i=2;i<=N/2;i++)
		for(int j=1;j<N/2;j++){
			s="";
			for(int k=1;k<=N/2;k++){
				char c1='0',c2='0';
				if(k==1 || k==i)c1='1';
				if(k==N/2 || k==j)c2='1';
				s+=c1;
				s+=c2;
			}

			cout<<s<<verify(s)<<endl;			
		}
	s="";for(int i=0;i<N;i++)s+='1';

	cout<<s<<verify(s)<<endl;
}

int main(){
	cout<<"Case #1:"<<endl;
	checkall();
	return 0;
}