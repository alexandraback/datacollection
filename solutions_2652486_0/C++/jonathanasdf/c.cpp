#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
    int T; cin >> T;
    for (int zz=1; zz <= T; zz++) {
        cout << "Case #" << zz << ": " << endl;
        int R, N, M, K; cin >> R >> N >> M >> K;
        for (int i=0; i < R; i++) {
            int cnt[6]; memset(cnt, 0, sizeof cnt);
            for (int j=0; j < K; j++) {
                int v; cin >> v; if(v==1) continue;
                int c=0;
                while(v%2==0) { c++; v/=2; }
                cnt[2] = max(cnt[2], c);
                c=0;
                while(v%3==0) { c++; v/=3; }
                cnt[3] = max(cnt[3], c);
                c=0;
                while(v%5==0) { c++; v/=5; }
                cnt[5] = max(cnt[5], c);
            }
            int c=0;
            for (int j=0; j < cnt[3]; j++) {
                c++;
                cout << 3;
            }
            for (int j=0; j < cnt[5]; j++) {
                c++;
                cout << 5;
            }
            if (c==2 && cnt[2] == 2) cout << 4;
            else if (c==2 && cnt[2] == 1) cout << 2;
            else if (c==1 && cnt[2] == 2) cout << 22;
            else {
                for (; c<3; c++) cout << 2;
            }
            cout << endl;
        }
    }
    return 0;
}
