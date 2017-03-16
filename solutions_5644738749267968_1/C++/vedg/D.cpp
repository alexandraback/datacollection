//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <cassert>

using namespace std;

typedef std::vector<int> Blocks;
void read(Blocks & b)
{
    for (size_t i = 0; i < b.size(); ++i) {
        string s;
        cin >> s;
        assert(s.substr(0, 2) == "0.");
        s.resize(8, '0');
        b[i] = std::stoi(s.substr(2));
    }
    sort(b.begin(), b.end());
}

int war(const Blocks & naomi, const Blocks & ken)
{
    int kenScore = 0;
    for (size_t i = 0, j = 0; i < naomi.size(); ++i) {
        j = upper_bound(ken.begin() + j, ken.end(), naomi[i]) - ken.begin();
        if (j == ken.size())
            break;
        ++j;
        ++kenScore;
    }
    return ken.size() - kenScore;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        int n;
        cin >> n;
        Blocks naomi(n), ken(n);
        read(naomi);
        read(ken);


        cout << "Case #" << cas << ": "
             << ken.size() - war(ken, naomi) << ' ' << war(naomi, ken) << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}

