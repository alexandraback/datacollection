/*
 * 
 *  Created by Xiaojun Zhang.  All rights reserved.
 *
 */


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
using namespace std;
const int MAX = 100005;
int T,A,B;
double p_i[MAX];
double p_co[MAX];
double expt[MAX];


std::string doubleToText(const double & d)
{
    std::stringstream ss;
    //ss << std::setprecision( std::numeric_limits<double>::digits10+2);
    ss << std::setprecision( std::numeric_limits<int>::max() );
    ss << d;
    return ss.str();
}

int main(int argv, char** args){
	ifstream in;
	in.open("password_large.in");
	ofstream out;
	out.open("password_large.out");
	in >> T;
	for (int i = 0; i < T; i++){
		in >> A>>B;
		
		for (int j = 0; j < A ; j++){
			in >> p_i[j];
			if ( j == 0) p_co[j] = p_i[j];
				else p_co[j] = p_co[j-1]*p_i[j];
		}
		for ( int j = 0; j< A; j++){
			int s = A-j-1;
			if ( 1- p_co[s] < 0.000000000001) // p_co[s]  == 1
				expt[j] = B-A+1+2*j;
			else expt[j] = (B-A+1+2*j)*p_co[s] + (B-A+1+j*2+B+1) * (1-p_co[s]);
		}
		expt[A] = B+2;
		double minimal = B*3;
		for ( int j = 0; j <= A ; j++){
			if ( minimal > expt[j] ) minimal = expt[j];
		}
		
		out << "Case #" << i+1<<": "  << doubleToText(minimal) << endl ;
	}
}