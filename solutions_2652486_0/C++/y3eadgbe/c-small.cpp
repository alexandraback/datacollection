#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<pair<int, int> > fac(int n) {
    vector<pair<int, int> > ans;
    for (int i = 2; i <= 7; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            ans.push_back(make_pair(i,cnt));
        }
    }
    return ans;
}

void solve() {
    int R,N,M,K;
    cin >> R >> N >> M >> K;
    cout << endl;
    rep(i, 100) {
        int hoge[10] = {0};
        rep(i,K) {
            int tmp;
            cin >> tmp;
            vector<pair<int, int> > f = fac(tmp);
            rep(i,f.size()) {
                if (f[i].first == 2) {
                    hoge[f[i].first] = max(hoge[f[i].first], f[i].second);
                } else {
                    hoge[f[i].first] = max(hoge[f[i].first], f[i].second);
                }
            }
        }
        int rem = 3;
        rep(i,hoge[3]) {
            cout << 3;
            rem--;
        }
        rep(i,hoge[5]) {
            cout << 5;
            rem--;
        }
        if (rem == 1) {
            cout << (1 << rem);
        } else if (rem == 2) {
            if (hoge[2] == 2) {
                cout << 22;
            } else if (hoge[2] == 4) {
                cout << 44;
            } else {
                cout << 24;
            }
        } else if (rem == 3) {
            cout << 244;
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
