#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int testAndInsert(map<string,int>& m, const string& s) {
	assert(s.size() >= 1 && s.size() <= 20);
	for (string::const_iterator it = s.begin(); it != s.end(); it++) {
		assert(isupper(*it));
	}
	map<string,int>::iterator it = m.find(s);
	if (it == m.end()) {
		int v = m.size();
		m.insert(make_pair(s, v));
		return v;
	}
	else {
		return it->second;
	}
}

vector<int> aBuren[1000], bBuren[1000];
int aVisited[1000];
int bMatch[1000];

int dfs(int node, int iteration) {
	if (aVisited[node] == iteration) return 0;
	aVisited[node] = iteration;
	for (vector<int>::iterator it = aBuren[node].begin(); it != aBuren[node].end(); it++) {
		if (bMatch[*it] == -1 || dfs(bMatch[*it], iteration)) {
			bMatch[*it] = node;
			return 1;
		}
	}
	return 0;
}

int solve() {
	int N;
	cin >> N;
	assert(N >= 1 && N <= 1000);
	map<string,int> aMap, bMap;
	for (int i = 0; i < N; i++) {
		string aStr, bStr;
		cin >> aStr >> bStr;
		int a = testAndInsert(aMap, aStr);
		int b = testAndInsert(bMap, bStr);
		assert(a >= 0 && a < (int) aMap.size());
		assert(b >= 0 && b < (int) bMap.size());
		aBuren[a].push_back(b);
		bBuren[b].push_back(a);
	}
	int numA = aMap.size();
	int numB = bMap.size();
	memset(aVisited, -1, sizeof aVisited);
	memset(bMatch, -1, sizeof bMatch);
	int numMatched = 0;
	for (int i = 0; i < numA; i++) {
		numMatched += dfs(i, i);
	}
	for (int i = 0; i < N; i++) {
		aBuren[i].clear();
		bBuren[i].clear();
	}
	assert(numMatched >= 0 && numMatched <= min(numA, numB));
	int ans = N + numMatched - numA - numB;
	assert(ans >= 0 && ans <= N);
	return ans;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
