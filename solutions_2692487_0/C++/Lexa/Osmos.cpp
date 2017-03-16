//============================================================================
// Name        : Osmos.cpp
// Author      : J.Son
// Version     :
// Copyright   : GNU LGPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; i++) {
		int a, n, best, curSum, curBest;
		vector<int> nums;
		cin >> a >> n;
		best = n;
		curBest = n;
		curSum = a;
		for(int j = 0; j < n; j++) {
			int num;
			cin >> num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		if(curSum > 1) {
			for(int j = 0; j < n; j++) {
				if(nums[j] < curSum) {
					curSum += nums[j];
					curBest--;
				} else {
					int pow = 0;
					curSum = curSum * 2 -1;
					while(curSum <= nums[j]) {
						curSum = curSum * 2 -1;
						pow++;
					}
					curSum += nums[j];
					curBest += pow;
				}
				if(best > curBest) {
					best = curBest;
				} else if(curBest >= best + n - j - 1) {
					break;
				}
			}
		}
		cout << "Case #" << i << ": " << best << endl;
	}
	return 0;
}
