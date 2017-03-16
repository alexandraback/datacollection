#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <iterator>
#include <complex>

using namespace std;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

const int N_MAX = 20 * 100500;
bool was[N_MAX];
int prev[N_MAX];

int main()
{

    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test)
    {
        int n;
        cin >> n;
        
        memset(was, 0, sizeof(was));
        memset(prev, -1, sizeof(prev));
        was[0] = true;

        vector<int> a, b;
        bool ok = false;

        for (int q = 0; q < n; ++q)
        {
            int x;
            cin >> x;

            for (int i = N_MAX - 1; !ok && i >= 0; --i)
                if (was[i])
                {
                    int j = i + x;
                    assert(j < N_MAX);
                    if (was[j])
                    {
                        ok = true;
                        for (int p = j; p != 0; p = prev[p])
                            a.push_back(p - prev[p]);
                        for (int p = i; p != 0; p = prev[p])
                            b.push_back(p - prev[p]);
                        b.push_back(x);
                    }
                    else { was[j] = true; prev[j] = i; }
                }
        }

#ifdef DEBUG
        for (int i = 0; i < 100; ++i) cerr << was[i];
        cerr << '\n';
#endif
        cout << "Case #" << test << ':' << '\n';
        if (!ok)
            cout << "Impossible\n";
        else
        {
            for (size_t i = 0; i < a.size(); ++i)
                cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
            
            for (size_t i = 0; i < b.size(); ++i)
                cout << b[i] << (i + 1 == b.size() ? '\n' : ' ');
        }
        
    }
    return 0;
}
