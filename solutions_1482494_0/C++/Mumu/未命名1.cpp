#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int s;
    int index;
    bool r1;
    friend bool operator < (const Node& op1, const Node& op2) {
        return op1.s < op2.s;
    }
};
char flag1[1001];
char flag2[1001];

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    Node tmp1, tmp2;
    tmp1.r1 = true; tmp2.r1 = false;
    for (int k = 1; k <= T; k++) {
        vector<Node> v;  
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) { 
            scanf("%d %d", &tmp1.s, &tmp2.s);
            tmp1.index = i; tmp2.index = i;
            v.push_back(tmp1);
            v.push_back(tmp2);
        }
        sort(v.begin(), v.end());
        int i;
        for (i = 0; i <= n; i++) {
            memset(flag1, 0, sizeof(flag1));
            memset(flag2, 0, sizeof(flag2));
            int left = i, score = 0;
            bool ok = true;
            for (int j = 0; j < v.size(); j++) if (!v[j].r1) {
 //               printf("Cur No.= %d, value = %d\n", v[j].index, v[j].s);
                if (v[j].s > score) {
                    for (int u = 0; u < j && left && v[j].s > score && v[u].s <= score; u++) 
                        if (v[u].r1 && !flag1[v[u].index] && !flag2[v[u].index]) {
                            score++;
                            flag1[v[u].index]++;
                            left--;
                        }
                    if (v[j].s > score) {
                        ok = false;
                        break;
                    }
                        
                }
                {
                    if (flag1[v[j].index])
                        score++;
                    else
                        score += 2;
                    flag2[v[j].index]++;
                }
            }
            if (ok) break;
            
        }
        if (i <= n) {
            printf("Case #%d: %d\n", k, n + i);
        }else
            printf("Case #%d: Too Bad\n", k);
    }
//    system("pause");
    return 0;
}
