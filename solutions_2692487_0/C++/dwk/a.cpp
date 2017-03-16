#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solve(int current, std::vector<int> &data, int index) {
    while(index < int(data.size())) {
        if(current > data[index]) {
            current += data[index];
            index ++;
        }
        else break;
    }
    
    if(index >= int(data.size())) return 0;
    
    // remove
    int remove = 1 + solve(current, data, index + 1);
    
    if(current <= 1) return remove;
    
    // add
    int add = 1 + solve(current + (current-1), data, index);
    
    if(remove < add) return remove;
    else return add;
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
        
        int answer = solve(start, data, 0);
        std::cout << "Case #" << (c+1) << ": " << answer << std::endl;
    }
    
    return 0;
}
