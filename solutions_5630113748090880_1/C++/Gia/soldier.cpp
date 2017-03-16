#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <list>

using namespace std;

// int lastword(list<char> list, string word) {
// 	list.push_back(word[0]);
// 	for(int i = 1; i < word.size(); i++) {
// 		char first = list.front();
// 		if(word[i]>=first) {
// 			list.push_front(word[i]);
// 		} else {
// 			list.push_back(word[i]);
// 		}
// 	}
// 	for(std::list<char>::iterator it=list.begin(); it != list.end(); ++it) {
// 		cout << *it;
// 	}
// 	cout << endl;
// }

int main() {
	string line;
	int testNum;
	getline(cin, line);
	stringstream ss(line);
	ss >> testNum;
	int ct = 1;
	while(testNum > 0) {
		int number;
		getline(cin, line);
		stringstream ss(line);
		ss >> number;
		int list_num = number*2-1;
		vector<int> vec(2501,0);
		for(int i = 0; i < list_num; i++) {
			getline(cin,line);
			stringstream ss1(line);
			int height;
			while(ss1>>height) {
				vec.at(height)++;
			}
		}
		vector<int> final;
		for(int j = 0; j < vec.size(); j++) {
			if(vec.at(j)!=0 && vec.at(j)%2!=0) {
				final.push_back(j);
			}
		}
		std::sort(final.begin(), final.end());
		cout << "Case #" << ct << ": ";
		for(int k = 0; k < final.size(); k++) {
			cout << final.at(k) << " ";
		}
		cout << endl;
		testNum--;
		ct++;
	}
	return 0;
}