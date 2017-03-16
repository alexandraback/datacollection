#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 20;

pair<int, int> A[1 << N];
int X[N];

void wr(int x)
{
    for (int i = 0; i < N; i++)
        if ((x >> i) & 1)
            cout << X[i] << ' ';
    cout << endl;
}

void go()
{
    int n;
    cin >> n;
    assert(n == 20);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int msk = 0; msk < (1 << n); msk++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if ((msk >> i) & 1)
                sum += X[i];
        A[msk] = make_pair(sum, msk);
    }
    sort(A, A + (1 << n));
    for (int i = 0; i < (1 << n) - 1; i++)
    {
        if (A[i].first == A[i + 1].first)
        {
            wr(A[i].second);
            wr(A[i + 1].second);
            return;
        }
    }
    cout << "Impossible" << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cerr << i << endl;
        cout << "Case #" << i + 1 << ":" << endl;
        go();

    }

}
