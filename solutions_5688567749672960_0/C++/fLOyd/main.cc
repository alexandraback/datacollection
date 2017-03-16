#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 1000005;

long long n;
int ans[1000005];
deque<int> q;

void solve() {
    memset(ans, 0, sizeof(ans));
    ans[1] = 1;
    q.push_back(1);
    while (!q.empty()) {
        int num = q.front();
        q.pop_front();

        int addone = num + 1;

        string s = to_string(num);
        reverse(s.begin(), s.end());
        int rev = stoi(s);
        if (addone < MAXN && ans[addone] == 0) {
            ans[addone] = ans[num] + 1;
            q.push_back(addone);
        }


        if (rev < MAXN && ans[rev] == 0) {
            ans[rev] = ans[num] + 1;
            q.push_back(rev);
        }
    }
}

int main(int argc, char *argv[]) {
    int casesNum;

    solve();
    cin >> casesNum;
    for (int caseId = 1;  caseId <= casesNum; ++caseId) {
        cin >> n;
        cout << "Case #" << caseId << ": " << ans[n] << endl;
    }
    return 0;
}
