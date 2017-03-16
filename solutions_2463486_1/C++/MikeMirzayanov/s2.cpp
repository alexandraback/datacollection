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

long long tol(string s)
{
    stringstream ss;
    ss << s;
    long long l;
    ss >> l;
    return l;
}

vector<long long> topal(long long a)
{
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    string rev(s);
    reverse(rev.begin(), rev.end());
    vector<long long> r;
    r.push_back(tol(s + rev));
    r.push_back(tol(s + rev.substr(1)));
    return r;
}

bool pal(long long a)
{
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    forn(i, s.length() / 2)
        if (s[i] != s[s.length() - 1 - i])
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    set<pair<long long, long long> > ppp;
    for (long long i = 1; i <= 100000; i++)
    {
        vector<long long> p = topal(i);
        forn(j, p.size())
            if (pal(p[j]) && pal(p[j] * p[j]))
                ppp.insert(make_pair(p[j], p[j] * p[j]));
    }
    for (set<pair<long long,long long> > :: iterator it = ppp.begin(); it != ppp.end(); it++)
        cout << "\"" << it->second << "\"," << endl;
    return 0;
}
