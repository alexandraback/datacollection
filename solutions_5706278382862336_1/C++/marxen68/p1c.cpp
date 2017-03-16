/*
 * p1c.cpp
 *
 *  Created on: May 11, 2014
 *      Author: marxen68
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define TYPE long int

TYPE gcd(TYPE a, TYPE b) {  // a>b
	if(b > a) return gcd(b,a);
	if(b == 0) return a;
	TYPE r = 0;
	while(b != 0 && a%b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return b;
}

int checkIfHasPrimeDiv(TYPE q) {
	int count = 0;
	while(q%2 == 0) {
		q = q/2;
		count++;
	}

	if(q > 1) return -1;
	return count;
}

void solve(TYPE P, TYPE Q, int tcase) {
	if(P >= Q) {
		cout << "Case #" << tcase << ": impossible" << endl;
		return;
	}
	TYPE G = gcd(P,Q);
	P /= G;
	Q /= G;
	int n = checkIfHasPrimeDiv(Q);
	if(n < 0) {
		cout << "Case #" << tcase << ": impossible" << endl;
		return;
	}

	// So Q has the form 2^n
	int count = 0;
	while(P / Q < 1) {
		P *= 2;
		count++;
	}
	cout << "Case #" << tcase << ": " << count << endl;
	return;
}

vector<TYPE> split(const string &str, char delim){
	size_t current = 0, found;
	vector<TYPE> res;
	TYPE temp;
	while((found = str.find_first_of(delim, current)) != string::npos){
		temp = stol(string(str, current, found - current));
		current = found + 1;
		res.push_back(temp);
	}
	temp = stol(string(str, current, str.size() - current));
	res.push_back(temp);
	return res;
}

int main(void) {
	int T, tcase = 1;
	TYPE P = 0, Q = 0;
	string a;
	cin >> T;
	while(T>0) {
		cin >> a;
		vector<TYPE> tmp = split(a,'/');
		vector<TYPE>::iterator it = tmp.begin();
		int count = 0;
		for( it = tmp.begin(); it != tmp.end(); ++it )
		{
			if(count == 0) P = *it;
			if(count == 1) Q = *it;
			count++;
		}
		solve(P,Q,tcase);
		tcase++;
		T--;
	}
}



