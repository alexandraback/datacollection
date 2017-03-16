#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

// エラー訂正とかでよく見るアレ
void proc()
{
    ll K, C, S;
	cin >> K >> C >> S;
    if (S*C < K) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }

    vector <ll> ans;
    ll checkNum = -1;
    while (checkNum < K-1) {
        ll tmp = 0;
        for(ll c = 0; c < C; ++c) {
            tmp += powl(K, c) * (++checkNum);
            if (K-1 <= checkNum) break;
        }
        ans.push_back(tmp+1);
    }

    for (int i = 0; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":";
		proc();
	}
}
