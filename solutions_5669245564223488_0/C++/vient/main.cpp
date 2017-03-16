#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool is_power_of_two(long long x)
{
    bool ans = true;
    while (x)
    {
        ans &= (x == 1 || (x != 1 && !(x & 1)));
        x >>= 1;
    }
    return ans;
}

long long gcd(long long a, long long b)
{
    return (b ? gcd(b, a % b) : a);
}

void dfs(int now, vector<vector<int> > & V, vector<bool> & Was)
{
    Was[now] = true;
    for (auto i : V[now])
        if (!Was[i])
            dfs(i, V, Was);
}

int main()
{
    ifstream cin("B-small-attempt10.in");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int stepnum = 1; q; q--, stepnum++)
    {
        cout << "Case #" << stepnum << ": ";
        int n, num = 0;
        int ans = 0;
        cin >> n;
        vector<string> V(n);
        for (auto & i : V)
            cin >> i;
        vector<int8_t> Z(n);
        iota(Z.begin(), Z.end(), 0);
        for (auto & s : V)
        {
            vector<bool> Was(26, false);
            for (int i = 1; i < s.size(); i++)
            {
                if (Was[s[i] - 'a'])
                    goto excuse_me_this_goto;
                if (s[i] != s[i - 1])
                    Was[s[i - 1] - 'a'] = true;
            }
        }
        do
        {
            vector<char> Was(26, false);
            register char prev = V[Z[0]][V[Z[0]].size() - 1];
            if (prev != V[Z[0]][0])
                Was[V[Z[0]][0] - 'a'] = true;
            int8_t * it = &Z[1];
            for (int i = n - 1; i; i--, it++)
            {
                if (Was[V[*it][0] - 'a'])
                    goto qwqwqw;
                if (V[*it][0] != prev)
                    Was[prev - 'a'] = true;
                prev = V[*it][V[*it].size() - 1];
                if (Was[prev - 'a'])
                    goto qwqwqw;
                if (V[*it][0] != prev)
                    Was[V[*it][0] - 'a'] = true;
            }
            ans++;
            qwqwqw:;
        } while (next_permutation(Z.begin(), Z.end()));
        cout << ans;
        excuse_me_this_goto:
        cout << '\n';
        cerr << stepnum << endl;
    }
    return 0;
}
