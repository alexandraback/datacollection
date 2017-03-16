#include <iostream>
#include <algorithm>
#include <vector>

int fair(std::vector<double> na, std::vector<double> ke) {
    auto it1 = na.begin();
    auto it2 = ke.begin();

    int count = na.size();
    while(it1 != na.end() && it2 != ke.end()) {
        if(*it2 > *it1) {
            count--;
            it1++;
        }
        it2++;
    }
    return count;
}

int unfair(const std::vector<double> & na, const std::vector<double> & ke) {
    auto it1 = na.begin();
    auto rit1 = na.rbegin();
    auto rit2 = ke.rbegin();

    int count = 0;
    while(rit1 != na.rend() && rit2 != ke.rend()) {
        if(*rit1 > *rit2) {
            count++;
            rit1++;
        } else {
            it1++;
        }
        rit2++;
    }
    return count;
}

int main() {
    int size;
    std::cin >> size;

    for(int i = 0; i < size; ++i) {
        int sz;
        std::cin >> sz;

        double temp;
        std::vector<double> na, ke;
        for(int j = 0; j < sz; ++j) {
            std::cin >> temp;
            na.push_back(temp);
        }
        for(int j = 0; j < sz; ++j) {
            std::cin >> temp;
            ke.push_back(temp);
        }

        std::sort(na.begin(), na.end());
        std::sort(ke.begin(), ke.end());

        int x = unfair(na, ke);
        int y = fair(na, ke);
        
        std::cout << "Case #" << i + 1 << ": ";
        std::cout << x << " " << y << std::endl;
    }
}
