#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>

using namespace std;

int main()
{
    vector<string> digits = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    map<char, int> cnt;
    for (auto &t : digits)
    {
        for (auto &i : t)
            cnt[i] += 1;
    }

    vector<int> res(10, 0);


    int t;
    cin >> t;
    getchar();
    for (int i = 0; i < t; i++)
    {
        string s;
        getline(cin, s);
        map<char, int> scnt;
        for (auto &c : s)
            scnt[c]++;

        res[0] = scnt['Z'];
        res[2] = scnt['W'];
        res[4] = scnt['U'];
        res[6] = scnt['X'];
        res[8] = scnt['G'];
        res[3] = scnt['H'] - res[8];
        res[7] = scnt['S'] - res[6];
        res[5] = scnt['V'] - res[7];
        res[1] = scnt['O'] - res[0] - res[2] - res[4];
        res[9] = scnt['I'] - res[5] - res[6] - res[8];
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < res[j]; k++)
                cout << j;
        cout << endl;
    }
    return 0;
}