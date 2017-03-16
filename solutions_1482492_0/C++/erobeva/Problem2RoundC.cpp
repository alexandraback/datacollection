/*
 *  Problem2RoundC.cpp
 *  GoogleCodeJamPractice
 *
 *  Created by Elina Robeva on 5/6/12.
 *  Copyright 2012 Stanford University. All rights reserved.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;


int main() {
	freopen("/Users/erobeva/Downloads/B-small-attempt0 (3).in","r",stdin);
	freopen("/Users/erobeva/Downloads/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOut.txt", "w", stdout);
	int T;
	cin >> T;
	
	for(int i = 0; i < T; ++i) {
		double D;
		int N, A;
		cin >> D;
		//cout << D << endl;
		cin >> N;
		cin >> A;
		//cout << N << " " << A << " " << endl;
		vector<double> t(N);
		vector<double> x(N);
		vector<double> v(N);
		for(int j = 0; j < N; ++j) {
			cin >> t[j] >> x[j];
			if(j > 0) {
				v[j-1] = (x[j] - x[j-1])/(t[j]- t[j-1]);
			}
		}
		cout << "Case #" << i + 1 << ": ";
		//vector<double> a(A);
		//cout << A << " " << N << " " << D << endl;
		for(int s = 0; s < A; ++s) {
			double a;
			cin >> a;
			double m = 0.0; // my speed
			double y = 0.0; // my location
			double time = 0.0;
			int met = 0;
			for(int j = 0; j < N-1; ++j) {
				if(y + m * (t[j+1] - t[j]) + a * (t[j+1] - t[j])*(t[j+1]-t[j])/2.0 > x[j+1]) {
					if(x[j+1] < D) {
						y = x[j+1];
						m = v[j];
					} else {
						met = 1;
						double t_meet_car = (-m + v[j] + sqrt((m - v[j])*(m - v[j])-2*a*(y - x[j])))/a;
						double t_meet_D = (-m + sqrt(m*m - 2*a*(y-D)))/a;
						if(t_meet_D <= t_meet_car) {
							
							time = t[j] + t_meet_D;
						} else {
							
							time = t[j] + (D - x[j]) / v[j];
						}
						break;
					}
				} else {
					if(m * (t[j+1] - t[j]) + a * (t[j+1] - t[j])*(t[j+1]-t[j])/2.0 < D) {
						y += m * (t[j+1] - t[j]) + a * (t[j+1] - t[j])*(t[j+1]-t[j])/2.0;
						m += a * (t[j+1] - t[j]);
					} else {
						time = t[j] + (-m + sqrt(m*m - 2*a*(y-D)))/a;
						met = 1;
						break;
					}
				}
			}
			if(met != 1) {
				met = 1;
				time = t[N-1] + (-m + sqrt(m*m - 2*a*(y-D)))/a;
				
			}
			
			cout << setprecision(10) << time << endl;
			
			
			
		}
		
		
		
		
	}
	
}