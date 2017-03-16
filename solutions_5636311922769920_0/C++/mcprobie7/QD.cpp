#include <stdio.h>
#include  <iostream>

using namespace std;

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("outputD.txt", "w", stdout);

    int nT;

    cin >> nT;

    for (int iT = 1; iT <= nT; iT++)
    {
        int K, C, S;

        cin >> K >> C >> S;

        long long K0 = 1;
        for (int i = 0; i < C - 1; i++) K0 = K0 * K;

        cout << "Case #" << iT << ":";

        long long K1 = 1;
        for (int i = 0; i < S; i++)
        {
            cout << " " << K1;
            K1 += K0;

        }
        cout << endl;


    }
    return 0;
}
