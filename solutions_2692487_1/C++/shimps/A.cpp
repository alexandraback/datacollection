#include <iostream>
#include <algorithm>

using namespace std;

int a[128];

int main() {
    int T;
    cin >> T;
    for(int it=1;it<=T;it++) {
        int A, N;
        cin >> A >> N;
        for(int i=0;i<N;i++) cin >> a[i];
        if(A == 1) {
            cout << "Case #" << it << ": " << N << endl;
            continue;
        }
        sort(a,a+N);
        int be = 1000;
        for(int de=0;de<=N;de++) {
            int op = de;
            long long s = A;
            for(int i=0;i<N-de;i++) {
                while(s <= a[i]) {
                    s += s-1;
                    op++;
                }
                s += a[i];
            }
            be = min(be,op);
        }
        cout << "Case #" << it << ": " << be << endl;
    }
    return 0;
}

