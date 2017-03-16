#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<list>
using namespace::std;

int main()
{
	int test_case;

	cin >> test_case;
	for (int i = 1;i <= test_case;i++) {
		string s;
		cin >> s;
		list<char> board;
		board.push_front(s[0]);
		for (int j = 1;j < s.size();j++) {
			if (board.front() > s[j]) {
				board.push_back(s[j]);
			}
			else {
				board.push_front(s[j]);
			}
		}
		cout << "Case #" << i << ": ";
		while (!board.empty()) {
			cout << board.front();
			board.pop_front();
		}
		cout << endl;
	}
	return 0;
}
