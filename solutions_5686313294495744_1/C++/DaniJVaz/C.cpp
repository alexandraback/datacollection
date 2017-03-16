#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

void recExplore(int start, vector<int> * edges1, vector<int> * edges2, bool* visited1, bool* visited2, int & count1, int & count2) {
	visited1[start] = true;
	count1 ++;

	for (int e1: edges1[start]) {
		if (visited2[e1])
			continue;

		visited2[e1] = true;
		count2 ++;

		for (int e2: edges2[e1]) {
			if (visited1[e2])
				continue;

			recExplore(e2, edges1, edges2, visited1, visited2, count1, count2);
		}
	}
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		vector<pair<int, int>> edges;
		unordered_map<string, int> words1, words2;
		int nextId1 = 0, nextId2 = 0;

		for (int i=0; i<N; i++) {
			char t1[25], t2[25];
			scanf("%s %s", t1, t2);

			if (words1.count(t1) == 0)
				words1[t1] = nextId1++;

			if (words2.count(t2) == 0)
				words2[t2] = nextId2++;

			edges.push_back({words1[t1], words2[t2]});
		}

		vector<int> edges1[nextId1], edges2[nextId2];

		for (auto e: edges) {
			edges1[e.first].push_back(e.second);
			edges2[e.second].push_back(e.first);
		}

		bool visited1[nextId1], visited2[nextId2];
		fill(visited1, visited1+nextId1, false);
		fill(visited2, visited2+nextId2, false);

		int count1, count2;

		int neededEdges = 0;

		for (int j=0; j<nextId1+nextId2; j++) {
			for (int i=0; i<nextId1; i++) {
				if (visited1[i])
					continue;

				int count = 0;
				for (auto e2: edges1[i])
					if (!visited2[e2])
						count++;

				if (count <= 1) {
					neededEdges++;
					visited1[i] = true;

					for (auto e2: edges1[i])
						visited2[e2] = true;
				}
			}

			for (int i=0; i<nextId2; i++) {
				if (visited2[i])
					continue;

				int count = 0;
				for (auto e1: edges2[i])
					if (!visited1[e1])
						count++;

				if (count <= 1) {
					neededEdges++;
					visited2[i] = true;

					for (auto e1: edges2[i])
						visited1[e1] = true;
				}
			}
		}

		for (int i=0; i<nextId1; i++) {
			if (visited1[i])
				continue;

			count1 = count2 = 0;
			recExplore(i, edges1, edges2, visited1, visited2, count1, count2);
			neededEdges += max(count1, count2);
		}

		printf("Case #%d: %d\n", iC, edges.size() - neededEdges);
	}
	return 0;
}