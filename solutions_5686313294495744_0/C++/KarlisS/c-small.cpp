#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<string, string> ss;

static int solve(const vector<ss>& topics)
{
    int ans = 0;
    const int n = topics.size();
    for (int i=0; i<(1<<n); i++)
    {
        set<string> fw, sw;
        int nFake = 0;
        bool good = true;
        for (int j=0; j<n; j++)
        {
            if (i & (1<<j))
            {
                nFake++;
            }
            else
            {
                fw.insert(topics[j].first);
                sw.insert(topics[j].second);
            }
        }
        for (int j=0; j<n; j++)
        {
            if (i & (1<<j))
            {
                if (fw.find(topics[j].first) == fw.end() ||
                    sw.find(topics[j].second) == sw.end())
                {
                    good = false;
                    break;
                }
            }
        }
        if (good) ans = max(ans, nFake);
    }
    return ans;
}


int main()
{
    int t;
    cin >> t;
    for (int it=1; it<=t; it++)
    {
        int n;
        cin >> n;

        vector<ss> topics;
        for (int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;
            topics.push_back({a, b});
        }
        cout << "Case #" << it << ": ";
        cout << solve(topics);
        cout << "\n";
    }
}
