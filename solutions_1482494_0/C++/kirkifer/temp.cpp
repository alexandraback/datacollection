#include <iostream>

using namespace std;

int *g_A, *g_B, *g_C, g_N;

int recurse(int moves, int stars)
{
    //cerr << moves << ' ' << stars << endl;

    int done = 0;
    int best = -1;
    for (int i = 0; i < g_N; i++)
    {
        int r = -1;
        if (g_C[i] == 2)
            done++;
        else if (stars >= g_B[i])
        {
            int old = g_C[i];
            g_C[i] = 2;
            r = recurse(moves + 1, stars + 2 - old);
            g_C[i] = old;
        }
        else if (!g_C[i] && stars >= g_A[i])
        {
            g_C[i] = 1;
            r = recurse(moves + 1, stars + 1);
            g_C[i] = 0;
        }
        if (r >= 0 && (r < best || best == -1))
            best = r;
    }
    if (done == g_N)
        return moves;
    return best;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int N;
        cin >> N;

        int A[N], B[N], C[N];
        for (int j = 0; j < N; j++)
        {
            cin >> A[j] >> B[j];
            C[j] = 0;
        }

        g_A = A; g_B = B; g_C = C; g_N = N;

        int r = recurse(0, 0);

        cout << "Case #" << i << ": ";
        if (r >= 0)
            cout << r << endl;
        else
            cout << "Too Bad" << endl;
    }

    return 0;
}
