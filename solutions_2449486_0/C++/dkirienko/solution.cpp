#include<iostream>
#include<vector>

using namespace std;

int N, M, A[100][100];

bool check(vector <int> & P)
{
    int i, j;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j)
            if (A[i][j] !=  min(P[i], P[N + j]))
                return false;
    return true;
}

bool gen(vector <int> & P, int k)
{
    bool res;
    if(k == 0)
        return check(P);
    else
    {
        P.push_back(1);
        res = gen(P, k - 1);
        P.pop_back();
        if (res)
            return true;
        P.push_back(2);
        res = gen(P, k - 1);
        P.pop_back();
        return res;
    }
}

void solve(int num)
{
    cin >> N >> M;
    vector <int> P;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < M; ++j)
            cin >> A[i][j];
    bool res = gen(P, N + M);
    cout << "Case #" << num << ": " << (res ? "YES" : "NO") << endl;
    return;
}

int main()
{
    int i, n;
    cin >> n;
    for (i = 1; i <= n; ++i)
        solve(i);
}
