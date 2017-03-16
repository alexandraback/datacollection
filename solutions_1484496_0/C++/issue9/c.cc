#include <stdio.h>
#include <cstdio>
#include <map>

using namespace std;

int n;
int a[512];

multimap<int, int> r;


void prm(int m) {
    int first = 1;
    for (int i = 0; i < n; ++i) {
        if ((1<<i) & m) {
            if (!first) printf(" ");
            printf("%d", a[i]);
            first = 0;
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int T, solved;
    scanf("%d", &T);

    for (int ti = 1; ti <= T; ++ti) {
        r.clear();
        solved = 0;

        printf("Case #%d:\n", ti);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }

        int me = (1 << n);
        for (int m = 1; m < me; ++m) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if ((1<<i) & m) s += a[i];
            }
            if (r.count(s) > 0) {
                // check
                auto er = r.equal_range(s);
                for (auto it = er.first; it != er.second; ++it) {
                    int m2 = it->second;
                    if ((m2 & m) == 0) {
                        // solved, output
                        prm(m2);
                        prm(m);
                        // exit for
                        m = me;
                        solved = 1;
                        break;
                    }
                }
            }
            r.insert(pair<int,int>(s,m));
        }

        if (!solved) printf("Impossible\n");

        
    }
    return 0;
}
