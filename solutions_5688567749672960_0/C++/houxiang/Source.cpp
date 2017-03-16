#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>

#include <Windows.h>

using namespace std;

const int SZ = 1000010;

vector<long long> nums; 

long long reverse(long long n) {
	long long result = 0; 
	while (n >= 10) {
		long long t = n % 10; 
		result = result * 10 + t;
		n /= 10; 
	}

	result = result * 10 + n;

	return result; 
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]); 

	int TC = 0; 
	inf >> TC; 

	nums.resize(SZ);
	for (long long i = 1; i < SZ; i++)
		nums[i] = i;

	for (long long i = 1; i < SZ; i++) {
		long long tr = reverse(i);
		
		if (tr >= SZ)
			continue;

		long long tn = nums[i] + 1;
		if (nums[tr] > tn) {
			nums[tr] = tn;
			for (long long j = tr + 1; j < SZ; j++) {
				if (nums[tr] + (j - tr) >= nums[j])
					break;
				else
					nums[j] = nums[tr] + (j - tr);
			}
		}
	}

	for (int tc = 1; tc <= TC; tc++) {
		long long n; 

		inf >> n; 

		cout << "Case #" << tc << ": " << nums[n] << endl;
	}

	return 0; 
}