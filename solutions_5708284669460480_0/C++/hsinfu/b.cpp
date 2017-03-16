#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

int getRepeatNum(string t) {
	int num = 0;
	for(int i = 1, j = 0; i < t.size(); ++i) {
		if(t.at(i) == t.at(j)) {
			num++;
			j++;
		} else {
			num = 0;
			j = 0;
		}
	}
	return num;
}

int getMinNum(string keyboard, string target, int S) {
	for(int i = 0; i < target.size(); ++i) 
		if(keyboard.find(target.at(i)) == string::npos)
			return 0;
	int repeatNum = getRepeatNum(target);
	int minNum = 1 + (S - target.size()) / (target.size() - repeatNum);
	return minNum;
}

void fillKeyprob(string& keyboard, map<char, float>& keyprob) {
	for(int i = 0; i < keyboard.size(); ++i) {
		map<char,float>::iterator it = keyprob.find(keyboard.at(i));
		if (it == keyprob.end()) {
			keyprob.insert( make_pair( keyboard.at(i), 1.0/keyboard.size() ) );
		} else {
			it->second += 1.0/keyboard.size();
		}
	}
}

float getTargetProb(map<char, float>& keyprob, string target) {
	float prob = 1.0;
	for(int i = 0; i < target.size(); ++i) 
		prob *= keyprob.find(target.at(i))->second;
	return prob;
}

float getTargetFrontProb(map<char, float>& keyprob, string target) {
	int repeatNum = getRepeatNum(target);
	float prob = 1.0;
	for(int i = 0; i < target.size() - repeatNum; ++i) 
		prob *= keyprob.find(target.at(i))->second;
	return prob;
}

float getExpectedNum(map<char, float>& keyprob, float firstCharProb, float targetProb, float targetFrontProb, int lenTarget, int lenTargetFront, int remainS) {
	if(lenTarget > remainS) return 0.0;
	float expectedNum = targetProb;
	float prob = targetProb;
	for(int i = 0; i < (remainS-lenTarget)/lenTargetFront; ++i) {
		expectedNum += prob * targetFrontProb;
		prob *= targetFrontProb;
	}
	return expectedNum + (1.0 - firstCharProb) * getExpectedNum(keyprob, firstCharProb, targetProb, targetFrontProb, lenTarget, lenTargetFront, remainS-1);
}

int main(int argc, char* argv[]) {
	int T, K, L, S;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		string keyboard, target;
		map<char, float> keyprob;
		cin >> K >> L >> S;
		cin >> keyboard >> target;
		int minNum = getMinNum(keyboard, target, S);
		if (minNum == 0) cout << "Case #" << t+1 << ": 0" << endl;
		else {
			fillKeyprob(keyboard, keyprob);
			float targetProb = getTargetProb(keyprob, target);
			float targetFrontProb = getTargetFrontProb(keyprob, target);
			int lenTarget = target.size();
			int lenTargetFront = target.size() - getRepeatNum(target);
			float firstCharProb = keyprob.find(target.at(0))->second;
			float expectedNum = getExpectedNum(keyprob, firstCharProb, targetProb, targetFrontProb, lenTarget, lenTargetFront, S);
			cout << "Case #" << t+1 << ": " << (float)minNum - expectedNum  << endl;
		}
	}
	return 0;
}

