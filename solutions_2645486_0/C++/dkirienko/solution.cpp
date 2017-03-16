#include<iostream>

using namespace std;

long long * A, * B, * T;
int V[10000];

void solve(int num)
{
    int E, R, N, i, e, d;
    cin >> E >> R >> N;
    for(i = 0; i < N; ++i)
        cin >> V[i];
    for (i = 0; i <= E; ++i)
    {
        A[i] = 0;
        B[i] = 0;
    }
    for(i = 0; i < N; ++i)
    {
        for (e = 0; e <= E; ++e)
        {
            // e - сколько было энергии
            // d - сколько потратили
            for (d = 0; d <= e; ++d)
            {
                int newEnergy = e - d + R;
                if (newEnergy >= E)
                    newEnergy = E;
                int newGain = A[e] + d * V[i];
                if (B[newEnergy] < newGain)
                    B[newEnergy] = newGain;
            }
        }
        T = A;
        A = B;
        B = T;
    }
    long long ans = 0;
    for (e = 0; e <= E; ++e)
        if (A[e] > ans)
            ans = A[e];
    cout << "Case #" << num << ": " << ans << endl;
    return;
}

int main()
{
    A = new long long[10000001];
    B = new long long[10000001];
    int N, num;
    cin >> N;
    for (num = 1; num <= N; ++num)
    {
        solve(num);
    }
}
