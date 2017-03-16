#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    for (int z=0; z<T; z++) {
        int N,S; cin >> N >> S;
        int p; cin >> p;
        int scores[N];
        for (int i=0; i < N; i++) {
            cin >> scores[i];
        }
        sort(scores, scores+N);
        int count = 0;
        for (int i=N-1; i >= 0; i--) {
            if (scores[i] >= p*3-2) count++;
            else if (p>1 && scores[i] >= p*3-4 && S) S--, count++;
        }
        printf("Case #%d: %d\n",z+1, count);
    }
    return 0;
}