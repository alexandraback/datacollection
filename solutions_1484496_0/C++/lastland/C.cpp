#include<iostream>
#include<vector>
using namespace std;

const int maxn = 20 + 10;
int a[maxn];
vector<int> s[3];
int sum[3];
bool solved;
int T, n;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    solved = false;
    for (int i = 0; i < 3; i++) {
        s[i].clear();
        sum[i] = 0;
    }
}

void print() {
    cout << s[0][0];
    for (int i = 1; i < s[0].size(); i++) cout << ' ' << s[0][i];
    cout << endl;
    cout << s[1][0];
    for (int i = 1; i < s[1].size(); i++)
        cout << ' ' << s[1][i];
    cout << endl;

}

void solve(int k) {
    if(solved) return;
    if (!solved && sum[0] != 0 && sum[0] == sum[1]) {
        print();
        solved = true;
    }
    if (k >= n) return;
    for (int i = 0; i < 3; i++) {
        s[i].push_back(a[k]);
        sum[i] += a[k];
        solve(k + 1);
        sum[i] -= a[k];
        s[i].pop_back();
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        init();
        solve(0);
        if(!solved) cout<<"Impossible"<<endl;
    }
    return 0;
}
