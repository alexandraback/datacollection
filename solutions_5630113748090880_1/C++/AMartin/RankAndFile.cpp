#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

const int max_n = 2501; 
int main(){
    std::cout.sync_with_stdio(false);
    int t, n, c;
    int vals [max_n];
    std::string out;
    
    std::cin >> t;
    c = t;
    while (c > 0){
        std::cin >> n;
        for (int i = 1; i < max_n; i++){
            vals[i] = 0;
        }
        int next;
        for (int i = 0; i < 2*(n*n)-n; i++){
            std::cin >> next;
            vals[next] += 1;
        }
        
        std::vector<int> list;
        for (int i = 1; i < max_n; i++){
            if (vals[i]%2){
                list.push_back(i);
            }
        }
        std::sort(list.begin(), list.end());
        
        c--;
        std::cout << "Case #" << t-c << ": ";
        for (int i = 0; i < list.size(); i++){
            std::cout << list[i];
            if (i < list.size() - 1){
                std:: cout << " ";
            } else {
                std:: cout << "\n";
            }
        }
    } 
}