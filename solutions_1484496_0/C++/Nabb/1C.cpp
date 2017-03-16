#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> S(N);
    map<int,int> z;
    for(int i=0;i<N;i++) cin >> S[i];
    for(int i=1;i<(1<<N);i++) {
        int t=0;
        for(int j=0;j<N;j++) {
            if(i&(1<<j)) t += S[j];
        }
        if(z.find(t)!=z.end()) {
            for(int j=0;j<N;j++) {
                if(i&(1<<j)) cout << S[j] << " ";
            }
            cout << endl;
            i = z[t];
            for(int j=0;j<N;j++) {
                if(i&(1<<j)) cout << S[j] << " ";
            }
            cout << endl;
            return;
        }
        z[t] = i;
    }
    cout << "impossible" << endl;
}

int main(void) {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": " << endl;
        solve();
    }
    return 0;
}
