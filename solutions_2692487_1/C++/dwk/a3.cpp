#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

int solve(long long start, std::vector<int> &data) {
    long long value[102][102] = {{}};
    int cost[102][102] = {{}};
    
    value[0][0] = start;
    for(int i = 1; i <= int(data.size()); i ++) {
        value[0][i] = -1;
    }
    
    for(int i = 1; i <= int(data.size()); i ++) {
        for(int j = 0; j <= int(data.size()); j ++) {
            value[i][j] = -1;
            
            // leave alone and/or add
            if(value[i-1][j] > data[i-1]) {  // leave alone
                value[i][j] = value[i-1][j] + data[i-1];
                cost[i][j] = cost[i-1][j];
            }
            else if(value[i-1][j] >= 2) {  // add
                long long v = value[i-1][j];
                int c = 0;
                while(v <= data[i-1]) {
                    v += (v-1);
                    c ++;
                }
                v += data[i-1];
                //double need = data[i-1] - value[i-1][j] + 1;
                //int c = std::ceil(need / (value[i-1][j]-1));
                
                value[i][j] = v;
                cost[i][j] = c + cost[i-1][j];
            }
            
            // remove
            if(j && value[i-1][j-1] >= 0) {
                value[i][j] = value[i-1][j-1];
                cost[i][j] = 1 + cost[i-1][j-1];
                //std::cout << "cost " << i << " " << j << " = " << cost[i][j] << std::endl;
            }
        }
    }
    
    int best = INT_MAX;
    for(int i = 0; i <= int(data.size()); i ++) {
        int s = data.size();
        if(value[s][i] >= 0 && cost[s][i] < best) {
            best = cost[s][i];
        }
    }
    
#if 0
    for(int i = 0; i <= int(data.size()); i ++) {
        for(int j = 0; j <= int(data.size()); j ++) {
            std::cout << value[i][j] << "(" << cost[i][j] << ") ";
        }
        std::cout << std::endl;
    }
#endif
    
    return best;
}

int main() {
    int cases;
    std::cin >> cases;
    for(int c = 0; c < cases; c ++) {
        int start, n;
        std::cin >> start >> n;
        std::vector<int> data;
        for(int i = 0; i < n; i ++) {
            int x;
            std::cin >> x;
            data.push_back(x);
        }
        
        std::sort(data.begin(), data.end());
        
        int answer = solve(start, data);
        std::cout << "Case #" << (c+1) << ": " << answer << std::endl;
    }
    
    return 0;
}
