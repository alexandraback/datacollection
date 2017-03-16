#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using std::endl;
using std::queue;
int n; 
int adjmat[1000][1000];
int seen[1000];

void dfs(int node) {
    if (seen[node]) {
        seen[node]++; return;
    }
    seen[node]++;
    for (int i = 0; i < n; i++) {
        if (adjmat[node][i]) {
            dfs(i);
        }
    }
}

int main() {
    int z; std::cin >> z;
    for (int t = 1; t <= z; t++) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int num; std::cin >> num;
            for (int j = 0; j < num; j++) {
                int temp; std::cin >> temp;
                adjmat[i][temp-1] = 1;
            }
            
        }
        std::cout << "Case #" << t << ": ";

        bool seenfail = false;
        for (int i = 0; i < n&&!seenfail; i++) {
            dfs(i);
            for (int i = 0; i < n && !seenfail; i++) {
                if (seen[i] > 1)
                    seenfail = true;
            }
            for (int i = 0; i < n; i++) {
                seen[i] = false;
            }

        }
        if (seenfail)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
        for (int i = 0; i < 1000; i++) {
               seen[i] = 0;
           for (int j = 0; j < 1000; j++) {
               adjmat[i][j] = 0;
           }
        }
    }
}
