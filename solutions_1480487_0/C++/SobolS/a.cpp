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

int main()
{

    int nTests;
    cin >> nTests;    
    for (int test = 0; test < nTests; ++test)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
            sum += s[i];
        }
        
        cout << "Case #" << test + 1 << ":";
        for (int i = 0; i < n; ++i)
        {
            LD lft = 0, rgh = 1;
            for (int it = 0; it < 60; ++it)
            {
                LD m = (lft + rgh) / 2;
                
                LD cur_sc = s[i] + sum * m;
                LD rem = 1.L - m;

                for (int j = 0; j < n; ++j)
                {
                    if (i == j) continue;
                    if (s[j] < cur_sc)
                        rem -= (cur_sc - s[j]) / sum;
                }
                if (rem < -1.E-12)
                    rgh = m;
                else
                    lft = m;
            }
            cout << fixed << setprecision(10) << ' ' << lft * 100;
        }
        cout << '\n';
    }
    return 0;
}
