#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
		string s;
		cin >> s;
		deque<char> work;
		
		for (char c : s) {
			if (work.empty()) {
				work.push_back(c);
			}
			else if (c >= work.front()) {
				work.push_front(c);
			}
			else {
				work.push_back(c);
			}
		}

		string lastword(work.begin(), work.end());

    printf("Case #%d: %s\n", t, lastword.c_str());
  }

}
