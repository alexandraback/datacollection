#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

map<char, char> w;
set<char> l, r;

void put(string a, string b)
{
    forv(i, a)
    {
        w[a[i]] = b[i];
        l.insert(a[i]);
        r.insert(b[i]);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    put("y qee", "a zoo");
    put("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");   
    put("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");   
    put("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

    for (char c = 'a'; c <= 'z'; c++)
    {
        for (char x = 'a'; x <= 'z'; x++)
        {
            if (l.count(c) == 0 && r.count(x) == 0) w[c] = x;
        }
    }

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc)
    {
        string s;
        getline(cin, s);
        printf("Case #%d: ", it + 1);
        forv(i, s) printf("%c", w[s[i]]);
        printf("\n");
    }

    return 0;
}
