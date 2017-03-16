#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int X, a, b, k;

vector<int> v;
int fans(int pos, bool yany, bool kany)
{
    if (pos == -1)
    {
        for (int i = 0; i < v.size(); i++)
            cerr << v[i];
        cerr << endl;
        return 1;
    }

    if (yany && kany)
    {
        for (int i = 0; i < v.size(); i++)
            cerr << v[i];
        for (int i = v.size(); i < 30; i++)
            cerr << '*';
        cerr << endl;
        return (1<<pos);
    }

    bool cank = true;
    if (kany == false)
        if ( ((1<<pos) & k) == 0 && ((1<<pos) & X) == 1)
            cank = false;

    bool cany = true;
    if (yany == false)
        if ( ((1<<pos) & b) == 0 )
            cany = false;

    bool can1 = cank && cany;

    int ans = 0;

    v.push_back(0);
    ans += fans(pos-1, yany || cany, kany || (((1<<pos) & k) == 1));
    v.pop_back();

    if (can1)
    {
        v.push_back(1);
        ans += fans(pos-1, yany, kany || (( ((1<<pos) & k) == 1 && ((1<<pos) & X) == 0)) );
        v.pop_back();
    }

    return ans;
}

/*int fans(int pos, int sum)
{
    if (pos == 0)
    {
        if ((sum + 1 <= b) && (((sum+1)&X) <= k ))
            return 2;
        else
            return 1;
    }

    if ( (1<<pos) > b )
        return fans(pos-1, sum);

    int ans = 0;
    ans = fans(pos-1, sum);
    if ()
}*/

int ans(int x)
{
    X = x;
    cerr << x << endl;
    return fans(30, false, false);
}

void solve(int TT)
{
    cerr << endl;
    cerr << TT << endl;
    long long res = 0;

    cin >> a >> b >> k;
    a--;
    b--;
    k--;

    for (int x = 0; x <= a; x++)
        for (int y = 0; y <= b; y++)
            if ((x&y) <= k)
            {
                //cerr << x<< ' ' << y << endl;
                res++;
            }

    cout << "Case #" << TT << ": " << res << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}

