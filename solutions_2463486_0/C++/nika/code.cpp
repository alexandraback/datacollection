#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <hashtable.h>

using namespace std;
typedef long long ll;
int i, j, k, m, n;
char ss[10002];
int a[105], b[205];
vector<string> celebrations;
set<string> celebrationS;
string A, B;

bool nakl(const string& A, const string& B)
{
    if (A.size() != B.size())
        return A.size() < B.size();
    return A < B;
}

void celebrate()
{
    string cel;
    for (int i = 0; i < 2*n-1; i++)
        cel += string(1, b[i]+'0');
    //cout << cel << endl;
    celebrations.push_back(cel);
    celebrationS.insert(cel);
}

bool check()
{
    for (int i = 0; i < 2*n; i++) b[i] = 0;
    for (int i = 0; i < n; i++) if (a[i])
        for (int j = 0; j < n; j++) if (a[j])
        {
            b[i+j] += a[i] * a[j];
            if (b[i+j] >= 10) return false;
        }
    return true;
}

void build(int at)
{
    if (at > n-1-at) { celebrate(); return; }
    int start = (at == 0) ? 1 : 0;
    for (a[at] = start; 1; a[at]++)
    {
        if (at < n-1-at) a[n-1-at] = a[at];
        if (check()) build(at + 1); else break;
    }
    a[at] = a[n-1-at] = 0;
}

int count_less(string X)
{
    int P = 0;
    int Q = celebrations.size() - 1;
    while (P < Q)
    {
        int R = (P + Q + 1) / 2;
        if (nakl(X, celebrations[R]))
            Q = R-1;
        else
            P = R;
    }
    return P + 1;
}


int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);

    int ti, tn;
    cin >> tn;
    gets(ss);

    for (n = 1; n <= 51; n++) build(0);

    for (ti = 1; ti <= tn; ti++)
    {
        cin >> A >> B;
        int ans = count_less(B) - count_less(A) + celebrationS.count(A);

        cout << "Case #" << ti << ": " << ans << endl;
    }

    return 0;
}
