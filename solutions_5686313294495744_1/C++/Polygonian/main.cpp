#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;

const int Unmatched = -1;
enum { MAX = 2048 };

vector<int> edges[MAX];
int matching[MAX];
bool visited[MAX];

bool augmentPath(int index) {
	visited[index] = true;
	for (int i = 0; i < edges[index].size(); i++) {
		int neighbour = edges[index][i];
		if (visited[neighbour]) continue;
		if (matching[neighbour] == Unmatched) {
			matching[index] = neighbour;
			matching[neighbour] = index;
			return true;
		} else if (matching[neighbour] != index) {
			visited[neighbour] = true;
			if (augmentPath(matching[neighbour])) {
				matching[index] = neighbour;
				matching[neighbour] = index;
				return true;
			}
		}
	}
	return false;
}

void solve(int CASE, const vector<pair<int, int> > &actual,
	const int aaCount, const int bbCount, const int edgeCount, int dupCount) {
	
	const int allCount = aaCount + bbCount;
	for (int i = 0; i < allCount; i++) {
		matching[i] = Unmatched;
		edges[i].clear();
	}
	for (int i = 0; i < edgeCount; i++) {
		int fromId = actual[i].first;
		int toId = actual[i].second + aaCount;
		edges[fromId].push_back(toId);
		edges[toId].push_back(fromId);
	}

	int matchingCount = 0;
	for (int i = 0; i < aaCount; i++) {
		if (matching[i] == Unmatched) {
			for (int j = 0; j < allCount; j++) {
				visited[j] = false;
			}
			if (augmentPath(i))
				matchingCount++;
		}
	}

	// printf("matchingCount = %d\n", matchingCount);
	int mismatchCount = 0;
	for (int i = 0; i < allCount; i++) {
		if (matching[i] != Unmatched) {
			int fromId = i;
			int toId = matching[i];
			if (fromId > toId) {
				int temp = fromId; fromId = toId; toId = temp;
			}
			int from = fromId;
			int to = toId - aaCount;
			// printf("  %d (%d) --> %d (%d)\n", from, fromId, to, toId);
		} else {
			mismatchCount++;
		}
	}

	int realCount = matchingCount + mismatchCount;
	int fakeCount = edgeCount - realCount;
	int fakePlusDupCount = fakeCount + dupCount;

	cout << "Case #" << CASE << ": " << fakePlusDupCount << endl;
}

int main(int argc, const char * argv[]) {

	istream &fin = cin;
//	fstream fin("tiny.in");

// #if __CMD__
// 	istream &fin = cin;
// #else
// 	fstream fin("tiny.in");
// #endif

	int T;
	fin >> T;
	string W;
	for (int c = 1; c <= T; c++) {
		int N;
		fin >> N;
		vector<string> aa, bb;
		vector<pair<string, string> > aabb;
		for (int i = 0; i < N; i++) {
			string a, b;
			fin >> a;
			fin >> b;
			aa.push_back(a);
			bb.push_back(b);
			aabb.push_back(make_pair(a, b));
		}
		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		unordered_map<string, int> aam;
		int aaCount = 0;
		for (int i = 0; i < N; i++) {
			if (aam.find(aa[i]) == aam.end()) {
				aam[aa[i]] = aaCount++;
			}
		}
		unordered_map<string, int> bbm;
		int bbCount = 0;
		for (int i = 0; i < N; i++) {
			if (bbm.find(bb[i]) == bbm.end()) {
				bbm[bb[i]] = bbCount++;
			}
		}
		vector<pair<int, int> > actualDup;
		vector<pair<int, int> > actual;
		for (int i = 0; i < N; i++) {
			const string &a = aabb[i].first;
			const string &b = aabb[i].second;
			// cout << "map: " << aam[a] << " -- " << bbm[b] << endl;
			actualDup.push_back(make_pair(aam[a], bbm[b]));
		}
		sort(actualDup.begin(), actualDup.end());
		for (int i = 0; i < N; i++) {
			if (i == 0 || actualDup[i] != actualDup[i - 1]) {
				actual.push_back(actualDup[i]);
			}
		}
		solve(c, actual, aaCount, bbCount, actual.size(),
			actualDup.size() - actual.size());
	}
    return 0;
}
