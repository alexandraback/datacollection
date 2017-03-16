#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int testCases, caseNumber;

int main () {
    int testCases;
    cin >> testCases;
    for(int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
        int K, C, S;
        cout << "Case #" << caseNumber << ":";
        cin >> K >> C >> S;
        if (C * S < K) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        for(int startPosition = 0; startPosition < K; startPosition += C) {
            int finishPosition = min(K, startPosition + C);
            long long query = 0;
            for(int i = startPosition; i < finishPosition; i++)
                query = query * 1LL * K + i;
            for(int i = finishPosition; i < startPosition + C; i++)
                query = query * 1LL * K;
            cout << " " << query + 1;
        }
        cout << endl;
    }
    return 0;
}