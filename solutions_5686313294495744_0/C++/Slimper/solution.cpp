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
#include <unordered_map>

using namespace std;


class MaximumFlow {
    vector< vector<int> > capacity;

    vector< vector<int> > resCapacity;
    vector< vector<int> > flow;

    int maxFlow;

    int n;

    int flowCost;

    long long EstimateMaxFlow() {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                ans += capacity[i][j];
        }
        return 2 * ans;
    }


    void FordFulkerson(int source, int sink) {
        if (source < 0 && source > n - 1) cerr << "Wrong source";
        if (sink < 0 && sink > n - 1) cerr << "Wrong sink";

        resCapacity = capacity;
        flowCost = 0;


        bool flag = true;
        vector<int> q(n, -1);
        //vector< pair<int, int> > path(n);

        while (flag) {
            int l = -1;
            int r = 0;
            q[0] = source;

            vector <int> prev(n, -1);
            bool sinkFound = false;
            while (l < r) {
                l++;
                int curVertex = q[l];
                for (int i = 0; i < n; i++)
                if ((prev[i] == -1) && (resCapacity[curVertex][i] > 0)) {
                    r++;
                    if (r >= q.size()) {
                        q.resize(r + 1);
                    }
                    q[r] = i;

                    prev[i] = curVertex;
                    if (i == sink) {
                        sinkFound = true;
                        break;
                    }
                }

                if (sinkFound) break;
            }

            if (!sinkFound) break;

            int cur = sink;
            int pathFlow = maxFlow;
            do {
                pathFlow = min(pathFlow, resCapacity[prev[cur]][cur]);
                cur = prev[cur];
            } while (cur != source);

            cur = sink;
            do {

                flow[prev[cur]][cur] += pathFlow;
                flow[cur][prev[cur]] = -flow[prev[cur]][cur];
                resCapacity[prev[cur]][cur] = capacity[prev[cur]][cur] - flow[prev[cur]][cur];
                resCapacity[cur][prev[cur]] = capacity[cur][prev[cur]] - flow[cur][prev[cur]];
                cur = prev[cur];
            } while (cur != source);

            flowCost += pathFlow;
        }

    }

    void Make(int source, int sink) {
        FordFulkerson(source, sink);


    }

public:

    MaximumFlow(vector < vector<int> > cap) {

        capacity = cap;
        n = capacity.size();
        flow = vector< vector< int> >(n, vector<int>(n, 0));
        //Sometimes better to determine maxflow manually 
        maxFlow = EstimateMaxFlow();
        //cout << maxFlow << endl;
    }

    int FindMaxFlowCost(int source, int sink) {
        Make(source, sink);
        return flowCost;
    }

    vector< vector<int> > FindMaxFlow(int source, int sink) {
        Make(source, sink);
        return flow;
    }

};



vector < pair<int, int> > FindMatching(vector< vector<bool> > g) {
    int n = g.size();
    int m = g[0].size();

    vector< vector<int> > graph = vector< vector<int> >(m + n + 2, vector<int>(n + m + 2, 0));

    for (int i = 1; i <= n; i++) {
        graph[0][i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        graph[n + i][n + m + 1] = 1;
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (g[i][j])
        graph[i + 1][n + j + 1] = 1;

    MaximumFlow f(graph);
    vector< vector<int> > flow = f.FindMaxFlow(0, m + n + 1);

    vector< pair<int, int> > matching;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (flow[i + 1][n + j + 1] == 1)
        matching.push_back(make_pair(i, j));

    return matching;
}


template <class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
	cout << "Case #" << caseNumber << ": " << ans << endl;
}


map<string, int> CreateIds(const vector<string>& words) {
    map<string, int> id;
    int curId = 0;
    for (auto& w : words) {
        if (id.find(w) == id.end()) {
            id[w] = curId;
            curId++;
        }
    }
    return id;
}


int SolveTestCase() {
    int n;
    cin >> n;
    vector<string> first(n);
    vector<string> second(n);

    for (int i = 0; i < n; i++) {
        cin >> first[i] >> second[i];
    }

    map<string, int> firstToId = CreateIds(first);
    map<string, int> secondToId = CreateIds(second);

    vector< vector<bool> > graph(firstToId.size(), vector<bool>(secondToId.size(), false));
    for (int i = 0; i < n; i++) {
        graph[firstToId[first[i]]][secondToId[second[i]]] = true;
    }
    auto matching = FindMatching(graph);
    return n - firstToId.size() - secondToId.size() + matching.size();
}

int main()
{
	//freopen("input.txt", "r", stdin);
    freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}