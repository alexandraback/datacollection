#include<iostream>
#include<set>

using namespace std;

int len(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

int pow10(int n)
{
    int ans = 1;
    while (n > 0)
    {
        --n;
        ans *= 10;
    }
    return ans;
}

int main()
{
    int n, num;
    cin >> n;
    set <int> S;
    for (num = 1; num <= n; ++num)
    {
        int A, B, ans, i, k;
        cin >> A >> B;
        ans = 0;
        for (i = A; i <= B; ++i)
        {
            int l = len(i);
            S.clear();
            for (k = 1; k < l; ++k)
            {
                int j = i / pow10(k) + i % pow10(k) * pow10(l - k);
                if (j > i && j <= B && S.count(j) == 0)
                {
                    S.insert(j);
                    // cout << i << " " << j << endl;
                    ++ans;
                }
            }
        }
        cout << "Case #" << num << ": " << ans << endl;
    }
}
