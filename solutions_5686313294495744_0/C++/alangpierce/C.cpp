#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/Round1B/C-small-attempt1";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

string next_string() {
    char result[1000];
    fscanf(infile, "%s", result);
    return string(result);
}

int next_int() {
    int result = 0;
    fscanf(infile, "%d", &result);
    return result;
}

vector<int> next_int_vector(int n) {
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++) {
        result[i] = next_int();
    }
    return result;
}

vector<set<int>> graph;
vector<pair<int, int>> edges;
int num_left;
int num_right;

int source = 0;
int sink = 1;
int left_node(int n) {
    return 2 + n;
}
int right_node(int n) {
    return 2 + num_left + n;
}

// returns true if successful
bool push_flow() {
    queue<int> q;
    q.push(source);

    map<int, int> preds;
    preds[source] = -1;

    while (q.size()) {
        int node = q.front();
        q.pop();
        if (node == sink) {
            for (int n = sink; n != source; n = preds[n]) {
                int v1 = preds[n];
                int v2 = n;
                graph[v1].erase(v2);
                graph[v2].insert(v1);
            }
            return true;
        }

        for (int neighbor : graph[node]) {
            if (!preds.count(neighbor)) {
                preds[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int calculate_max_flow() {
    graph.clear();
    graph.resize(num_left + num_right + 2);
    for (int i = 0; i < num_left; i++) {
        graph[source].insert(left_node(i));
    }
    for (int i = 0; i < num_right; i++) {
        graph[right_node(i)].insert(sink);
    }
    for (int i = 0; i < edges.size(); i++) {
        graph[left_node(edges[i].first)].insert(right_node(edges[i].second));
    }

    int flow = 0;
    while (push_flow()) {
        flow++;
    }
    return flow;
}

string handle_case() {
    int n = next_int();
    map<string, int> left_indexes;
    map<string, int> right_indexes;

    vector<pair<int, int>> input_edges;
    for (int i = 0; i < n; i++) {
        string s1 = next_string();
        int left_index;
        if (left_indexes.count(s1)) {
            left_index = left_indexes[s1];
        } else {
            left_index = (int)left_indexes.size();
            left_indexes[s1] = left_index;
        }

        string s2 = next_string();
        int right_index;
        if (right_indexes.count(s2)) {
            right_index = right_indexes[s2];
        } else {
            right_index = (int)right_indexes.size();
            right_indexes[s2] = right_index;
        }
        input_edges.push_back(make_pair(left_index, right_index));
    }

    edges = input_edges;
    num_left = (int) left_indexes.size();
    num_right = (int) right_indexes.size();

    int max_flow = calculate_max_flow();

    int num_vertices = (int)left_indexes.size() + (int)right_indexes.size();
    int result = n - num_vertices + max_flow;

    stringstream ss;
    ss << result;
    return ss.str();
}

int main() {
    string infilename = problem + ".in";
    string outfilename = problem + ".out";
    infile = fopen(infilename.c_str(), "r");
    if (infile == nullptr) {
        printf("File %s not found!", infilename.c_str());
        return 1;
    }
    outfile = fopen(outfilename.c_str(), "w");

    lld n_cases = next_lld();
    for (lld case_num = 1; case_num <= n_cases; ++case_num) {
        string result = handle_case();
        printf("Case #%lld: %s\n", case_num, result.c_str());
        fprintf(outfile, "Case #%lld: %s\n", case_num, result.c_str());
    }
    return 0;
}