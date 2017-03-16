#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int solve()
{
	vector< pair<string, string> > topics;
	map<string, int> w1;
	map<string, int> w2;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		topics.push_back(make_pair(s1, s2));
		++w1[s1];
		++w2[s2];
	}

	int sol = 0;

	for(const auto& p : topics) {
		if(w1[p.first] > 1 && w2[p.second] > 1) {
			++sol;
		}
	}

	return sol;
}

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}
