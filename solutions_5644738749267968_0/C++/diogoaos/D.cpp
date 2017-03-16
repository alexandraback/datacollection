#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int deceit(set<double> sa, set<double> sb) {
    int cnt = 0;
    while (sa.size()) {
        if (*(sa.begin()) > *(sb.begin())) {
            cnt++;
            sb.erase(*(sb.begin()));
        } else {
            sb.erase(*(sb.rbegin()));
        }
        sa.erase(*(sa.begin()));
    }
    return cnt;
}

int war(set<double> sa, set<double> sb) {
    int cnt = 0;
    while (sa.size()) {
        if (*(sa.begin()) > *(sb.rbegin())) {
            cnt++;
            sb.erase(*(sb.begin()));
        } else {
            sb.erase(*(sb.lower_bound( *(sa.begin()) ) ) );
        }
        sa.erase(*(sa.begin()));
    }
    return cnt;
}

int main() {
    int ntests, n;
    double del;
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        scanf("%d", &n);
        
        set<double> sa, sb;
        
        for (int i = 0; i < n; i++) {
            scanf("%lf", &del);
            sa.insert(del);
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%lf", &del);
            sb.insert(del);
        }
        
        printf("Case #%d: %d %d\n", test, deceit(sa, sb), war(sa, sb));
    }
    return 0;
}
