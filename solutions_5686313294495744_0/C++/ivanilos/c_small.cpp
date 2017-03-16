#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#define pb push_back
#define MAX_LEN 25
using namespace std;

vector <pair <string, string> > v;
char s1[MAX_LEN];
char s2[MAX_LEN];
set <string> left;
set <string> right;

int main(void) {
    int t;
    int n;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        v.clear();
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %s %s", s1, s2);
            v.pb(make_pair(string(s1), string(s2)));
        }

        int res = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            left.clear();
            right.clear();
            int counter = 0;
            for (int i = 0; i < n; i++) {
                int bit = (mask >> i) & 1;
                if (bit == 0) {
                    left.insert(v[i].first);
                    right.insert(v[i].second);
                }
            }
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int bit = (mask >> i) & 1;
                if (bit == 1) {
                    counter++;
                    if (left.find(v[i].first) == left.end() || right.find(v[i].second) == right.end()) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                res = max(res, counter);
            }
        }
        printf("Case #%d: %d\n", caso, res);
    }
    return 0;
}
