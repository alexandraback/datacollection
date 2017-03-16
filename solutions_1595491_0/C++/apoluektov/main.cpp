#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <sstream>
#include <cmath>
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
    cerr << s << s.empty() ? "" : " ";
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


int solve(vec const& v, int p, int s) {
    int cn = 0;
    int cs = 0;
    int minn = 3*p-2;
    int mins = 3*p-4;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < mins)
            continue;
        else if (v[i] < minn) {
            if (v[i] >= 2)
                ++cs;
        }
        else
            ++cn;
    }

    return cn + min(s, cs);
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n, s, p;
        cin >> n >> s >> p;
        vec v;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        print(i, solve(v, p, s));
    }
}
