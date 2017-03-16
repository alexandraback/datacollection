#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_map>

#define D(x) x

using namespace std;

string solve(const string& input, unordered_map<string,string>& memo) {
	if (input == "") return "";

	auto it = memo.find(input);
	if (it != memo.end()) {
		return it->second;
	}

	string best;
	for (int first = 0; first < input.length(); first++) {
		string current = input.substr(first, 1) 
			+ solve(input.substr(0, first), memo)
			+ input.substr(first+1, input.length());
		best = max(best, current);
	}

	memo[input] = best;
	return best;
}
int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
    	unordered_map<string, string> memo;
    	string S;
    	cin >> S;
    	string result = solve(S, memo);


        cout << "Case #" << testCase << ": " << result << endl;
    }
}
