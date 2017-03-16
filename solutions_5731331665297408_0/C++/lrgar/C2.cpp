// ================================================================================================
//  Written by Luis Garcia, 2014
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ14_03C2, "GCJ14 03C2")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

string test(
	vector<bool> & visited, const vector<int> & stack, const vector<pair<int, int>> & routes, const vector<string> & zipCodes
	) {
		if (count(visited.begin(), visited.end(), false) == false)
			return "";

		string ret = "Z";
		for (int i = 0; i < stack.size(); ++i) {
			for (int j = 0; j < routes.size(); ++j)
				if (routes[j].first == stack[i] && !visited[routes[j].second]) {
					vector<int> newStack(stack.begin(), stack.begin() + i + 1);
					newStack.push_back(routes[j].second);

					visited[routes[j].second] = true;
					string nt = test(visited, newStack, routes, zipCodes);
					if (nt != "Z")
						ret = min(ret, zipCodes[routes[j].second] + nt);
					visited[routes[j].second] = false;
				}
		}
		return ret;
	}

int main(
	) {
		int T, N, M;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> N >> M;
			
			vector<string> zipCodes(N);
			vector<pair<int, int>> routes;

			for (int i = 0; i < N; ++i) cin >> zipCodes[i];
			for (int j = 0; j < M; ++j) {
				int a, b;
				cin >> a >> b;
				routes.push_back(make_pair(a - 1, b - 1));
				routes.push_back(make_pair(b - 1, a - 1));
			}

			string answer = "Z";

			for (int i = 0; i < N; ++i) {
				vector<bool> visited(N);
				visited[i] = true;

				string s = test(visited, vector<int>{i}, routes, zipCodes);
				if (s != "Z")
					answer = min(answer, zipCodes[i] + s);
			}

			cout << "Case #" << _T << ": " << answer << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
