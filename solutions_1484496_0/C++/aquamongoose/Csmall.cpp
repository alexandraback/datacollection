#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <string> vs;
const int INF = 0x3f3f3f3f;
const int MAXN = 25, MAXS = 100010;

int s[MAXN];
vi masks[MAXS*20];
int n;

void print(int a, int b)
{
    for (int i=0; i<n; i++)
        if (a & (1 << i)) cout << s[i] << ' ';
    cout << endl;
    for (int i=0; i<n; i++)
        if (b & (1 << i)) cout << s[i] << ' ';
    cout << endl;
}

void solve()
{
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];
    for (int i=0; i<MAXS*20; i++)
        masks[i].clear();

    for (int mask=1; mask+1<(1 << n); mask++)
    {
        int val = 0;
        for (int j=0; j<n; j++)
            if (mask & (1 << j)) val += s[j];

        for (int i=0; i<masks[val].size(); i++)
        {
            if (!(mask & masks[val][i]))
            {
                print(mask, masks[val][i]);
                return;
            }
        }
        masks[val].push_back(mask);
    }
    cout << "Impossible\n";
}

int main()
{
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ":\n";
        solve();
    }
    return 0;
}
