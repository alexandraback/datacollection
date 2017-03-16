/*
 * Codejam 2012: Round 1A
 * Author: Mahmoud Aladdin (Platter)
 * 
 */

#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long _long;
typedef vector<int> _vi;
typedef pair<int, int> _pii;
typedef vector<_pii> _vpii;
typedef vector<string> _vs;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPit(it, rit) for(typeof(rit.begin()) (it) = (rit).begin(); (it) != (rit).end(); ++(it))
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define PB(m) push_back(m)
#define MP(a, b) make_pair(a, b)

int A, B;

double mul(vector<double> p, int end){
	double a = 1.0;
	for(int i = 0; i < end; i++){
		a *= p[i];
	}
	return a;
}

double continue_(vector<double> pA, int end, int esc){
	double suc = mul(pA, end);
	double re = B - end + 1 + esc;
	return suc * re + ((1 - suc) * (re + B + 1));
}

int main(){
	ifstream file_in("A.in");
	ofstream file_out("A.out");
	
	int T;
	file_in >> T;
	for(int tt = 1; tt < T + 1; ++tt){
		file_in >> A >> B;
		vector<double> pA;
		REP(i, A) {
			double temp; file_in >> temp;
			pA.PB(temp);			
		}
		double min_case = B + 2;
		for(int i = A; i > 0; i--){
			min_case = min(min_case, continue_(pA, i, A - i));
		} 
		cout << tt << endl;
		file_out << "Case #" << tt << ": " << min_case << endl;
		
	}
	cout << "Program Terminated";
	return 0;
}
