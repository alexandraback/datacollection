#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int alp2[26];
auto alp = alp2 - 'a';
int countnum[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        string s;
        cin >> s;
        memset(alp2, 0, sizeof(alp2));
        for (int i = 0; i < s.length(); ++i)
            ++alp[s[i] - 'A' + 'a'];
        countnum[0] = alp['z'];
        countnum[1] = alp['o'] - alp['z'] - alp['w'] - alp['u'];
        countnum[2] = alp['w'];
        countnum[3] = alp['r'] - alp['z'] - alp['u'];
        countnum[4] = alp['u'];
        countnum[5] = alp['f'] - alp['u'];
        countnum[6] = alp['x'];
        countnum[7] = alp['s'] - alp['x'];
        countnum[8] = alp['t'] - countnum[3] - countnum[2];
        countnum[9] = (alp['n'] - countnum[7] - countnum[1]) / 2;
        cout << "Case #" << test + 1 << ": ";
        for (int i = 0; i < 10; ++i)
            cout << string(countnum[i], i + '0');
        cout << endl;
    }
    return 0;
}