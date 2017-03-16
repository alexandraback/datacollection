#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;

        vector<string> first, second;
        for(int i = 0; i < n; ++i)
        {
            string f, s;
            cin >> f >> s;
            first.push_back(f);
            second.push_back(s);
        }

        int ans = 0;
        for(int i = 0; i < (1 << n); ++i)
        {
            int cnt = 0;
            set<string> orgfirst, orgsecond;
            for(int j = 0; j < n; ++j)
            {
                if(i & (1 << j))
                {
                    ++cnt;
                    orgfirst.insert(first[j]);
                    orgsecond.insert(second[j]);
                }
            }

            bool valid = true;
            for(int j = 0; j < n; ++j)
            {
                if(!(i & (1 << j)))
                {
                    if(orgfirst.count(first[j]) == 0)
                        valid = false;
                    if(orgsecond.count(second[j]) == 0)
                        valid = false;
                }
            }

            if(valid) ans = max(ans, n - cnt);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
