#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

const int INF = 1001001001;
std::vector<int> G[1000001];
int dist[1000001];

int main(){
    for(int i=1;i<=1000000;i++){
        if(i+1 <= 1000000){
            G[i].push_back(i+1);
        }
        std::string s = std::to_string(i);
        std::reverse(s.begin(), s.end());
        int ri = 0;
        for(const char c : s){
            ri = ri * 10 + c - '0';
        }
        G[i].push_back(ri);
    }

    std::fill(dist, dist+1000001, INF);
    dist[1] = 0;

    std::deque<int> deque;
    deque.push_front(1);

    while(!deque.empty()){
        int u = deque.front();
        deque.pop_front();
        for(int v : G[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                deque.push_back(v);
            }
        }
    }
    
    int T;
    scanf("%d", &T);

    for(int i=0;i<T;i++){
        int N;
        scanf("%d", &N);

        printf("Case #%d: %d\n", i+1, dist[N] + 1);
    }
}
