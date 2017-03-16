#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int letterCount[26];
		memset(letterCount, 0, sizeof(letterCount));
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			letterCount[str[i] - 'A']++;
		}
		string words[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

		vector<int> digits(10, 0);

		vector<pair<char, int> > musts;
		musts.push_back(make_pair('Z', 0));
		musts.push_back(make_pair('G', 8));
		musts.push_back(make_pair('W', 2));
		musts.push_back(make_pair('H', 3));
		musts.push_back(make_pair('U', 4));
		musts.push_back(make_pair('O', 1));
		musts.push_back(make_pair('F', 5));
		musts.push_back(make_pair('X', 6));
		musts.push_back(make_pair('S', 7));
		musts.push_back(make_pair('I', 9));

		for (int i = 0; i < musts.size(); i++) {
			int cnt1 = letterCount[musts[i].first - 'A'];
			digits[musts[i].second] = cnt1;
			for (int j = 0; j < words[musts[i].second].size(); j++) {
				letterCount[words[musts[i].second][j] - 'A'] -= cnt1;
			}
		}
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j < digits[i]; j++)
				cout << i;

		cout << endl;
	}
	return 0;
}
