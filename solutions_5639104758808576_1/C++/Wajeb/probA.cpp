#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ifstream cin("probAlarge.in");
	ofstream cout("probAlarge.txt");

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n;
		string s;
		vector<int> v;
		cin >> n >> s;
		for(int i = 0; i < n + 1; i++) v.push_back(s[i] - '0');

		int counter = 0, friends = 0;
		for(int req = 0; req < n + 1; req++)
		{
			int diff = max(req - counter, 0);
			friends += diff;
			counter += diff + v[req];
		}

		cout << "Case #" << t + 1 << ": " << friends << endl;
	}

	return 0;
}
