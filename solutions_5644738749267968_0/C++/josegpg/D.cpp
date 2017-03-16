#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T, N;
double A[1005], B[1005];

void printGame() {
    for (int i = 0; i < N; i++)
            cout << A[i] << " ";
        cout << endl;
        
        for (int i = 0; i < N; i++)
            cout << B[i] << " ";
        cout << endl;
        
}

int playWar() {
    int i, j = 0;
    for (i = 0; i < N; i++) {
        while (j < N && B[j] < A[i]) j++;
        j++;
        if (j > N) break;
    }
    
    return N - i;
}

int playWar2() {
    int i = 0, j = 0, count = 0;
    
    while (i < N) {
        if (A[i] > B[j]) {
            count++;
            j++;
        }
        
        i++;
    }
    
    return count;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> A[i];
        
        for (int i = 0; i < N; i++)
            cin >> B[i];
        
        sort(A, A+N);
        sort(B, B+N);
        
        printf("Case #%d: %d %d\n", t, playWar2(), playWar());
        
    }
    
    return 0;
}
