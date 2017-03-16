#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#define LL long long

using namespace std;

int T;

void output(int Case, long long ans)
{
    cout << "Case #" << Case << ": " << ans << endl;
}

int numBits(int n)
{
    int cur = 30;

    while ((n&(1<<cur)) == 0)
    {
        cur--;
    }
    return cur+1;
}

long long run(int a, int b, int k)
{
    LL total = 0;
    int nA = numBits(a-1);
    int nB = numBits(b-1);
    cout << nA << " " << nB << endl;

    for (int i = 0; i < k; i++)
    {
        int numSet = __builtin_popcount(i);
        if (i > a || i > b) break;
        int varA = nA-numSet;
        int varB = nB-numSet;
        int minFix = min(varA, varB);
        LL temp = 1<<(minFix);
        int maxFix = max(varA, varB);
        temp *= 1<<(maxFix-minFix);
        temp += 1<<(minFix);
        cout << numSet << " " << i << " " << temp << endl;
        total += temp;


    }
    return total;
}

long long runEast(int a, int b, int K)
{
    LL ans = 0;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < b; k++)
            {
                if ((j&k)==i)
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A, B, K;
        cin >> A >> B >> K;
        long long ans = runEast(A, B, K);
        output(i+1, ans);
    }

    return 0;
}
