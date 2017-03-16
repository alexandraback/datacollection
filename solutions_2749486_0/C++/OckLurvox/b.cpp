/*
 * b.cpp
 *
 *  Created on: 12-05-2013
 *      Author: Ock
 */

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ifstream scanner;
ofstream out;
int X;
int Y;
int T;
int testcase;
int min = 501;
/*
string solve(int x,int y, int i, string s){
	if(X==x && Y==y && i<=500){
		return s;
	}
	else{
		string a=solve(x,y+i,i+1,s+"N");
		string b=solve(x,y-i,i+1,s+"S");
		string c=solve(x+i,y,i+1,s+"E");
		string d=solve(x-i,y,i+1,s+"W");

		int minimum = a.length();
		string sol=a;
		if(minimum > b.length()){
			minimum = b.length();
			sol=b;
		}
		if(minimum > c.length()){
			minimum = c.length();
			sol=c;
		}
		if(minimum > d.length()){
			minimum = d.length();
			sol=d;
		}

		return sol;

	}
}
*/

string goUp(){
	return "SN";
}
string goDown(){
	return "NS";
}
string goLeft(){
	return "WE";
}
string goRight(){
	return "EW";
}


void solve(){
	string sol="";

	if(X>0){
		for (int i = 0; i < X; ++i) {
			sol+=goLeft();
		}
	}
	else if(X<0){
		for (int i = 0; i < -X; ++i) {
			sol+=goRight();
		}
	}

	if(Y>0){
		for (int i = 0; i < Y; ++i) {
			sol+=goUp();
		}
	}
	else if(Y<0){
		for (int i = 0; i < -Y; ++i) {
			sol+=goDown();
		}
	}


	out << "Case #" << testcase << ": " << sol << endl;
}

int main(){

	scanner.open("B-small-attempt0.in");
	out.open("output.txt");

	scanner >> T;
	for (int i = 1; i <= T; ++i) {
		testcase = i;
		scanner >> X >> Y;
		solve();
	}



	scanner.close();
	out.close();


	return 0;
}





