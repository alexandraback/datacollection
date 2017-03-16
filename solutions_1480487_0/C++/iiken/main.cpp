/*
 * 
 *  Created by Xiaojun Zhang.  All rights reserved.
 *
 */


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <iomanip>


std::string doubleToText(const double & d)
{
    std::stringstream ss;
    //ss << std::setprecision( std::numeric_limits<double>::digits10+2);
    ss << std::setprecision( 8 );
    ss << d;
    return ss.str();
}

using namespace std;
const int maxn = 200;
int T,N;
int a[maxn];
double b[maxn];
int main(int argv, char** args){
	ifstream in;
	in.open("safe_small.in");
	ofstream out;
	out.open("safe_small.out");
	in >> T;
	for (int i = 0; i < T; i++){
		in >> N;
		int sum = 0;
		int sum2 = 0;
		int m = 0;
		for ( int j = 0; j < N; j++){
			in >> a[j];
			sum += a[j];
		}
		sum2 = sum;
		
		
		for ( int j = 0 ; j < N ;j++){
			b[j] = (double)(2*sum - N*a[j])/N/sum *100;
			if ( b[j] < 0 ) {
				m++;
				sum2 = sum2 - a[j];
			}
		}
		
		out << "Case #" << i+1<<": ";
		double res;
		for ( int j = 0; j < N; j++){
			if ( b[j] > 0) {
				res = (double)(sum + sum2 - (N-m)* a[j])/sum /(N-m) *100; 
				string res_str = doubleToText(res);
				out << res_str << " ";
			}else{
				out << 0.00 << " ";
			}
			
		}
		
		
		out << endl;
		
	}
}