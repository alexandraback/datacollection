#include <bits/stdc++.h>

using namespace std;

int n;
string s;

void input()
{
    cin >> n >> s;
}

void output(int test, int k)
{
    cout << "Case #" << test<< ": " << k << '\n';
}

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    {
        input();
        int sum = 0;
        int kol = 0;
        for (int j = 0; j < s.length(); ++j)
        {
            if (s[j] == '0')
                continue;
            int k = s[j] - '0';
            kol += max(0, j - sum);
            sum += max(0, j - sum) + k;
        }
        output(i + 1, kol);
    }
    return 0;
}
