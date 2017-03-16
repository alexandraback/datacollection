#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2000001;
int parent[maxn], rank[maxn];
int T,A,B;
int digs[10];

int findset(int now) {
    if (parent[now] != now) {
       parent[now] = findset(parent[now]); 
    }
    return parent[now];
}


void unionset(int x ,int y){
     int rx = findset(x);
     int ry = findset(y);
     if (rx == ry) return;
     if (rank[rx] < rank[ry]) {
        rank[ry] += rank[rx];
        parent[rx] = ry;
     } else {
        rank[rx] += rank[ry];
        parent[ry] = rx;
     }
}

int solve(int num) {
    int len = 0;
    int top = 1;
    int prenum = num ,sum = num;
    while (num) {
          digs[len++] = num % 10;
          num /= 10;
          if (num) top *= 10;
    }
    for (int i = 0; i < len; i++) {
        
        int nextnum = (prenum - digs[len - 1 - i] * top) * 10 + digs[len - 1 - i];
        if (nextnum >= A && nextnum <= B) { 
           unionset(sum, nextnum);
        }
        prenum = nextnum;
    }
}


int main() {
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d",&A, &B);
        long long ret = 0;
        for (int i = A; i <= B; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = A; i <= B; i++) {
            if (parent[i] == i) {
               solve(i);
            }
        }
        for (int i = A; i <= B; i++) {
            if (parent[i] == i && rank[i] > 1) {
               ret += (long long)(rank[i] - 1) * (rank[i]) / 2;
            }
        }
        printf("Case #%d: ", cas);
        cout << ret << endl;
    }
}
