#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <list>

using namespace std;

int lastword(list<char> list, string word) {
	list.push_back(word[0]);
	for(int i = 1; i < word.size(); i++) {
		char first = list.front();
		if(word[i]>=first) {
			list.push_front(word[i]);
		} else {
			list.push_back(word[i]);
		}
	}
	for(std::list<char>::iterator it=list.begin(); it != list.end(); ++it) {
		cout << *it;
	}
	cout << endl;
}

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
		list<char> myList;
		cout << "Case #" << ct << ": ";
		lastword(myList,line);
		testNum--;
		ct++;
	}
	return 0;
}