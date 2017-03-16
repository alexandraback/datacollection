#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<string, string> SPair;

int T;
int n;
char fi[100001];
char se[100001];

int check(vector<SPair> &list, int st) {
    vector<SPair> tmp;
    map<string, bool> fi_dic, se_dic;
    int ret = 0;

    for (int i=0; i<n; i++) {
        if (!(st >> i & 1)) {
            fi_dic[list[i].first] = true;
            se_dic[list[i].second] = true;
        }
    }

    for (int i=0; i<n; i++) {
        if (st >> i & 1) {
            ret++;
            if (!fi_dic[list[i].first]) return -1;
            if (!se_dic[list[i].second]) return -1;
        }
    }

    return ret;
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        scanf("%d", &n);

        vector<SPair> list;
        for (int i=0; i<n; i++) {
            scanf("%s", fi);
            scanf("%s", se);
            list.push_back(SPair(fi, se));
        }

        int lim = 1 << n;
        int ans = 0;
        for (int st=0; st<lim; st++) {
            ans = max(ans, check(list, st));
        }
        printf("Case #%d: %d\n", Case, ans);
    }
}
