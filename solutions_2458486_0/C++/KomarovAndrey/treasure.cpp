#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
vector<int> keyhole;
vector<vector<int> > keysInside;
multiset<int> keysAvail;
vector<vector<int> > dp;
vector<int> stack;
set<int> cache;

bool in(int i, int mask)
{
    return (mask >> i) & 1;
}

bool gen(int remain, int usedMask)
{
    if (remain == 0)
        return true;
    if (cache.count(usedMask))
        return false;
    for (int i = 0; i < n; i++)
    {
        if (in(i, usedMask))
            continue;
        auto it = keysAvail.find(keyhole[i]);
        if (it == keysAvail.end())
            continue;
        keysAvail.erase(it);
        for (int key : keysInside[i])
            keysAvail.insert(key);
        stack.push_back(i);
        if (gen(remain - 1, usedMask | (1 << i)))
            return true;
        stack.pop_back();
        keysAvail.insert(keyhole[i]);
        for (int key : keysInside[i])
            keysAvail.erase(keysAvail.find(key));
    }
    cache.insert(usedMask);
    return false;
}

void solveOne(int CASE)
{
    cout << "Case #" << CASE << ": ";
    cin >> k >> n;
    keysAvail = multiset<int>();
    for (int i = 0; i < k; i++)
    {
        int key;
        cin >> key;
        keysAvail.insert(key);
    }
    keysInside = vector<vector<int> >(n);
    keyhole = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> keyhole[i];
        int m;
        cin >> m;
        keysInside[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
            cin >> keysInside[i][j];
    }
    dp = vector<vector<int> >(n, vector<int>((1 << n), -1));
    stack = vector<int>();
    cache = set<int>();
    if (gen(n, 0))
    {
        for (int k = 0; k < n; k++)
            cout << (stack[k] + 1) << " ";
        cout << endl;
        return;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        solveOne(i + 1);
    }
}
