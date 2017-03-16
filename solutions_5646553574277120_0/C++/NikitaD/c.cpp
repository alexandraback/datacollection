#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }





void solution()
{

    int c, d, v;
    cin >> c >> d >> v;
    vector <int> a(d);
    for (int i = 0; i < d; ++i)
    {
        cin >> a[i];
    }

    if (c == 1)
    {

        vector <bool> was(v + 1, false);
        was[0] = true;
        for (int i = 0; i < d; ++i)
        {
            for (int k = v; k >= 0; --k)
                if (was[k] && k + a[i] <= v)
                    was[k + a[i]] = true;
        }

        vector <int> b;
        for (int i = 1; i <= v; ++i)
        {
            if (!was[i])
            {
                b.push_back(i);
                for (int k = v; k >= 0; --k)
                    if (was[k] && k + b.back() <= v)
                        was[k + b.back()] = true;
            }
        }

        cout << b.size();
    }
}



int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);


    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test)
    {
        cout << "Case #" << test << ": ";
        solution();
        cout << "\n";
    }



    return 0;
}
