#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<functional>
#include <fstream>
#include <iomanip>
#define ii pair<int,int>
#define INF 1000000000
using namespace std;
map <char, int> mp;

bool emptyMap() {
	int cnt = 0;
	for (std::map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		if (it->second == 0)
			cnt++;
	return cnt == mp.size();
}
int main()
{
	freopen("outputSmall.txt", "w", stdout);
	string ans[] = { "ZERO","TWO", "FOUR", "SIX", "EIGHT", "FIVE", "NINE", "THREE" ,"ONE", "SEVEN" };
	int a[] = { 0,2,4,6,8,5,9,3,1,7 };
	int n;
	cin >> n;
	for (int l = 0; l < n; l++) {
		string s;
		vector <int> answer;
		cin >> s;
		cout << "Case #" << l + 1 << ": ";
		for (int i = 0; i < s.size(); i++)
			mp[s[i]]++;
		for (int i = 0; i < 10; i++) {
				int cnt = 0;
				int min = INF;
				for (int j = 0; j < ans[i].size(); j++) {
					if (mp[ans[i][j]] > 0) {
						if (ans[i] == "THREE" || ans[i] == "SEVEN") {
							if (ans[i][j] == 'E') {
								if (mp[ans[i][j]] > 1) {
									cnt++;
								}
							}
							else
								cnt++;
						}
						else if (ans[i] == "NINE") {
							if (ans[i][j] == 'N') {
								if (mp[ans[i][j]] > 1)
									cnt++;
							}
							else
								cnt++;
						}
						else
							cnt++;
					}
					if (mp[ans[i][j]] < min)
						min = mp[ans[i][j]];
				}
				if (cnt == ans[i].size()) {
					for (int j = 0; j < ans[i].size(); j++) {
						mp[ans[i][j]] -= min;
					}
					for (int ix = 0; ix < min;ix++)
						answer.push_back(a[i]);
				}
			}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i];
		cout << endl;
		mp.clear();
	}
	return 0;
}
