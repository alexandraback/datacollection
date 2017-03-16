#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <set>

using namespace std;

vector <string> numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main(void) {
//the hypothesis, tested but not proved, is that few (probably less than 100 turns) are needed, and 0 is the only problematic case
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		string S;
		cin>>S;
		
		vector <int> C(26, 0);
		for (char c : S) C[c-'A']++;
		
		string solution;
		
		vector <int> order = {0,2,4,6,3,5,7,8,1,9};
		vector <char> mark = {'Z','O','W','R','U','F','X','S','H','I'};
		
		for (int i=0; i<10; i++) {
			int curr = order[i];
			while (C[mark[curr]-'A']) {
				for (char m : numbers[curr]) C[m-'A']--;
				solution += to_string(curr);
			}
		}
		
		sort(solution.begin(), solution.end());
		
		cout<<"Case #"<<test<<": " << solution <<"\n";
	}
	return 0;
}
