#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str[100];
int n;
const long long MOD = 1000000007;

int main(void)
{
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> str[i];

		vector <int> inds;
		for(int i = 0; i < n; i++) inds.push_back(i);
		int ans = 0;
		do
		{
			bool isValid = true;
			string concated;
			for(auto ind: inds) concated += str[ind];
			concated.erase(unique(concated.begin(), concated.end()), concated.end());
			bool isVisited[26] = {false, };
			for(char ch: concated)
			{
				ch -= 'a';
				if(isVisited[ch] == false) isVisited[ch] = true;
				else { isValid = false; break; }
			}

			ans += isValid;
		} while(next_permutation(inds.begin(), inds.end()));

		printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}

