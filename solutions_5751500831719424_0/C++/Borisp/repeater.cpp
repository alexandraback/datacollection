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
string simplify(string str) {
	string res;
	res.push_back(str[0]);
	for(int i = 0; i < str.size(); i++)
		if (str[i] != res[res.size() - 1])
			res.push_back(str[i]);

	return res;
}

int solve(const vector<int> & groups)
{
	int minm = 1000000000;
	for (int i = 0; i < 128; i++)
	{
		int num = 0;
		for (int j = 0; j < groups.size(); j++)
		{
			num += abs(groups[j] - i);
		}
		minm = min(minm, num);
	}
	return minm;
}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
    for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n;
		cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		string tmp = simplify(v[0]);
		bool working = true;
		for (int i = 1; i < n; i++) {
			string simplified = simplify(v[i]);
			if (simplified != tmp) {
				cout << "Fegla Won" << endl;
				working = false;
				break;
			}
		}
		if (!working)
			continue;

		vector<int> indexes(n, 0);
		
		int res = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			vector<int> groups(n);
			for (int j = 0; j < n; j++)
			{
				int cnt = 0;
				while (indexes[j] < v[j].size() && v[j][indexes[j]] == tmp[i]) {
					indexes[j]++;
					cnt++;
				}
				groups[j] = cnt;

			}
			res += solve(groups);
		}

		cout << res << endl;

		
			 
	}
	return 0;
}
