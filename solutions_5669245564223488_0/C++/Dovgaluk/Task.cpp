#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string a[100];
const long long MOD = 1000000007LL;

long long f(int v)
{
    long long r = 1;
    while (v)
    {
        r = (r * v) % MOD;
        --v;
    }
    return r;
}

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        long long res = 0;
        int n;
        std::vector<int> first(26, -1), last(26, -1), same(26, 0);
        std::cin >> n;
        bool ok = true;
        for (int i = 0 ; i < n ; ++i)
        {
            std::cin >> a[i];
            bool eq = true;
            for (size_t j = 0 ; j != a[i].size() ; ++j)
            {
                if (a[i][0] != a[i][j])
                {
                    eq = false;
                    break;
                }
            }
            if (eq)
            {
                same[a[i][0] - 'a']++;
                a[i].clear();
            }
            else 
            {
                if (first[a[i][0] - 'a'] < 0)
                    first[a[i][0] - 'a'] = i;
                else
                    ok = false;
                if (last[a[i].back() - 'a'] < 0)
                    last[a[i].back() - 'a'] = i;
                else
                    ok = false;
            }
        }
        if (ok)
        {
            for (int i = 0 ; i < n ; ++i)
            {
                if (!a[i].empty())
                for (size_t j = 1 ; j != a[i].size() - 1 ; ++j)
                {
                    int c = a[i][j] - 'a';
                    if (i == first[c])
                    {
                        if (a[i][j] != a[i][j - 1])
                            ok = false;
                    }
                    else
                    {
                        if (first[c] != -1 && last[c] != i)
                            ok = false;
                    }
                    if (i == last[c])
                    {
                        if (a[i][j] != a[i][j + 1])
                            ok = false;
                    }
                    else
                    {
                        if (last[c] != -1 && first[c] != i)
                            ok = false;
                    }
                }
            }
            std::vector<bool> used(n);
            std::vector<long long> v;
            while (ok)
            {
                int notused = -1;
                for (int i = 0 ; i != n ; ++i)
                    if (!a[i].empty() && !used[i])
                        notused = i;

                if (notused == -1)
                    break;
                // find beginning
                int k = notused;
                while (last[a[k][0] - 'a'] != -1)
                {
                    k = last[a[k][0] - 'a'];
                    if (k == notused)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    long long r = 1;
                    do
                    {
                        used[k] = true;
                        int c1 = a[k][0] - 'a';
                        int c2 = a[k].back() - 'a';
                        r = (r * f(same[c1])) % MOD;
                        same[c1] = 0;
                        r = (r * f(same[c2])) % MOD;
                        same[c2] = 0;
                        k = first[c2];
                    }
                    while (k != -1);
                    v.push_back(r);
                }
            }
            if (ok)
            {
                for (int i = 0 ; i < 26 ; ++i)
                    if (same[i])
                        v.push_back(f(same[i]));
                long long r = 1;
                for (size_t i = 0 ; i != v.size() ; ++i)
                    r = (r * v[i]) % MOD;
                r = (r * f((int)v.size())) % MOD;
                res = r;
            }
        }
        std::cout << "Case #" << t << ": " << res << "\n";
	}
	return 0;
}

