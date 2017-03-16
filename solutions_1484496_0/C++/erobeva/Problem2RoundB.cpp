/*
 *  Problem2RoundB.cpp
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
using namespace std;


int equal_sum(vector<int> nums, vector<int>a, int suma, vector<int>b, int sumb, int n, int total) {
	if(a.size() > 0 && b.size() > 0 && suma == sumb){
		cout << endl;
		for(int i = 0; i < a.size(); ++i){
			cout << a[i] << " ";
		}
		cout << endl;
		for(int i = 0; i < b.size(); ++i){
			cout << b[i] << " ";
		}
		cout << endl;
		return 1;
	}
	if(suma > total / 2 || sumb > total/2){
		return 0;
	}
	if(nums.size() > n){
		if(suma < sumb + nums[n]){
			vector<int> a1(a.size() + 1);
			for(int i = 0; i < a.size(); ++i){
				a1[i] = a[i];
			}
			a1[a.size()] = nums[n];
			int x = equal_sum(nums, a1, suma + nums[n], b, sumb, n+1, total);
			if (x == 1) {
				return 1;
			}
			vector<int> b1(b.size() + 1);
			for(int i = 0; i < b.size(); ++i){
				b1[i] = b[i];
			}
			b1[b.size()] = nums[n];
			int y = equal_sum(nums, a, suma, b1, sumb + nums[n], n+1, total);
			if(y == 1) {
				return 1;
			}
		} else {
			vector<int> b1(b.size() + 1);
			for(int i = 0; i < b.size(); ++i){
				b1[i] = b[i];
			}
			b1[b.size()] = nums[n];
			int y = equal_sum(nums, a, suma, b1, sumb + nums[n], n+1, total);
			if(y == 1) {
				return 1;
			}			
			vector<int> a1(a.size() + 1);
			for(int i = 0; i < a.size(); ++i){
				a1[i] = a[i];
			}
			a1[a.size()] = nums[n];
			int x = equal_sum(nums, a1, suma + nums[n], b, sumb, n+1, total);
			if (x == 1) {
				return 1;
			}
		}
		int z = equal_sum(nums, a, suma, b, sumb, n+1, total);
		if(z == 1){
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int main() {
	freopen("/Users/erobeva/Downloads/C-small-attempt2.in","r",stdin);
	freopen("/Users/erobeva/Downloads/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOut.txt", "w", stdout);
	int T;
	cin >> T;
	
	for(int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<int> nums(N);
		int total = 0;
		for(int j = 0; j < N; ++j) {
			cin >> nums[j];	
			total += nums[j];
		}
		//sort(nums.begin(), nums.end());
		//reverse(nums.begin(), nums.end());
		cout << "Case #" << i + 1 << ": ";	
		vector<int> a(0);
		vector<int> b(0);
		int result = equal_sum(nums, a, 0, b, 0, 0, total);
		if(result == 0) {
			cout << "Impossible" << endl;
		}
	}
	
}