#include<iostream>
#include<vector>

using namespace std;

int N, M, A[100][100];

const int INF = 1000;

bool TestHor(int i, int j)
{
    int jj;
    for (jj = 0; jj < M; ++jj)
        if (A[i][jj] != A[i][j] && A[i][jj] != INF)
            return false;
    return true;
}

bool TestVer(int i, int j)
{
    int ii;
    for (ii = 0; ii < N; ++ii)
        if (A[ii][j] != A[i][j] && A[ii][j] != INF)
            return false;
    return true;
}

void FillHor(int i, int val)
{
    int j;
    for (j = 0; j < M; ++j)
    {
        if(A[i][j] != INF)
            A[i][j] = INF;
    }
}

void FillVer(int j, int val)
{
    int i;
    for (i = 0; i < N; ++i)
    {
        if(A[i][j] != INF)
            A[i][j] = INF;
    }
}

bool solve()
{
    cin >> N >> M;
    int i, j, ii, jj, m;
    for (i = 0; i < N; ++i)
        for (j = 0; j < M; ++j)
            cin >> A[i][j];
    while (true)
    {
        m = INF;
        for (i = 0; i < N; ++i)
            for (j = 0; j < M; ++j)
            {
                if (A[i][j] < m)
                {
                    m = A[i][j];
                    ii = i;
                    jj = j;
                }
            }
        if (m == INF)
            return true;
        bool h, v;
        h = TestHor(ii, jj);
        v = TestVer(ii, jj);
        if (h == false && v == false)
            return false;
        int val = A[ii][jj];
        if (h)
            FillHor(ii, val);
        if (v)
            FillVer(jj, val);
    }
    return true;
}

int main()
{
    int i, n;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        bool res = solve();
        cout << "Case #" << i << ": " << (res ? "YES" : "NO") << endl;
    }
}

