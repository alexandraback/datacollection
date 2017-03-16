#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

unsigned long int solve( queue<unsigned long int> nB, queue<unsigned long int> typeB,
                    queue<unsigned long int> nT, queue<unsigned long int> typeT);

int main() {
    unsigned long int M, N, T, a1, A1, b1, B1;

    cin >> T;
    for (unsigned long int i = 1; i < T + 1; ++i) {
        queue<unsigned long int> typeB, nB, typeT, nT;
        cin >> N >> M;

        for (unsigned long int j = 0; j < N; ++j) {
            cin >> a1 >> A1;
            nB.push(a1);
            typeB.push(A1);
        }
        
        for (unsigned long int j = 0; j < M; ++j) {
            cin >> b1 >> B1;
            nT.push(b1);
            typeT.push(B1);
        }

        cout << "Case #" << i << ": " << solve(nB, typeB, nT, typeT) << endl;
    }
}

unsigned long int solve( queue<unsigned long int> nB, queue<unsigned long int> typeB,
                    queue<unsigned long int> nT, queue<unsigned long int> typeT) {
    if (nB.size() == 0 || nT.size() == 0) {
        return 0;
    }
    
    unsigned long int win = 0;
    if (typeB.front() == typeT.front()) {
        if (nB.front() > nT.front()) {
            nB.front() -= nT.front();
            win += nT.front();
            nT.pop();
            typeT.pop();
            return win + solve(nB, typeB, nT, typeT);
        } else {
            nT.front() -= nB.front();
            win += nB.front();
            nB.pop();
            typeB.pop();
            return win + solve(nB, typeB, nT, typeT);
        }
    }    

    queue<unsigned long int> nB2(nB), typeB2(typeB);
    nB.pop();
    typeB.pop();
    win = solve(nB, typeB, nT, typeT);
    nT.pop();
    typeT.pop();
    return max(win, solve(nB2, typeB2, nT, typeT));
}
