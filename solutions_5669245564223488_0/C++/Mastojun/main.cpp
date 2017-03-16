#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int T;
int N;

vector<string> train;
int counter[26];

bool isValid(vector<string>& temp) {
	string trains = "";
	for(int i = 0; i < temp.size(); i++) {
		trains += temp[i];
	}

	bool appear[26] = {0,};

	appear[trains[0] - 'a'] = 1;

	for(int i = 1; i < trains.length(); i++) {
		if(trains[i] != trains[i-1]) {
			if(appear[trains[i] - 'a'] == 1) return false;
			appear[trains[i] - 'a'] = 1;
		}
	}

	return true;
}

vector<bool> isUsed;
vector<string> temp;

int solve(int cnt) {
	if(cnt == N) {
		return isValid(temp) ? 1 : 0;
	}

	int result = 0;
	for(int i = 0; i < N; i++) {
		if(isUsed[i] == false) {
			isUsed[i] = true;
			temp.push_back(train[i]);
			result += solve(cnt + 1);
			temp.pop_back();
			isUsed[i] = false;
		}
	}
	return result;
}

int main() {

	cin >> T;

	for(int c = 1; c <= T; c++) {
		cin >> N;

		train.clear();
		
		for(int i = 0; i < N; i++) {
			string in;
			cin >> in;
			train.push_back(in);
		}
		
		isUsed = vector<bool>(N, false);

		int result = solve(0);
		
		cout << "Case #" << c << ": " << result << endl;
		fprintf(stderr, "Case #%d\n", c);
	}

	return 0;
}
