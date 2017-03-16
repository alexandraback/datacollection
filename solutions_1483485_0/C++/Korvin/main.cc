#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>

using namespace std; // }}}

map<char, char> M;

void init()
{
    vector<string> a, b;

    a.push_back("y qee");
    b.push_back("a zoo");
    a.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    b.push_back("our language is impossible to understand");
    a.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    b.push_back("there are twenty six factorial possibilities");
    a.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    b.push_back("so it is okay if you want to just give up");

    vector<int> va(26), vb(26);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            M[a[i][j]] = b[i][j];
            if (a[i][j] != ' ') {
                va[a[i][j] - 'a'] = 1;
                vb[b[i][j] - 'a'] = 1;
            }
        }
    }

    int posa = find(va.begin(), va.end(), 0) - va.begin();
    int posb = find(vb.begin(), vb.end(), 0) - vb.begin();
    M['a' + posa] = 'a' + posb;

    /*cout << M.size() << endl;
    for (map<char, char>::iterator it0 = M.begin(); it0 != M.end(); ++it0)
        cout << it0->first << " " << it0->second << endl;*/
}

string translate(string s)
{
    string res;
    for (int i = 0; i < s.size(); ++i) {
        res+= M[s[i]];
    }

    return res;
}

int main()
{
    init();
    ifstream fcin("test.in");
    ofstream fcout("test.out");
    int T;
    fcin >> T;

    for (int i = 0; i <= T; ++i) {
        char cur[256];
        fcin.getline(cur, 256);
        fcout << "Case #" << i << ": " << translate(cur) << endl;
    }

    return 0;
}
