#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int len_longest(int ind, int * vals, int max_n){
    int len = 0;
    for(int i = 1; i < max_n + 1; i++){
        if (i != vals[ind] && vals[i] == ind){
            int cur = 1 + len_longest(i, vals, max_n);
            if (cur > len){
                len = cur;
            }
        }
    }
    return len;
}

int main(){
    std::cout.sync_with_stdio(false);
    int t, n, c;
    std::string out;
    
    std::cin >> t;
    c = t;
    while (c > 0){
        std::cin >> n;
        int vals [n+1];
        bool touch [n+1];
        for (int i = 1; i < n + 1; i++){
            std::cin >> vals[i];
            touch[i] = 0;
        }
        
        int max_cycle = 1;
        int max_chain = 0;
        for (int i = 1; i < n + 1; i++){
            for (int j = 1; j < n + 1; j++){
                touch[j] = false;
            }
            int cur_cycle = 0;
            int next = i;
            while(!(touch[next])){
                touch[next] = true;
                next = vals[next];
                cur_cycle+=1;
            }
            if (next == i) {
                if (cur_cycle > max_cycle){
                    max_cycle = cur_cycle;
                }
                if (vals[vals[i]] == i && i < vals[i]){
                    // std::cout << "found cycle starting at " << i <<"\n";
                    max_chain += 2;
                    max_chain += len_longest(i, vals, n);
                    // std::cout << "\tlen to " << i << " is:" << len_longest(i, vals, n) << "\n";
                    max_chain += len_longest(vals[i], vals, n);
                    // std::cout << "\tlen to " << vals[i] << " is:" << len_longest(vals[i], vals, n) << "\n";
                }
            }
        }
        
        c--;
        std::cout << "Case #" << t-c << ": " << std::max(max_cycle, max_chain) << "\n";
        // for (int i = 1; i < n + 1; i++){
        //     std::cout << "\tlen to " << i << " is:" << len_longest(i, vals, n) << "\n";
        // }
    } 
}