#include <iostream>
#include <string>

using namespace std;

int main(){
	int TC, c = 1;
	cin >> TC;
	while (TC--){
		string input, answer;
		cin >> input;
		answer = input[0];
		for (int i = 1; i < input.length(); i++){
			if (input[i] >= answer[0])
				answer = (input[i] + answer);
			else
				answer = (answer + input[i]);	
		}
		cout << "Case #" << c++ << ": " << answer << endl;
	}
}
