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

map<char, char> dict;

void add_to_dict(string const& g, string const& e)
{
    for (int i = 0; i < g.length(); ++i) {
        dict[g[i]] = e[i];
    }
}

string translate(string const& g)
{
    string s(g.length(), ' ');
    for (int i = 0; i < g.length(); ++i) {
        s[i] = dict[g[i]];
    }
    return s;
}


int main()
{
    add_to_dict("ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "our language is impossible to understand");
    add_to_dict("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "there are twenty six factorial possibilities");
    add_to_dict("de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "so it is okay if you want to just give up");

    dict['a'] = 'y';
    dict['z'] = 'q';
    dict['q'] = 'z';

    //cout << translate("abcdefghijklmnopqrstuvwxyz") << "\n";

    int tc;
    cin >> tc;
    cin.ignore(1);
    for (int i = 0; i < tc; ++i) {
        string gs;
        getline(cin, gs);
        print(i, translate(gs));
    }
}
