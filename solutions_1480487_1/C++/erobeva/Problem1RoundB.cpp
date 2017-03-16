/*
 *  Problem1RoundB.cpp
 *  GoogleCodeJamPractice
 *
 *  Created by Elina Robeva on 5/5/12.
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
using namespace std;


int main() {
	freopen("/Users/erobeva/Downloads/A-large (2).in","r",stdin);
	freopen("/Users/erobeva/Downloads/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOut.txt", "w", stdout);
	int T;
	cin >> T;
	
	for(int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<long long> s(N);
		long long X = 0;
		for(int j = 0; j < N; ++j) {
			cin >> s[j];
			X += s[j];
		}
		cout << "Case #" << i + 1 << ": ";	
		for(int j = 0; j < N; ++j) {
			double min = 100.0;
			for(int l = 0; l < N; ++l) {
				if(s[j] > s[l]) {
					continue;
				}
				long long Y = 0;
				int count = 0;
				for(int k = 0; k < N; ++k){
					if(s[k] <= s[l]) {
						Y += s[k];
						count++;
					}
				}
				if(count == 1){
					if(100.0 * ((((double)(X + X)/(double)N) - (double)s[j])/(double)X) < min) {
						min = 100.0 * ((((double)(X + X)/(double)N) - (double)s[j])/(double)X);
					}
					//cout << setprecision(10) << 100.0 * ((((double)(X + X)/(double)N) - (double)s[j])/(double)X) << " ";
					continue;
				}
				if((double)s[j] >= (double)(X + Y)/(double)count){
					min = 0.0;
				} else {
					if(100.0 * ((((double)(X + Y)/(double)count) - (double)s[j])/(double)X) < min) {
						min = 100.0 * ((((double)(X + Y)/(double)count) - (double)s[j])/(double)X);
					}
				}
			}
			cout << setprecision(10) << min << " ";
		}
		
		
		
		
		
		
		
		/*long long Y = 0;
		int count = 0;
		for(int j = 0; j < N; ++j) {
			if((double)s[j] < (double)total/(double)N) {
				Y += s[j];
				count++;
			}
		}
		
		
		for(int j = 0; j < N; ++j) {
			if((double)s[j] >= (double)total/ N){
				cout << 0.0 << " ";
				continue;
			}
			double a = 100.0 * ((((double)total/(double)N) - (double)s[j])/(double)X);
			double b = 100.0 * ((((double)(X + Y)/(double)count) - (double)s[j])/(double)X)
			if(a >= 0) {
				cout << setprecision(10) << a << " ";
			} else {
				cout << 0 << " ";
			}
		} */
		cout << endl;
	}
	
}