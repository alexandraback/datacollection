#include <iostream>
#include <vector>
using namespace std;
void solve(int case_no);

void dfs(int cur_length, vector<int> &cur, int &answer, vector<bool>& visited, size_t n, const vector<int> &bff);


int main(void) {
    int T;
    cin >> T;
    for (int case_no = 1; case_no <= T; case_no++) {
        solve(case_no);
    }
}

void solve(int case_no) {
    size_t n;
    cin >> n;
    vector<int> bff(n);
    for (int i = 0; i < n; i++) {
        cin >> bff[i];
        --bff[i];
    }
    int answer = 0;
    vector<int> cur(n);
    vector<bool> visited(n);
    dfs(0, cur, answer, visited, n, bff);
    cout << "Case #" << case_no << ": " << answer << endl;
}

void dfs(int cur_length, vector<int> &cur, int &answer, vector<bool>& visited, size_t n, const vector<int> &bff) {
    if (cur_length >= 3) {
        if ((bff[cur[0]] == cur[1] || bff[cur[0]] == cur[cur_length - 1]) &&
                    (bff[cur[cur_length - 1]] == cur[0] || bff[cur[cur_length - 1]] == cur[cur_length - 2])) {
            // for (int i = 0; i < cur_length; i++) cout << cur[i] << ' '; cout << endl;
            answer = max(answer, cur_length);
        }
    }
    if (cur_length == n) {
        return;
    }
    for (int next = 0; next < n; next++) {
        if (!visited[next]) {
            cur[cur_length] = next;
            if (cur_length <= 1 || bff[cur[cur_length - 1]] == next || bff[cur[cur_length - 1]] == cur[cur_length - 2]) {
                visited[next] = true;
                dfs(cur_length + 1, cur, answer, visited, n, bff);
                visited[next] = false;
            }
        }
    }
}