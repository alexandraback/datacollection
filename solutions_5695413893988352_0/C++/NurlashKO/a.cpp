//Solution by Zhusupov Nurlan
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define endl '\n'
#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define mp make_pair

LL P[20];
string r1, r2, X1, X2, Y1, Y2;
int sw;

string  maximize(string s)
{
    LL res = 0;
    for (int i = 0; i < len(s); i++)
        if (s[i] == '?')
            s[i] = '9';
    return s;
}

string minimize(string s)
{
    LL res = 0;
    for (int i = 0; i < len(s); i++)
        if (s[i] == '?') s[i] = '0';
    return s;
}

LL dif(string s, string t)
{
    LL n = len(s), res = 0;
    for (int i = 0; i < len(s); i++)
        res += LL(s[i] - t[i]) * P[n - i - 1];
    return abs(res);
}

void upd()
{
            if (sw) swap(X1, Y1), swap(X2, Y2);
            if (dif(X1, Y1) < dif(X2, Y2) || (dif(X1, Y1) == dif(X2, Y2) &&
                                                X1+Y1 <= X2+Y2))
                X1, Y1;
            else
                X1 = X2, Y1 = Y2;
            if (sw) swap(X1, Y1), swap(X2, Y2);
}

int main()
{
    freopen(fname"in", "r", stdin);
    freopen(fname"out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    P[0] = 1;
    for (int i = 1; i <= 18; i++)
        P[i] = P[i - 1] * 10;
    for (int test = 1; test <= T; test++)
    {
        string c, j;
        cout << "Case #" << test << ": ";
        cin >> c >> j;
        r1 = c, r2 = j;
        int n = len(c);
        int f = 0;
        sw = 0;
        LL ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (c[i] != '?' && j[i] != '?' && c[i] != j[i]) {
                if (c[i] > j[i]) sw = 1, swap(c, j), swap(r1, r2);
                string R1 = r1, R2 = r2;
                X1 = maximize(r1);
                Y1 = minimize(r2);
    
                f = 1;
                int p = i - 1;
                while (p >= 0) {
                    if (c[p] == '?' && j[p] == '?')
                    {
                        f = 2;
                        X2 = minimize(R1);
                        Y2 = maximize(R2);
                        X2[p] = '1';
                        upd();
                    }
                    if (c[p] != '?' && j[p] == '?' && c[p] > '0')
                    {
                        f = 2;
                        X2 = minimize(R1);
                        Y2 = maximize(R2);
                        Y2[p]--;
                        upd();
                    }
                    if (c[p] == '?' && j[p] != '?' && j[p] < '9')
                    {
                        f = 2;
                        X2 = minimize(R1);
                        Y2 = maximize(R2);
                        X2[p]++;
                        upd();
                    }
                    if (c[p] == '?') R1[p] = '0';
                    if (j[p] == '?') R2[p] = '9';

                    p--;
                }
                break;
            }
            if (c[i] == '?' && j[i] == '?')
                r1[i] = r2[i] = '0';
            else
            {
                if (c[i] == '?')
                    r1[i] = j[i];
                else
                if (j[i] == '?')
                    r2[i] = c[i];
            }   
            
        }
        if (!f)
            cout << r1 << " " << r2;
        else
        if (f == 1)
        {
            if (sw) swap(X1, Y1);
            cout << X1 << " " << Y1;
        }
        else
        {
            if (sw) swap(X1, Y1), swap(X2, Y2);
            if (dif(X1, Y1) < dif(X2, Y2) || (dif(X1, Y1) == dif(X2, Y2) &&
                                                X1+Y1 <= X2+Y2))
                cout << X1 << " " << Y1;
            else
                cout << X2 << " " << Y2;
        }
        cout << "\n";
    }
}
