#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int myabs(int a) {
    if(a < 0) return -a;
    return a;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int T, N;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        vector<string> v(N);
        int ans = 10000000;
        for(int n = 0; n < N; n++) cin >> v[n];
        bool flag = true;
        vector< pair<char, int> > comp[100];
        string u0 = v[0];
        u0.erase(unique(u0.begin(), u0.end()), u0.end());
        for(int n = 0; n < N; n++) {
            char c;
            int l = 0;
            string un = v[n];
            un.erase(unique(un.begin(), un.end()), un.end());
            if(u0 != un) {
                flag = false;
                break;
            }
            for(int i = 0; i < v[n].length(); i++) {
                if(i == 0) {
                    c = v[n][i];
                    l = 1;
                } else {
                    if(v[n][i] != v[n][i-1]) {
                        comp[n].push_back(pair<char, int>(c, l));
                        c = v[n][i];
                        l = 1;
                    } else {
                        l++;
                    }
                }
            }
            comp[n].push_back(pair<char, int>(c, l));
        }
        if(flag) {
            int tans = 0;
            for(int i = 0; i < comp[0].size(); i++) {
                vector<int> sz;
                for(int j = 0; j < N; j++) {
                    sz.push_back(comp[j][i].second);
                }
                sort(sz.begin(), sz.end());
                int d1 = 0, d2 = 0;
                for(int i = 0; i < sz.size(); i++) {
                    d1 += myabs(sz[i] - sz[sz.size()/2-1]);
                    d2 += myabs(sz[i] - sz[sz.size()/2]);
                }
                tans += min(d1, d2);
            }
            ans = tans;
        }
        cout << "Case #" << t << ": ";
        if(!flag) cout << "Fegla Won\n";
        else cout << ans << endl;
    }
}