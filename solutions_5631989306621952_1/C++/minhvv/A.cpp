//A.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		string s;
		cin >> s;

		deque<char> q;
		q.push_front(s[0]);

		for (int i = 1; i < s.length(); ++i)
		{
			char c = s[i];
			if (c >= q[0]) {
				q.push_front(c);
			} else {
				q.push_back(c);
			}
		}

		cout << "Case #" << t+1 << ": ";
		for (deque<char>::iterator it = q.begin(); it != q.end(); ++it)
    		cout << *it;
    	cout << endl;
	}
	return 0;
}
