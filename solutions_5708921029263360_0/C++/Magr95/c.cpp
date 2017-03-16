#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    freopen("C-small-attempt0.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        int J, P, S, K, count = 0;
        printf("Case #%d: ", i);
        unordered_map <int, unordered_map<int, int> > jp, js, ps;
        vector<pair<int, pair<int, int> > > v;
        cin >> J >> P >> S >> K;
        for (int j = 1; j <= J; j++)
            for (int p = 1; p <= P; p++)
                for (int s = 1; s <= S; s++) {
                    if (jp[j][p] < K && js[j][s] < K && ps[p][s] < K) {
                        jp[j][p]++; js[j][s]++; ps[p][s]++; count++;
                        v.push_back(make_pair(j, make_pair(p, s)));
                    }
                }
        printf("%d\n", count);
        for (int j = 0; j < v.size(); j++) {
            printf("%d %d %d\n", v[j].first, v[j].second.first, v[j].second.second);
        }
    }
    return 0;
}
