#include <iostream>
#include <cmath>
using namespace std;

long long pow10[16];

long long flip(long long N)
{
    long long res = 0;
    while (N % 10 == 0)
        N /= 10;
    while(N >= 10) {
        res += N % 10;
        res *= 10;
        N /= 10;
    }
    res += N;
    return res;
}

long long descend(long long N, int ndigs, long long& steps)
{
    long long power = pow10[(ndigs + 1)/2], target = N/power;
    target = target * power + 1;
    if (N < target) {
        steps++;
        return descend(N-1, floor(log10(N-1)), steps);
    }
    steps += N - target;
    return target;
}

int main()
{
    pow10[0] = 1;
    for (int i = 1; i < 16; i++)
        pow10[i] = pow10[i-1] * 10;
    
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        long long N, steps = 1;
        cin >> N;
        while (N > 10) {
            int ndigs = floor(log10(N));
//            cout << "ndigs = " << ndigs << endl;
            N = descend(N, ndigs, steps);
//            cout << N << endl;
            if (N % 10 != 0) {
                long long nN = flip(N);
                if (nN != N) steps++;
                N = nN;
            }
//            cout << N << endl;
            N = descend(N, ndigs, steps);
//            cout << N << endl;
            long long nN = pow10[ndigs] - 1;
            if (nN < N) {
                steps += N - nN;
                N = nN;
            }
//            cout << N << endl;
        }
        steps += N - 1;
        cout << "Case #" << c << ": " << steps << endl;
    }
    return 0;
}
