#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define N 10000000

int dist[N];

int reverse(int a) {
    int tmp = a;
    int ans = 0;

    while(tmp != 0) {
        int last = tmp % 10;
        ans = ans * 10 + last;
        tmp /= 10;
    }

    return ans;
}

int main( void ) {
    int TA; cin >> TA;
    int cc = 1;

    while(TA--) {
        int n; 
        scanf("%d", &n);
        
        queue<int> Q;

        memset(dist, 63, sizeof dist);

        Q.push(1);
        dist[1] = 1;
    
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            if(cur == n) break;

            int cand = reverse(cur);

            if(dist[cand] > dist[cur] + 1) { 
                dist[cand] = dist[cur] + 1;
                Q.push(cand);
            }

            if(dist[cur + 1] > dist[cur] + 1) {
                Q.push(cur + 1);
                dist[cur + 1] = dist[cur] + 1;
            }
        }
        printf("Case #%d: %d\n", cc++, dist[n]); 
    }
    return 0;
}
