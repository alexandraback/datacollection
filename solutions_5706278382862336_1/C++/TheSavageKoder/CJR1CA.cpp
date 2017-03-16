#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

long long GCD(long long A, long long B) {
    if(B == 0) return A;
    return GCD(B, A%B);
}

int F(long long P, long long Q) {
    long long G = GCD(P, Q);
    P /= G;
    Q /= G;

    if(2*P >= Q)
        return 1;

    return 1 + F(2*P, Q);
}


int main() {
//    cout << (long long)pow(2LL, 39) << endl;
    freopen("CJR1CA.in", "r", stdin);
    freopen("CJR1CA.out", "w", stdout);

    string PQ;
    int N;
    cin >> N;
    for(int cse = 1; cse <= N; cse++) {
        cin >> PQ;
        for(int i = 0; i < PQ.length(); i++)
            if(PQ[i] == '/')
                PQ[i] = ' ';
        istringstream iss(PQ);
        long long P, Q, TQ, G;
        iss >> P >> Q;
        G = GCD(P, Q);
        P /= G;
        Q /= G;

        bool possible = P <= Q;
        TQ = Q;
        while(TQ > 1) {
            if(TQ%2)
                possible = false;
            TQ /= 2;
        }
        cout << "Case #" << cse << ": ";
        if(possible)
            cout << F(P, Q) << endl;
        else
            cout << "impossible" << endl;
    }
}
