#include <iostream>
#include <map>

using namespace std;

int N, A[32];

int main() {
    int T;
    cin >> T;
    for(int te=1;te<=T;te++) {
        cin >> N;
        for(int i=0;i<N;i++) cin >> A[i];
        map<int, int> S;
        int f=0;
        int a, b;
        for(int m=1;m<(1<<N) && !f;m++) {
            int su = 0;
            for(int i = 0; i < N; i++) if(m&(1<<i)) su += A[i];
            if(S.find(su) != S.end()) {
                f = 1;
                a = S[su];
                b = m;
            } else S[su] = m;
        }
        cout << "Case #" << te << ":" << endl;
        if(!f) cout << "Impossible" << endl;
        else {
            int t = (a&b);
            a ^= t;
            b ^= t;
            for(int i = 0; i < N; i++) if(a&(1<<i)) cout << A[i] << " "; cout << endl;
            for(int i = 0; i < N; i++) if(b&(1<<i)) cout << A[i] << " "; cout << endl;
        }
    }
    return 0;
}
