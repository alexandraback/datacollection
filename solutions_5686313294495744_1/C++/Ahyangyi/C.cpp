#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int match(int i,
        std::vector<int>& U,
        std::vector<int>& M,
        const std::vector<std::vector<int>>& Ai,
        std::vector<int>& V)
{
    V[i] = 1;
    for (int j = 0; j < Ai[i].size(); j++)
    {
        int next = Ai[i][j];
        if (M[next] == -1)
        {
            U[i] = 1;
            M[next] = i;
            return 1;
        }
    }
    for (int j = 0; j < Ai[i].size(); j++)
    {
        int next = Ai[i][j];
        if (!V[M[next]] && match(M[next], U, M, Ai, V))
        {
            U[i] = 1;
            M[next] = i;
            return 1;
        }
    }
    return 0;
}

int match(int i,
        std::vector<int>& U,
        std::vector<int>& M,
        const std::vector<std::vector<int>>& Ai
        )
{
    std::vector<int> V(U.size(), 0);
    return match(i, U, M, Ai, V);
}

int main()
{
    int t, ct;
    for (cin >> t, ct = 1; ct <= t; ct++)
    {
        int q;
        cin >> q;
        std::unordered_map<string, int> A_id, B_id;
        std::vector<int> A(q);
        std::vector<int> B(q);
        int n = 0, m = 0;
        for (int i = 0; i < q; i++)
        {
            string a, b;
            cin >> a >> b;
            if (A_id.find(a) == A_id.end())
            {
                A_id[a] = n ++;
            }
            if (B_id.find(b) == B_id.end())
            {
                B_id[b] = m ++;
            }
            A[i] = A_id[a];
            B[i] = B_id[b];
        }

        std::vector<std::vector<int>> Ai(n);
        for (int i = 0; i < q; i++)
        {
            Ai[A[i]].push_back(B[i]);
        }

        int ans = q - n - m;
        std::vector<int> U(n, 0);
        std::vector<int> M(m, -1);
        for (int i = 0; i < n; i++)
        {
            ans += match(i, U, M, Ai);
        }
        cout << "Case #" << ct << ": " << ans << endl;
    }

    return 0;
}
