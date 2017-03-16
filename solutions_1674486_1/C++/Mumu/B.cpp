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
    int r1, r2;
    bool f1, f2;
    friend bool operator < (const Node& op1, const Node& op2) {
        return op1.r2 > op2.r2;
    }
    Node():f1(false), f2(false) {}
};

int findmin(vector<Node>& v) {
    int ret = -1;
    for (int i = 0; i < v.size(); i++) 
        if (!v[i].f2 && (ret == -1 || v[i].r2 < v[ret].r2))
            ret = i;
    return ret;
}

int findmax(vector<Node>& v, int score) {
    int ret = -1;
    for (int i = 0; i < v.size(); i++) 
        if (!v[i].f2 && !v[i].f1 && v[i].r1 <= score && (ret == -1 || v[i].r2 > v[ret].r2))
            ret = i;
    return ret;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out1", "w", stdout);
    int T;
    scanf("%d", &T);
    Node tmp;
    for (int k = 1; k <= T; k++) {
        vector<Node> v;  
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) { 
            scanf("%d %d", &tmp.r1, &tmp.r2);
            v.push_back(tmp);
        }
        
        int res = 0, score = 0, i = 0;
        for (; i < n; i++) {
            int x = findmin(v);
            int y;
            while (v[x].r2 > score) {
                y = findmax(v, score);
                if (y == -1) break;
                else {
                    score++;
                    res++;
                    v[y].f1 = true;
                }
            }
            if (y == -1) break;
            else {
                if (v[x].f1) score++;
                else score += 2;
                
                res++;
                v[x].f2 = true;
            }
        }
        if (i == n) 
            printf("Case #%d: %d\n", k, res);
        else
            printf("Case #%d: Too Bad\n", k);
    }
//    system("pause");
    return 0;
}
