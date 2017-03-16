#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define RI(x) scanf("%d", &x)
#define RL(x) scanf("%I64d", &x)
#define RD(x) scanf("%f", &x)

string C, J;
ll dp[30][30][30];
vector<int> v1, v2;
int n;

void solve(int case_number)
{
    v1.clear();
    v2.clear();
    for (int i=0; i<22; ++i)
        for (int j=0; j<10; ++j)
            for (int k=0; k<10; ++k)
                dp[i][j][k] = LONG_LONG_MAX;
    cin >> C >> J;
    reverse(C.begin(), C.end());
    reverse(J.begin(), J.end());
    C = '0' + C;
    J = '0' + J;
    n = C.length();

    dp[0][0][0] = 0;
    for (int pos=1; pos<n; ++pos)
    {
        int last1, end1;
        if (C[pos] == '?')
        {
            last1 = 0;
            end1 = 10;
        }
        else
        {
            last1 = C[pos] - '0';
            end1 = C[pos] - '0' + 1;
        }
        for (; last1<end1; ++last1)
        {
            int last2, end2;
            if (J[pos] == '?')
            {
                last2 = 0;
                end2 = 10;
            }
            else
            {
                last2 = J[pos] - '0';
                end2 = J[pos] - '0' + 1;
            }
            for (; last2<end2; ++last2)
            {
                for (int i=0; i<10; ++i)
                {
                    for (int j=0; j<10; ++j)
                    {
                        if (dp[pos-1][i][j] == LONG_LONG_MAX)
                            continue;
                        ll tmp;
                        if (pos == 1)
                            tmp = last1 - last2;
                        else
                            tmp = dp[pos-1][i][j] + (last1 - last2)*10;
                        if (abs(dp[pos][last1][last2]) > abs(tmp))
                            dp[pos][last1][last2] = tmp;
                    }
                }
            }
        }
    }
    int st=0, en=0;
    for (int i=0; i<10; ++i)
        for (int j=0; j<10; ++j)
            if (abs(dp[n-1][i][j]) < abs(dp[n-1][st][en]))
            {
                st = i;
                en = j;
            }
    v1.pb(st);
    v2.pb(en);
    for (int pos=n-2; pos > 0; --pos)
    {
        bool ok = false;
        for (int i=0; i<10; ++i)
        {
            if (ok)
                break;
            for (int j=0; j<10; ++j)
            {
                if (ok)
                    break;
                if (dp[pos][i][j] == LONG_LONG_MAX)
                    continue;
                if (dp[pos][i][j] + (st - en)*10 == dp[pos+1][st][en])
                {
                    st = i;
                    en = j;
                    v1.pb(st);
                    v2.pb(en);
                    ok = true;
                }
            }
        }
    }


    cout << "Case #" << case_number << ": ";
    for (int i=0; i<n-1; ++i)
        cout << v1[i];
    cout << ' ';
    for (int i=0; i<n-1; ++i)
        cout << v2[i];
    cout << "\n";
}

int main()
{
    freopen("input4.in", "r", stdin);
    freopen("output4.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i)
        solve(i);

    return 0;
}

