#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

#define N 1010

int n;
double a[N], b[N];

void readInput()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}

void solve(int &dw_score, int &w_score)
{
    sort(a, a + n);
    sort(b, b + n);
    int i, j;
    dw_score = 0;
    for (i = 0, j = 0; i < n; i++)
    {
        if (a[i] > b[j])
        {
            j++;
            dw_score++;
        }
    }
    w_score = 0;
    for (i = n - 1, j = n - 1; i > -1; i--)
    {
        if (a[i] > b[j])
            w_score++;
        else j--;
    }
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        readInput();
        int dw_score = 0, w_score = 0;
        solve(dw_score, w_score);
        cout << dw_score << ' ' << w_score << endl;
    }
    return 0;
}
