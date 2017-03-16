//============================================================================
// Name        : codejamQR2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int t,d,k;
int a[1000],b[1000];
int main() {
	ifstream in("input");
	ofstream out("output");
	in>>t;
	for(int p = 0; p<t; p++){
		in >> d;
		memset(a,0,sizeof(a));
		int max = 0;
		for(int i = 0; i < d; i++){
			in>>k;
			if(k > max)
				max = k;
			for (int j = 1; j < k; j++){
				a[j] = a[j]+(k-1)/j;
			}
		}
		int min = max;
		for(int j = 1; j<max; j++){
			if (a[j]+j < min)
				min = a[j]+j;
		}
		out<<"Case #"<<p+1<<": "<<min<<'\n';
	}
	return 0;
}
