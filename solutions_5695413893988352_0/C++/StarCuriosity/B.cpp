#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

string getstring(int num, int len)
{
    string tmp = to_string(num);
    int k = tmp.length();
    string ans(len - k, '0');
    ans += tmp;
    return ans;
}

bool good(const string& mask, int num)
{
    int n = mask.length();
    if (to_string(num).length() > n)
        return false;
    string tmp = getstring(num, n);
    for(int i = 0; i < n; ++i)
        if (mask[i] != '?' && mask[i] != tmp[i])
            return false;
    return true;
}

void solve(int numtest)
{
    string a,b;
    cin >> a >> b;

    pair<int,int> best(0, 999999);

    for(int x = 0; x < 1000; ++x)
        if (good(a, x))
            for(int y = 0; y < 1000; ++y)
                if (good(b, y))
                {
                    int cur = abs(x - y);
                    int bestval = abs(get<0>(best) - get<1>(best));
                    if (tie(cur, x, y) < tie(bestval, best.first, best.second))
                        best = {x,y};
                }

    cout << "Case #" << numtest << ": " << getstring(best.first, a.length()) << ' ' << getstring(best.second, a.length()) <<'\n';
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        solve(i);
        cerr << "ok " << i << endl;
    }
}

