#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

void display(int bit, vi& v) {
    vi ret;
    For(i, v.size()) {
        if ((1<<i) & bit)
            ret.push_back(v[i]);
    }

    
    For(i, ret.size()) {
        if (i > 0) putchar(' ');
        printf("%d", ret[i]);
    }
    putchar('\n');
}
            
void calc(vi& v) {
    const int n = v.size();

    map<int, vi> m;
    for (int i = 0; i < (1 << n); i++) {

        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                sum += v[j];
            }
        }

        m[sum].push_back(i);
    }

    for (map<int, vi>::iterator p = m.begin(); p != m.end(); ++p) {
        const vi& w = p->second;
        if (w.size() > 1) {
            for (int i = 0; i < (int)w.size(); i++) {
                for (int j = i+1; j < (int)w.size(); j++) {
                    if ((w[i] ^ w[j]) == (w[i] | w[j])) {
                        display(w[i], v);
                        display(w[j], v);
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);

        vi v(n);
        For(i, n) scanf("%d", &v[i]);

        printf("Case #%d:\n", cc+1);
        calc(v);
    }
}
