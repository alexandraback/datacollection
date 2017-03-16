#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <functional>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}


vector<vector<int> > graph;

int BBF[1010];
int rBBF[1010];

bool IsInBinCircle(int i)
{
    return BBF[BBF[i]] == i;
}

int longest_child(int fa)
{
    int len = 1;
    for (int i = 0; i < graph[fa].size(); i++){
        if (BBF[fa] == graph[fa][i] ) continue;
        len = max(longest_child(graph[fa][i]) + 1, len);
    }
    return len;
}

bool visited[2000];
int depth[2000];

int dfs_cicle(int x, int d)
{
    visited[x] = true;
    int bbf = BBF[x];
    depth[x] = d;
    if (visited[bbf]){
        return d - depth[bbf] + 1;
    }else{
        return dfs_cicle(bbf, d+1);
    }
}

int find_max_cicle(int n){
    fill(visited, visited + n, false);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (graph[i].size() != 0){
            ans = max(ans, dfs_cicle(i, 0));
        }
    }
    return ans;
}

int main() {
    use_file("C2");
    int T, N;
    cin >> T;

    for(int ca = 1; ca <= T; ca++){
        cin >> N;
        graph.clear();
        graph.resize(N);
        for (int i = 0; i < N; i++){
            cin >> BBF[i];
            BBF[i]--;
            graph[BBF[i]].push_back(i);
        }

        int c2 = 0;
        for (int i = 0; i < N; i++){
            if (IsInBinCircle(i)){
                c2 += longest_child(i);
            }
        }
        int c3 = find_max_cicle(N);
        //cout <<"debug: " <<  c2 << " " << c3 << endl;

        cout << "Case #" << ca << ": " << max(c2, c3);
        cout << endl;
    }
	return 0;
}
