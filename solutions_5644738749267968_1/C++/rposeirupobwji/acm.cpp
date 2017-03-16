#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

int read_()
{
    int tmp = 0;
    scanf("\n0.");

    char c = 0;

    FOR(5)
    {
        if (c != ' ' && c != '\n')
            scanf("%c", &c);

        if (c != ' ' && c != '\n')
            tmp += c - '0';
        tmp *= 10;
    }

    return tmp;
}

int War(vector<int> const& ken, vector<int> const& naomi)
{
    int res = 0;

    set<int> k(ALL(ken));

    FOR(ken.size())
    {
        auto itr = k.upper_bound(naomi[i]);
        if (itr == k.end())
            ++res, k.erase(k.begin());
        else
            k.erase(itr);
    }

    return res;
}

int Count(vector<int> const& ken, vector<int> const& naomi)
{
    int res = 0;

    set<int> k(ALL(ken));
    set<int> n(ALL(naomi));

    while (!n.empty())
    {
        // eat all possible
        while (!n.empty() && *n.rbegin() > *k.rbegin())
        {
            n.erase(--n.end());
            k.erase(--k.end());
            ++res;
        }
    
        // lure highest
        if (!n.empty())
        {
            k.erase(--k.end());
            n.erase(n.begin());
        }
    }

    return res;
}

int main()
{
    srand(time(NULL));
    cout << setprecision(15);
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int n;
        cin >> n;

        vector<int> ken, naomi;
        ken.clear();
        naomi.clear();

        FOR(n) naomi.push_back(read_());
        FOR(n) ken.push_back(read_());

        int war = War(ken, naomi);
        int dec = Count(ken, naomi);

        printf("Case #%d: %d %d\n", CASE, dec, war);
    }

    return 0;
}