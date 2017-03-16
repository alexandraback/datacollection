#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> reconstructString(string S) {
	vector<string> result;
	result.clear();
	string candidate = "";
	result.push_back(candidate);
	for (int i = 0; i < S.length(); i++) {
		if (S.at(i) == '?') {
			int size = result.size();
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < 10; k++) {
					string copy = result.at(j);
					copy.push_back(k + '0');
					result.push_back(copy);
				}
			}
		}
		else {
			for (int j = 0; j < result.size(); j++)
				result.at(j).push_back(S.at(i));
		}
			
	}

	vector<string> correct;
	correct.clear();
	for (int i = 0; i < result.size(); i++) {
		if (result.at(i).length() == S.length())
			correct.push_back(result.at(i));
	}

	return correct;
}

void compareString(vector<string> C_, vector<string> J_, string &C, string &J) {
	int min = RAND_MAX;
	for (int i = 0; i < C_.size(); i++) {
		for (int j = 0; j < J_.size(); j++) {
			if (abs((stoi(C_.at(i)) - stoi(J_.at(j)))) < min)
				min = abs((stoi(C_.at(i)) - stoi(J_.at(j))));
		}
	}
	vector<string> cC, cJ;
	for (int i = 0; i < C_.size(); i++) {
		for (int j = 0; j < J_.size(); j++) {
			if (abs((stoi(C_.at(i)) - stoi(J_.at(j)))) == min) {
				C = C_.at(i);
				J = J_.at(j);
				return;
			}
		}
	}
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string C, J;
		cin >> C >> J;
		if (C == "?" && J == "?")
			C = J = "0";
		else if (C == "??" && J == "??")
			C = J = "00";
		else if (C == "???" && J == "???")
			C = J = "000";
		else {
			vector<string> C_ = reconstructString(C);
			vector<string> J_ = reconstructString(J);
			//for (int j = 0; j < C_.size(); j++)
			//	cout << C_.at(j) << endl;
			//for (int j = 0; j < J_.size(); j++)
			//	cout << J_.at(j) << endl;
			//cout << C_.size() << " " << J_.size() << endl;
			compareString(C_, J_, C, J);
		}
		cout << "Case #" << i + 1 << ": " << C << " " << J << endl;
	}
	return 0;
}