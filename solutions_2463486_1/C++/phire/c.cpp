#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

set<ll> good;

int base(int x)
{
    int r = 1;
    while (x) {
        r *= 10;
        x /= 10;
    }
    return r;
}

template <class T>
T rev(T x)
{
    T r = 0;
    while (x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

bool ispali(ll x)
{
    return x == rev(x);
}

void check2(int x)
{
    if (ispali((ll)x*x))
        good.insert((ll)x*x);
}

void check1(int x)
{
    int b = base(x);
    int r = rev(x);
    check2(x * b + r);
    for (int i = 0; i < 10; i++)
        check2(x * b * 10 + i * b + r);
}

int main(int argc, const char* argv[])
{
    good.insert(1);
    good.insert(4);
    good.insert(9);
    for (int x = 1; x < 1000; x++)
        check1(x);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        ll a, b;
        int r = 0;
        cin >> a >> b;
        foreach (it, good)
            if (a <= *it && *it <= b)
                r++;
        cout << "Case #" << i << ": " << r << endl;
    }
    return 0;
}
