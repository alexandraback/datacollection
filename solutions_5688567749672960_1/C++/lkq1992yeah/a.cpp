#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool flag = false;

long long num;
long long msk[20];
int arr[20], digits = 0, arr2[20];


void initMsk() {
	msk[0] = 1;
	for (int i = 1; i < 16; i++)
		msk[i] = msk[i - 1] * 10;
}

void splitNum(long long num) {
	digits = 0;
	while (num) {
		arr[digits] = num % 10;
		num /= 10;
		digits++;
	}
	// for (int i = digits - 1; i >= 0; i--)
		// cout << arr[i];
	// cout << endl;
}

long long getMiddle(int smallLevel) {		//3: 1000 --> 10000
	long long ret = msk[smallLevel + 1] - msk[smallLevel];
	for (int i = 0; i <= smallLevel; i++) {
		long long tmp = (msk[i] - 1) + (msk[smallLevel - i + 1] - 1) + 1;
		if (ret == -1) ret = tmp;
		else if (tmp < ret) ret = tmp;
	}
	if (flag)
		cout << "Middle: " << smallLevel << ", ret: " << ret << endl;
	return ret;
}

long long getUpdated(long long small, long long big) {
	if (small < msk[digits - 1]) return msk[15];
	if (num < big) return msk[15];			//invalid, return a very big number
	long long ret = (small - msk[digits - 1]) + 1 + (num - big);
	if (big == small) ret--;
	return ret;
}

long long getTail(int changePos) {
	if (changePos == digits) {		//no change, just add directly
		long long ret = num - msk[digits - 1];
		if (flag) 
			cout << "Tail at " << changePos << ": " << ret << endl;
		return ret;
	} else {
		for (int i = 0; i < digits; i++)
			arr2[i] = arr[i];
		arr2[changePos]--;
		for (int i = changePos; i < digits; i++) {
			if (arr2[i] < 0) {
				arr2[i + 1]--;
				arr2[i] += 10;
			}
		}
		long long big = 0;
		long long small = 0;
		long long big2 = -1, small2 = -1;
		int count = 0;
		for (int i = digits - 1; i >= changePos; i--) {
			big += msk[i] * arr[i];
			small += msk[count] * arr[i];
			big2 += msk[i] * arr2[i];
			small2 += msk[count] * arr2[i];
			count++;
		}
		if (changePos > 0) {
			big += 1;
			small += msk[digits - 1];
			big2 += 1;
			small2 += msk[digits - 1];
		}
		
		long long tmp = msk[15];
		
		long long choice1 = getUpdated(small, big);
		if (flag)
			cout << "Tail at (" << changePos << ", choice1): " << small << ", " << big << ", " << choice1 << endl;
		if (choice1 < tmp) tmp = choice1;
		
		long long choice2 = getUpdated(small2, big2);
		if (flag)
			cout << "Tail at (" << changePos << ", choice2): " << small2 << ", " << big2 << ", " << choice2 << endl;
		if (choice2 < tmp) tmp = choice2;
		
		return tmp;
	}
}

long long solve() {
	cin >> num;
	splitNum(num);
	if (flag) 
		printf("Digits: %d\n", digits);
	long long ret = 1;
	for (int i = 0; i < digits - 1; i++) {
		long long step = getMiddle(i);
		ret += step;
	}
	if (flag) 
		cout << "Halfway: " << ret << endl;
	long long tmp = getTail(digits);
	for (int i = digits - 1; i >= 0; i--) {
		long long tail = getTail(i);
		if (tmp == -1) tmp = tail;
		else if (tail < tmp) tmp = tail;
	}
	if (flag) 
		cout << "tmp: " << tmp << endl;
	ret += tmp;
	if (flag)   
		cout << "ret: " << ret << endl;
	return ret;
}

int main() {
	int t, cas;
	initMsk();
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++) {
		int ret = solve();
		cout << "Case #" << cas << ": " << ret << endl;
	}
	return 0;
}