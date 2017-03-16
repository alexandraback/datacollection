#include <bits/stdc++.h>
using namespace std;
int pf (int n){
	if (n==1) return 0;
	if (n%2==0) return n;
	return n-1;
}

int mf (int n){
	if (n%2==1) return n;
	return n-1;
	
}

int ct;

void print (int n){
	cout<<"Case #"<<ct<<": "<<n<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for (ct=1; ct<=t; ct++) {
		string s;
		cin>>s;
		int st=1;
		for (int i=0; i<s.size()-1; i++) st+=(s[i]!=s[i+1]);
		if (s[0]=='+') print(pf(st));
		else print(mf(st));
	}
	
	return 0;
}