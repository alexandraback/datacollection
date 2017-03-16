#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;
FILE* in; FILE* out;

// Dinitz Algorithm

const int MAX_NODES = 2004;
const int MAX_EDGES = 16384;
const int INF = 1000000001;

struct Edge {
	int next, to, cap;
	Edge(int next_ = 0, int to_ = 0, int cap_ = 0) :
	    next(next_), to(to_), cap(cap_) {}
};

int source, sink;
Edge edges[MAX_EDGES]; int numEdges;
int vis[MAX_NODES], dist[MAX_NODES], first[MAX_NODES];

int recurse(int node, int flow) {
	if (node == sink) return flow;
	for (int idx = first[node]; idx != -1; idx = edges[idx].next) {
		if (!vis[edges[idx].to] && edges[idx].cap > 0 && dist[node] == dist[edges[idx].to] + 1) {
			int ret = recurse(edges[idx].to, min(flow, edges[idx].cap));
			if (ret) {edges[idx].cap -= ret; edges[idx ^ 1].cap += ret; return ret;}
		}
	}
	vis[node] = 1;
	return 0;
}

int dinitz(int source_, int sink_) {
	source = source_; sink = sink_;
	
	int flow = 0;
	while (true) {
		// BFS
		int cur = 0;
		queue <int> q;

		for (int i=0; i<MAX_NODES; i++) dist[i] = MAX_NODES;
		q.push(sink); dist[sink] = 0;
		
		while (!q.empty()) {
			cur = q.front(); q.pop();
			for (int idx = first[cur]; idx != -1; idx = edges[idx].next) {
				if (edges[idx ^ 1].cap > 0 && dist[edges[idx].to] == MAX_NODES) {
					dist[edges[idx].to] = dist[cur] + 1;
					q.push(edges[idx].to);
					if (edges[idx].to == source) {cur = source; break;}
				}
			}
			if (cur == source) break;
		}
		if (cur != source) break;
		
		// DFS
		int flag = 0;
		memset(vis, 0, sizeof(vis));
		while (true) {
			int add = recurse(source, INF);
			if (add == 0) break;
			flow += add; flag = 1;
		}
		if (!flag) break;
	}
	return flow;
}

inline void addEdge(int from, int to, int cap) {
	if (!numEdges) memset(first, -1, sizeof(first));
	edges[numEdges].to = to; edges[numEdges].cap = cap;
	edges[numEdges].next = first[from]; first[from] = numEdges++;
	
	edges[numEdges].to = from; edges[numEdges].cap = 0;
	edges[numEdges].next = first[to]; first[to] = numEdges++;
}

// End of Dinitz Algorithm


const int MAX = 1024;

int n;
string a[MAX][2];

int findWord(const vector <string>& words, const string& word) {
    int left = 0, right = (int)words.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (words[mid] == word)
            return mid;
        words[mid] < word ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

int eval() {
    vector <string> word1, word2;
    for (int i = 0; i < n; i++) {
        word1.push_back(a[i][0]);
        word2.push_back(a[i][1]);
    }
    sort(word1.begin(), word1.end());
    word1.resize(unique(word1.begin(), word1.end()) - word1.begin());
    sort(word2.begin(), word2.end());
    word2.resize(unique(word2.begin(), word2.end()) - word2.begin());
    
    numEdges = 0;
    int src = 2 * n, snk = 2 * n + 1;
    for (int i = 0; i < n; i++) {
        int node1 = findWord(word1, a[i][0]) + 0;
        int node2 = findWord(word2, a[i][1]) + n;
        addEdge(node1, node2, 1);
    }
    
    map <string, int> cnt1, cnt2;
    for (int i = 0; i < n; i++) {
        cnt1[a[i][0]]++;
        cnt2[a[i][1]]++;
    }
    
    int skipped = 0;
    set <string> taken1, taken2;
    for (int i = 0; i < n; i++) {
        if (cnt1[a[i][0]] == 1 || cnt2[a[i][1]] == 1) {
            skipped++;
            taken1.insert(a[i][0]);
            taken2.insert(a[i][1]);
        }
    }
    
    for (int i = 0; i < (int)word1.size(); i++)
        if (taken1.find(word1[i]) == taken1.end())
            addEdge(src, i + 0, 1);
    for (int i = 0; i < (int)word2.size(); i++)
        if (taken2.find(word2[i]) == taken2.end())
            addEdge(i + n, snk, 1);
    int flow = dinitz(src, snk);
    
    int leftUnfinished = 0, rightUnfinished = 0;
    for (int idx = first[src]; idx != -1; idx = edges[idx].next)
        if (edges[idx].cap == 1) leftUnfinished++;
    for (int idx = first[snk]; idx != -1; idx = edges[idx].next)
        if (edges[idx].cap == 0) rightUnfinished++;
    
    int ans = n - skipped - leftUnfinished - rightUnfinished - flow;
    return ans;
}

void solveTest() {
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        char word1[32], word2[32];
        fscanf(in, "%s %s", word1, word2);
        a[i][0] = word1, a[i][1] = word2;
    }
    fprintf(out, "%d\n", eval());
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("Technobabble.in", "rt");
	out = fopen("Technobabble.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solveTest();
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
