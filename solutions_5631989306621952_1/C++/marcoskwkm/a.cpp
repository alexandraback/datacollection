#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    int t = 1, T;
    for (scanf("%d", &T); t <= T; t++) {
        deque<char> v;
        string s;
        cin >> s;
        v.push_back(s[0]);
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] >= v[0]) v.push_front(s[i]);
            else v.push_back(s[i]);
        }
        printf("Case #%d: ", t);
        for (char c: v) printf("%c", c);
        printf("\n");                   
    }
    return 0;
}
