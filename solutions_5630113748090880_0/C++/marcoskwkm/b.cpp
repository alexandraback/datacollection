#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 60;

int main() {
    int t = 1, T;
    for (scanf("%d", &T); t <= T; t++) {
        vector< vector<int> > line[MAXN];
        int n;
        scanf("%d", &n);
        vector< vector<int> > v;
        for (int i = 1; i < 2*n; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                tmp.push_back(x);
            }
            v.push_back(tmp);
        }
        int missing = -1;
        for (int i = 0; i < n; i++) {
            int low = INF, p1 = -1, p2 = -1;
            for (int j = 0; j < (int)v.size(); j++) {
                if (v[j][i] < low) {
                    low = v[j][i];
                    p1 = j;
                    p2 = -1;
                }
                else if(v[j][i] == low) {
                    p2 = p1;
                    p1 = j;
                }
            }
            line[i].push_back(v[p1]);
            if (p2 != -1) {
                line[i].push_back(v[p2]);
                if (p1 > p2) swap(p1, p2);
                swap(v[p2], v.back());
                v.pop_back();
            }
            else missing = i;
            swap(v[p1], v.back());
            v.pop_back();
        }
        assert(missing != -1);        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i == missing) {
                ans.push_back(line[missing][0][missing]);
                continue;
            }
            if (line[i][0][missing] != line[missing][0][i])
                ans.push_back(line[i][0][missing]);
            else
                ans.push_back(line[i][1][missing]);
        }
        printf("Case #%d:", t);
        for (int x: ans) printf(" %d", x);
        printf("\n");            
    }
    return 0;
}
