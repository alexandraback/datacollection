#include <cstdio>
#include <cmath>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int I = 2;
const int J = 3;
const int K = 4;

int quat(char ch)
{
    switch (ch)
    {
        case 'i':
            return I;
        case 'j':
            return J;
        case 'k':
            return K;
    }
    assert(false);
}

int sign(int val)
{
    return val < 0 ? -1 : 1;
}

int mul(int a, int b)
{
    int c;
    switch (abs(a))
    {
        case 1:
            c = abs(b);
            break;
        case I:
            switch (abs(b))
            {
                case 1:
                    c = I;
                    break;
                case I:
                    c = -1;
                    break;
                case J:
                    c = K;
                    break;
                case K:
                    c = -J;
                    break;
                default:
                    assert(false);
            }
            break;
        case J:
            switch (abs(b))
            {
                case 1:
                    c = J;
                    break;
                case I:
                    c = -K;
                    break;
                case J:
                    c = -1;
                    break;
                case K:
                    c = I;
                    break;
                default:
                    assert(false);
            }
            break;
        case K:
            switch (abs(b))
            {
                case 1:
                    c = K;
                    break;
                case I:
                    c = J;
                    break;
                case J:
                    c = -I;
                    break;
                case K:
                    c = -1;
                    break;
                default:
                    assert(false);
            }
            break;
    }
    return sign(a) * sign(b) * c;
}

int pow(int x, long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 1)
        return mul(x, pow(x, n - 1));
    int y = pow(x, n / 2);
    return mul(y, y);
}

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test)
    {
        cout << "Case #" << test << ": ";
        int l;
        long long x;
        string s;
        cin >> l >> x >> s;
        
        vector<int> v;
        v.reserve(l);
        int cycle = 1;
        for (int i = 0; i < l; ++i)
        {
            v.push_back(quat(s[i]));
            cycle = mul(cycle, v[i]);
        }
        int end = pow(cycle, x);
        if (end != -1)
        {
            puts("NO");
            continue;
        }
        
        bool good = false;
        int cur = 1, look = I;
        set<int> used;
        for (int rep = 0; rep < x && !good && used.find(cur) == used.end(); ++rep)
        {
            used.insert(cur);
            for (int i = 0; i < l; ++i)
            {
                cur = mul(cur, v[i]);
                if (cur == look)
                {
                    if (look == I)
                    {
                        look = K;
                        used.clear();
                    }
                    else
                    {
                        good = true;
                        break;
                    }
                }
            }
        }
        puts(good ? "YES" : "NO");
    }
    return 0;
}