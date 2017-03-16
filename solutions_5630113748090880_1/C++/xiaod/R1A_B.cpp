#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define FIN freopen("B-large.in", "r", stdin)
#define FOUT freopen("B-large.out", "w", stdout)

const int N = 1005;

int main() {
    FIN;
    FOUT;
    int T, n, ncase = 0;
    scanf("%d", &T);
    while(T--) {
        map<int, int> m;
        set<int> s;
        scanf("%d", &n);
        for(int i = 0; i < 2 * n - 1; ++i) {
            for(int j = 0; j < n; ++j) {
                int num;
                scanf("%d", &num);
                if(m.count(num) == 0) {
                    m[num] = 1;
                }
                else {
                    m[num] += 1;
                }
            }
        }
        for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            if(it->second % 2 == 1) {
                s.insert(it->first);
            }
        }
        printf("Case #%d:", ++ncase);
        for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            printf(" %d", *it);
        }
        puts("");
    }
    return 0;
}
