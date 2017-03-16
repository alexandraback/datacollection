#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int nCase=1; nCase<=nCases; nCase++) {
		cout<<"Case #"<<nCase<<": ";
		int R,C,W;
		cin>>R>>C>>W;
		if(W==1) {cout<<R*C<<endl; continue;}
		int ntries=R*(C/W)+W;
		if(!(C%W)) ntries--;
		cout<<ntries<<endl;
	}

	return 0;
}
