#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<int> zips;
vector<pair<int, int> > edges;
vector<int> selected;
int root;

vector<int> visited;

void print(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void dfs(int r, vector<int> &result) {
    if (visited[r]) return;

    visited[r] = 1;
    result.push_back(r);

    vector<pair<int, int> > childs;
    for (int i = 0; i < edges.size(); ++i) {
        if (!selected[i]) {
            continue;
        }
        int c;
        if (edges[i].first == r) c = edges[i].second;
        else if (edges[i].second == r) c = edges[i].first;
        else continue;

        if (!visited[c]) {
            childs.push_back(make_pair(zips[c],c));
        }
    }

    sort(childs.begin(), childs.end());
    for (int i = 0; i < childs.size(); ++i) {
        dfs(childs[i].second, result);
    }
}

string calc() {
    int N, M;
    cin >> N >> M;

    zips.clear();
    zips.resize(N);
    root = 0;
    for (int i = 0; i < N; ++i) {
        cin >> zips[i];
        if (zips[i] < zips[root]) root = i;
    }

    edges.clear();
    edges.resize(M);

    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first;
        --edges[i].second;
        if (edges[i].first > edges[i].second) {
            swap(edges[i].first, edges[i].second);
        }
    }

    selected.clear();
    selected.resize(M);
    for (int i = 1; i <= N - 1; ++i) {
        selected[M - i] = 1;
    }

    vector<int> ans;
    do {
        visited.clear();
        visited.resize(N, 0);
        vector<int> res;
        dfs(root, res);
        if (res.size() == N) {
            /*
            print(selected);
            print(res);
            cout << endl;
            */
            if (ans.empty()) {
                ans = res;
                continue;
            }

            bool ok = false;
            for (int i = 0; i < N; ++i) {
                if (zips[res[i]] == zips[ans[i]]) continue;
                ok = (zips[res[i]] < zips[ans[i]]);
                break;
            }

            if (ok) {
                ans = res;
            }
        }
    } while (next_permutation(selected.begin(), selected.end()));

    //print(ans);

    stringstream ss;
    for (int i = 0; i < N; ++i) {
        ss << zips[ans[i]];
    }
    return ss.str();
}

int main(void)
{
	int T;
	cin >> T;

	for (int ca=1; ca<=T; ++ca) {
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
