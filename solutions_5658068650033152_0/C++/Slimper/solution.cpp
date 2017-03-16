#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
	cout << "Case #" << caseNumber << ": " << ans << endl;
}

vector< vector<int> > graph;

int DFS(int v, vector<bool>& vis, const vector<bool>& isGrid) {
    vis[v] = true;
    int ans = 1;
    if (isGrid[v]) {
        ans = 0;
    }
    for (const int& next : graph[v]) {
        if (!vis[next]) {
            int cur = DFS(next, vis, isGrid);
            if (ans > 0) {
                if (cur == 0) {
                    ans = 0;
                }
                else {
                    ans += cur;
                }
            }
        }
       
    }
    return ans;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    int v = n * m;
    int len = 1 << v;

    vector<bool> isEdge(v, false);
    vector<bool> isStone(v, false);

    for (int i = 0; i < n; i++) {
        isEdge[i * m] = true;
        isEdge[i * m + m - 1] = true;
    }

    for (int i = 0; i < m; i++) {
        isEdge[i] = true;
        isEdge[m * (n - 1) + i] = true;
    }

    graph.resize(v);
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = m * i + j;
            for (int d = 0; d < 4; d++) {
                int newY = i + dy[d];
                int newX = j + dx[d];
                if (newY >= 0 && newY < n && newX >= 0 && newX < m) {
                    graph[t].push_back(m * newY + newX);
                }
            }
        }
    }


    int ans = k;
    for (int i = 1; i < len; i++) {
        int stones = 0;
        for (int j = 0; j < v; j++) {
            if (i & (1 << j)) {
                isStone[j] = true;
                stones++;
            }
            else {
                isStone[j] = false;
            }
        }
        int enclosed = stones;
        vector<bool> vis = isStone;
        for (int j = 0; j < v; j++) {
            if (!vis[j] && !isEdge[j]) {
                enclosed += DFS(j, vis, isEdge);
            }
        }
        if (enclosed >= k) {
            ans = min(ans, stones);
        }
    }
	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("C-small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase<int>() );

	return 0;
}