//2012-04-14T13:24:45
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[])
{
	int T;
	int A, B;
	stringstream ss;

	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int ans = 0;
		string bufstr;
		cin >> A >> B;
		for (int n = A; n <= B; n++) {
			set<int> appeared;
			ss << n;
			ss >> bufstr;
			//cout << "Check about " << n << endl;
			for (int i = 0; i < bufstr.length() - 1; i++) {
				int bufint;
				char bufchar = bufstr.at(bufstr.length() - 1);
				bufstr = bufstr.substr(0, bufstr.length() - 1);
				bufstr = bufchar + bufstr;
				if (bufchar == '0') {
					continue;
				}
				ss.clear();
				ss << bufstr;
				ss >> bufint;
				//cout << "\t How about " << bufint << endl;
				if (bufint > n && bufint <= B && appeared.find(bufint) == appeared.end()) {
					//cout << "\t\t" << bufint << " is ans." << endl;
					//cout << "(" << n << ", " << bufint << ")" << endl;
					++ans;
					appeared.insert(bufint);
				}
			}
			ss.clear();
		}
		cout << "Case #" << ii + 1 << ": " << ans << endl;
	}
	return 0;
}
