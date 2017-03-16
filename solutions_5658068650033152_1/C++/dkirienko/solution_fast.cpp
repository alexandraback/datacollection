#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K;

int points(int h, int a, int b)
{
    if (a + 2 * (h - 1) < b)
        return 0;
    int ans = 0;
    for (int i = 0; i < h; ++i)
    {
        int c1 = a + 2 * i;
        int c2 = b + 2 * (h - 1 - i);
        ans += min(M, min(c1, c2));
    }
    return ans;
}

int count1(int h, int a, int b)
{
    return a + b + 2 * (h - 2);
}

int solve()
{
    cin >> N >> M >> K;
    if (K <= 4 || N == 1 || M == 1)
        return K;
    int ans = K;
    int h, a, b;
    for (h = 2; h <= N; ++h)
        for (a = 1; a <= M; ++a)
            for(b = a; b <= M; ++b)
            {
                if(points(h, a, b) >= K)
                    ans = min(ans, count1(h, a, b));
            }
    return ans;
}

int main()
{
    int T, num;
    cin >> T;
    for (num = 1; num <= T; ++num)
    {
        cout << "Case #" << num << ": " << solve() << endl;
    }
}

