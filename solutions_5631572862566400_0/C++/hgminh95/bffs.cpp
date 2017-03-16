#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1111

int n;
int a[MAX_N];
vector<int> rev[MAX_N];
bool visited[MAX_N];

void init() {
    for (int i = 0; i < n; i++)
        rev[i].clear();
}

void reset() {
    for (int i = 0; i < n; i++)
        visited[i] = false;
}

int longestCircle(int u) {
    reset();
    int curr = u;
    visited[curr] = true;
    int res = 1;
    
    while (1) {
        int next = a[curr];
        
        if (next == u) return res;
        if (visited[next]) return 1;
        
        visited[next] = true;
        curr = next;
        res++;
    }
}

int longestPathTo(int u, int ignore) {
    int res = 0;
    for (int i = 0; i < rev[u].size(); i++) {
        int v = rev[u][i];
        if (v == ignore) continue;
        int temp = longestPathTo(v, ignore) + 1;
        
        if (res < temp) res = temp;
    }
    
    return res;
}

int main() {
    freopen("c.small.inp", "r", stdin);
    freopen("c.small.out", "w", stdout);
    
    int nTest;
    scanf("%d", &nTest);

    for (int test = 0; test < nTest; test++) {
        scanf("%d", &n);
        
        init();
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            tmp--;
            
            a[i] = tmp;
            rev[tmp].push_back(i);
        }
        
        int maxCircle = 0;
        int totalCircle2 = 0;
        for (int i = 0; i < n; i++) {
            int circle = longestCircle(i);
            //cout << i + 1 << " " << circle << endl;
            
            if (circle != 2) {
                if (maxCircle < circle) maxCircle = circle;
            }
            else  {
                // i, a[i]
                
                totalCircle2 += 2 + longestPathTo(i, a[i]) + longestPathTo(a[i], i);
            }
        }
        
        if (totalCircle2 % 2 != 0) printf("ERROR\nERROR\nERROR\n");
        totalCircle2 = totalCircle2 / 2;
        
        printf("Case #%d: %d\n", test + 1, max(maxCircle, totalCircle2));
    }
    return 0;
}
