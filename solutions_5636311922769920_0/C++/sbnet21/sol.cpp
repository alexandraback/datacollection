#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void solver(int K, int C, int S)
{
    if (K != S)
        cout << " IMPOSSIBLE";
    else {
        for (int i = 0; i < K; i++)
            cout << " " << (i+1);
    }
    cout << endl;
}


int main()
{
    int T, K, C, S;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> K >> C >> S;
        cout << "Case #" << (i+1) << ":";
        solver(K, C, S);
    }

    return 0;
}