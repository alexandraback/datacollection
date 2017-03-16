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

int C[10], T, digitLen[10], d[2222][10], pr[2222][10], cnt[500];
string s;
string digit[10] = {"ZERO", "EIGHT", "TWO", "SIX", "FOUR", "FIVE", 
                        "THREE", "SEVEN", "NINE", "ONE"};
int D[10] = {0, 8, 2, 6, 4, 5, 3, 7, 9, 1};

bool DO(int x)
{
    bool f = true;
    for (int i = 0; i < len(digit[x]); i++)
    {
        cnt[digit[x][i]]--;
        if (cnt[digit[x][i]] < 0) f = false;
    }
    if (f) return true;
    for (int i = 0; i < len(digit[x]); i++)
        cnt[digit[x][i]]++;
    return false;
}

int main()
{
    freopen(fname"in", "r", stdin);
    freopen(fname"out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int x = 0; x < 10; x++)
        digitLen[x] = len(digit[x]);
    cin >> T;
    for (int test = 1; test <= T; test++)
    {
        cout << "Case #" << test << ": ";
        cin >> s;
        int n = s.length();

        for (int i = 0; i < len(s); i++)
            cnt[s[i]]++;
        for (int i = 0; i < 10; i++)
        {
            C[D[i]] = 0;
            while (DO(i))
                C[D[i]]++;
        }
        for (int i = 0; i < len(s); i++)
            assert(!cnt[s[i]]);

        for (int i = 0; i < 10; i++)
            for (int j = 1; j <= C[i]; j++)
                cout << i;
        cout << "\n";
    }
}
