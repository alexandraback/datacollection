#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define de2(a,b) cout << #a << ':' << (a) << ' ' << #b << ':' << (b) << endl
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

enum {
    TYPE_1 = 1,
    TYPE_2 = 2,
    TYPE_3 = 3,
    TYPE_4 = 4,
};

bool existsWrong(vi& v) {
    For(i, v.size())
        if (v[i] == 1)
            return true;
    return false;
}

int type1(vi& v, int a, int b) {
    a = v.size();
    if (existsWrong(v)) {
        return (b-a) + 1 + b + 1;
    }
    return (b-a) + 1;
}

double calc(int a, int b, vector<double>& prob) {
    // printf("a:%d b:%d size:%d\n", a, b, (int)prob.size());
    For(i, prob.size()) {
        //printf("v[%d] = %lf\n", i, prob[i]);
    }
    map<int, double> tab;

    for (int i = 0; i < (1<<a); i++) {
        //printf("i:%d\n", i);
        vi keys;
        double p = 1;
        bool invalid = false;
        for (int j = 0; j < a; j++) {
            if (i & (1<<j)) {
                keys.push_back(0);
                p *= prob[j];
            }
            else {
                keys.push_back(1);
                p *= (1.0 - prob[j]);
                if (prob[j] == 1.0) {
                    invalid = true;
                    break;
                }
            }
        }
        if (invalid) {
            //printf("i:%d invalid\n", i);
            continue;
        }

        //printf("p:%lf\n", p);
        
        tab[TYPE_1] += p * type1(keys, a, b);

        // backspace

        for (int j = 1; j <= a; j++) {
            assert(!keys.empty());
            keys.pop_back();
            tab[1000 + j] += p * (j + type1(keys, a, b));
        }
        assert(keys.empty());

        // press enter righty away
        tab[TYPE_3] += p * (b + 2);
    }

    double best = 1e10;
    for (map<int, double>::iterator p = tab.begin(); p != tab.end(); ++p) {
        //de2(p->first, p->second);
        best = min(best, p->second);
    }
    return best;

}

int main() {
    int ncases;
    scanf("%d", &ncases);
    For(cc, ncases) {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<double> v(a);
        For(i, a) scanf("%lf", &v[i]);

        printf("Case #%d: %lf\n", cc+1, calc(a, b, v));
    }
}
