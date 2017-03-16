#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rankandFile(vector<int> nums) {
	int a[2500] = {0};
	vector<int> ans;
	for (int i = 0; i < nums.size(); ++i) {
		if (a[nums[i]] == 0) a[nums[i]]++;
		else a[nums[i]]--;
	}
	for (int i = 0; i < 2500; ++i) {
		if (a[i] == 1) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

void print_vec(vector<int> vec) {
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ',';
	}
	cout << endl;
}

int main() {
	ifstream input("B-large.in");
	ofstream output("rankandFile_large_answer.txt");
	string num;
	getline(input, num);
	int n = stoi(num);
	for (int i = 0; i < n; ++i) {
		output << "case #" << i + 1 << ": ";
		getline(input, num);
		int N = stoi(num);
		vector<int> allnums;
		for (int j = 0; j < (2 * N - 1); ++j) {
			getline(input, num);
			for (int k = 0; k < N; ++k) {
				int pos = num.find_first_of(' ');
				int temp = stoi(num.substr(0, pos));
				num = num.substr(pos + 1);
				allnums.push_back(temp);
			}
		}
		//print_vec(allnums);
		vector<int> miss = rankandFile(allnums);
		for (int j = 0; j < miss.size(); ++j) {
			output << miss[j] << " ";
		}
		output << endl;
	}
	return 0;
}