#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

template <class T>
void printAnswer(const vector<T> ans)
{
    int i = 1;
    for (const auto& x : ans) {
        cout << "Case #" << i << ": " << x << endl;
        ++i;
    }
    return;
}


int findMinHonest(vector< pair<string, string> > edges)
{
    int n = edges.size();
    set<string> sLeft, sRight;
    set<string> sLeftMask, sRightMask;
    for (int i = 0; i < n; ++i) {
        sLeft.insert(edges[i].first);
        sRight.insert(edges[i].second);
    }

    int minHonest = n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cnt = 0;
        sLeftMask = sLeft;
        sRightMask = sRight;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0)
                continue;
            ++cnt;
            //sLeftMask.erase(sLeftMask.find(edges[i].first));
            //sRightMask.erase(sRightMask.find(edges[i].second));
            sLeftMask.erase(edges[i].first);
            sRightMask.erase(edges[i].second);
        }
        if (sLeftMask.empty() && sRightMask.empty() && (cnt < minHonest))
            minHonest = cnt;
    }
    return minHonest;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T = 0;
    cin >> T;
    vector<int> ans(T);
    for (int t = 0; t < T; ++t) {
        int n = 0;
        cin >> n;
        vector< pair<string, string> > edges(n);
        for (int i = 0; i < n; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        ans[t] = n - findMinHonest(edges);
    }


    printAnswer(ans);
    return 0;
}