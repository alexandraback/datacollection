#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <sstream>
#include <cmath>
#include <cassert>
using namespace std;

#define LOG

typedef vector<int> vec;
typedef vector<int>::iterator iter;
typedef unsigned int uint;

vec parse_vec(std::istream& in)
{
    if (in.peek() == '\n')
        in.get();

    string ss;
    getline(cin, ss);

    istringstream strin(ss);
    int n;

    vec v;
    while (strin >> n)
        v.push_back(n);

    return v;
}

void print_vec(string const& s, vec const& v)
{
#ifdef LOG
    cerr << s.empty() ? "" : " ";
    int vszie = v.size();
    for (int i = 0; i < vszie; ++i)
        cerr << v[i] << " ";
    cerr << "\n";
#endif
}

void print_vec(vec const& v)
{
    print_vec("", v);
}

template <class T>
void print(int tc, T const& val)
{
    cout << "Case #" << tc+1 << ": " << val << "\n";
}

template <class T>
void print(int tc, vector<T> const& val)
{
    cout << "Case #" << tc+1 << ":";
    int vsize = val.size();
    for (int i = 0; i < val.size(); ++i)
        cout << " " << val[i];

    cout << "\n";
}


int digits(int n)
{
    int d = 1;
    while (n /= 10)
        ++d;

    return d;
}

int next_ten(int n, int d)
{
    int c = 1;
    while (d--)
        c *= 10;
    return c;
}

void recycle(int n, vec& buf)
{
    int ndigit = digits(n);
    int maxn = next_ten(n, ndigit);
    
    buf.clear();
    int tens = 1;
    for (int i = 1; i < ndigit; ++i) {
        tens *= 10;
        int r = n / tens + (n % tens) * (maxn / tens);
        buf.push_back(r);
        sort(buf.begin(), buf.end());
        buf.erase(unique(buf.begin(), buf.end()), buf.end());
    }
}

int64_t solve(int a, int b)
{
    vec buf;
    int c = 0;
    for (int i = a; i < b; ++i) {
        recycle(i, buf);
        for (int j = 0; j < buf.size(); ++j) {
            if (buf[j] <= b && buf[j] >= a && buf[j] > i)
                ++c;
        }
    }

    return c;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int a, b;
        cin >> a >> b;
        print(i, solve(a,b));
    }
}
