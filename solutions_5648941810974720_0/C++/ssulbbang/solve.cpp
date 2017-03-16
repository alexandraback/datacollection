#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {

	int t;
	string v[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int order[10] = {0, 2, 6, 8, 4, 5, 7, 3, 1, 9};
	string key = "ZWXGUFVROI";
	cin >> t;

	for(int i = 1; i <= t; i++) {
		string code;
		cin >> code;
		map<char, int> count;
		map<int, int> answer;

		for(int j = 0; j < code.size(); j++) {
			count[code[j]]++;
		}

		for(int j = 0; j < 10; j++) {
			answer[order[j]] += count[key[j]];
			for(int k = 0; k < v[order[j]].size(); k++) {
				count[v[order[j]][k]] -= answer[order[j]];
			}
		}

		cout << "Case #" << i << ": ";
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < answer[j]; k++) {
				cout << j;
			}
		}
		cout << endl;
	}

	return 0;
}
