#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000001;
int d[N];
int p[N];
queue<int> q;

long long rev(long long n)
{
        stringstream ss;
        ss << n;
        string t;
        ss >> t;
        reverse(t.begin(), t.end());
        stringstream ss2;
        ss2 << t;
        ss2 >> n;
        return n;
}

long long get(long long n)
{
    long long result = 0;

    while (n > 1)
    {
        // cout << "? " << n << endl;
        stringstream ss;
        ss << n;
        string s;
        ss >> s;

        int len = s.length();
        int end = len / 2 - 1;

        if (len < 2)
        {
            n--;
            result++;
            continue;
        }

        long long before = n;
        forn(i, end + 1)
            before /= 10;
        forn(i, end + 1)
            before *= 10;
        before++;
        
        int t = 0;
        while ((before > n || rev(before) >= before) && before >= 1)
        {
        before = n;
        forn(i, end + 1)
            before /= 10;
        before -= (++t);
        forn(i, end + 1)
            before *= 10;
        before++;
        }

        //cout << n << " " << before << endl;

        if (before <= n && rev(before) < before)
        {
            // cerr << n << " -> " << before << endl;
            result += n - before + 1;
            n = rev(before);
            continue;
        }

        n--;
        result++;
    }

    return result + 1;
}

int main(int argc, char* argv[])
{
    /*
    get(21);
    return 0;
    */
    /*
    cout << get(54) << endl;
    return 0;
    for (int i = 1; i <= 1000; i++)
        cout << i << " " << get(i) << endl;
    return 0;
    */
    /*
    d[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        {
            int v = u + 1;
            if (v < N && d[v] == 0)
            {
                d[v] = d[u]  +1;
                p[v] = u;
                q.push(v);
            }
        }
        {
            int v = rev(u);
            if (v < N && d[v] == 0)
            {
                d[v] = d[u]  +1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    cerr << "ok" << endl;

    forn(i, N)
    {
        cout << i << " " << d[i] << " " << p[i];
        if (p[i] + 1 != i)
            cout << " xxxx ";
        cout << endl;

        if (d[i] != get(i))
        {
            cout << "error " << i << " " << d[i] << " " << get(i) << endl;
        }
    }
    */
    //freopen("input.txt", "rt", stdin);

    int tt;
    cin >> tt;

    forn(test, tt)
    {
        long long x;
        cin >>x;
        cout << "Case #" << (test + 1) << ": " << get(x) << endl;
    }

    return 0;
}
