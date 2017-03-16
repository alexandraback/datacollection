#include <iostream>
#include <vector>

using namespace std;

vector<double> pows5;

void powers5()
{
    pows5.push_back(1.0);
    for (int i = 1; i <= 3000; ++i)
        pows5.push_back(pows5[i - 1] * 0.5);
}

double solve(int N, int X, int Y)
{
    if (Y < 0)
        return 0.0;

    int K = 0;
    for (; (2 * K + 1) * (K + 1) <= N; ++K);
    --K;

    int M = N - (2 * K + 1) * (K + 1);

    if (X < 0 && X >= -2 * K + Y)
        return 1.0;
    if (X == 0 && Y < 2 * K + 1)
        return 1.0;
    if (X > 0 && X <= 2 * K - Y)
        return 1.0;

    if (X < 0 && X < -2 * (K + 1) + Y)
        return 0;
    if (X == 0 && Y >= 2 * K + 1)
        return 0.0;
    if (X > 0 && X > 2 * (K + 1) - Y)
        return 0.0;

    int level = -1;
    for (int i = 1; ; ++i) {
        if (M >= 2 * (K + 1) + i) 
            ++level;
        else
            break;
    }

    if (Y <= level)
        return 1.0;
    Y -= (level + 1);

    M -= 2 * (level + 1);
    double res = 0.0;
    for (int k = Y + 1; k <= M; ++k)
        res += pows5[k];

    return res;
}

int main()
{
    powers5();

    int T;
    cin >> T;

    int id = 1;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        cout << "Case #" << id << ": " << solve(N, X, Y) << "\n";
        ++id;
    }

    return 0;
}
