//============================================================================
// Name        : codeJamQR4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int t, x, r, c;
int main() {
	ifstream in("input");
	ofstream out("output");
	in>>t;
	for(int p = 0; p < t; p++){
		in >>x >>r >>c;
		switch (x){
				case 1:
					out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					break;
				case 2:
					if (r*c%2 == 0)
						out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					else
						out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					break;
				case 3:
					if(r<2 || c<2 || r*c%3!=0)
						out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					else
						out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					break;
				case 4:
					if(r<3 || c<3 || r*c%4!=0)
						out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					else
						out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					break;
				case 5:
					if(r<4 || c<4 || r*c%5 != 0)
						out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					else
						out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					break;
				case 6:
					if (r<4 || c<4 || r*c%6 != 0)
						out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					else
						out<<"Case #"<<p+1<<": GABRIEL"<<'\n';
					break;
				default:
					out<<"Case #"<<p+1<<": RICHARD"<<'\n';
					break;
		}
	}
	return 0;
}
