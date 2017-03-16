#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int arrange(int nChildren, vector<vector<int> > friends, int initFriend, vector<int> circle) {

	int maxCount = circle.size();

	if (find(circle.begin(), circle.end(), initFriend) == circle.end()) {
		circle.push_back(initFriend);

		for (int ff = 0; ff < friends.at(initFriend).size(); ++ff) {
			vector<int> cClone(circle);
			int count = arrange(nChildren, friends, friends.at(initFriend).at(ff), cClone);
			maxCount = count > maxCount ? count : maxCount;
		}
	}

	return maxCount;
}

int main(int argc, char const *argv[]) {
	int nTestCases;
	cin >> nTestCases;

	for (int i = 0; i < nTestCases; ++i) {
		int nChildren;
		cin >> nChildren;

		vector<vector<int> > friends;
		for (int f = 0; f < nChildren; ++f) {
			friends.push_back(vector<int>());
		}


		for (int f = 0; f < nChildren; ++f) {
			int fid;
			cin >> fid;
			fid -= 1;
			friends.at(fid).push_back(f);
			friends.at(f).push_back(fid);
		}

		for (int f = 0; f < nChildren; ++f) {
			set<int> fSet(friends.at(f).begin(), friends.at(f).end());
			friends.at(f).assign(fSet.begin(), fSet.end());
		}

		int maxCount = 0;
		for (int f = 0; f < nChildren; ++f) {
			int count = arrange(nChildren, friends, f, vector<int>());
			maxCount = count > maxCount ? count : maxCount;
		}

		cout << "Case #" << i+1 << ": " << maxCount << endl;	
	}

	return 0;
}