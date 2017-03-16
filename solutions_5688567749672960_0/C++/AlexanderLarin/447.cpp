#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

const int MAX = 210000;
const int MAXC = 15;
const long long INF = 1e13;
const int MOD = 1000000007;
const double EPS = 1e-11;

int T;
long long n, out;

int length(long long l)
{
    int res = 0;
    while(l > 0)
    {
        ++res;
        l /= 10;
    }
    return res;
}

long long x10(int len)
{
    int l = 1;
    long long o = 1;
    for(;l < len; ++l)
        o *= 10;
    return o;
}

long long rev(long long in)
{
    long long out = 0;
    while(in > 0)
    {
        out *= 10;
        out += in % 10;
        in /= 10;
    }
    return out;
}

long long cnt(int len, long long to)
{
    //cout << "as" << to << ' '<< len << endl;
    
    long long a = x10(len / 2 + 1 + ((len & 1) ? 1 : 0));
    long long res = to % a;
    
    long long revto = rev(to);
    
    long long b = x10(len / 2 + 1);
    res += revto % b;
    res = min(res, to - x10(len));
    res = min(res, revto - x10(len) + 1);
    //cout << "a" << a << ' ' << b << ' ' << revto << ' '  << res << endl;
    
    return res;    
}

int main()
{
    freopen("./out.txt", "w", stdout);
    cin >> T;
    for(int Ti = 0; Ti < T; ++Ti)
    {
        cin >> n;
        out = min(10ll, n);
        if(n % 10 == 0)
        {
            n--;
            if(n > 10)
                out += 1;
        }
        long long cur = 9;
        int clen = 1;
        int target = length(n);        
        for(clen = 1; clen < target - 1; ++clen)
        {
            cur = cur * 10 + 9;
            out += cnt(clen + 1, cur) + 1;
        }
        if(target > 1)
            out += cnt(target, n);
        
        cout << "Case #" << Ti + 1 << ": " << out << "\n";
    }
}