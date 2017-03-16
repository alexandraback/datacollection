#include <iostream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>
#include <stack>
#include <list>

const int C = 500;
const int F = 4;
const int X = 2000;

std::pair<int, int> naomiWins(int N, std::vector<double> &naomi, std::vector<double> &ken)
{
    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());
    
    std::list<double> naomiWorst(naomi.begin(), naomi.end());
    std::list<double> kenBest(ken.begin(), ken.end());
    
    int worstCase = 0, bestCase = 0;
    for (std::list<double>::iterator it = naomiWorst.begin(); it != naomiWorst.end(); ++it) {
        bool kenWon = false;
        for (std::list<double>::iterator it2 = kenBest.begin(); it2 != kenBest.end(); ++it2) {
            if (*it2 > *it) {
                kenBest.erase(it2);
                kenWon = true;
                break;
            }
        }
        if (!kenWon) {
            worstCase++;
            kenBest.erase(kenBest.begin());
        }
    }
        
    std::list<double> naomiBest(naomi.begin(), naomi.end());
    std::list<double> kenWorst(ken.begin(), ken.end());
    for (std::list<double>::reverse_iterator it = kenWorst.rbegin(); it != kenWorst.rend(); ++it) {
        if (naomiBest.back() < *it) {
            naomiBest.pop_front();
        } else {
            bestCase++;
            naomiBest.pop_back();
        }
    }
    
    return std::make_pair(bestCase, worstCase);
}

void solveCase()
{
    int N;
    std::cin >> N;
    std::vector<double> naomi(N), ken(N);
    for (int i = 0; i < N; ++i)
        std::cin >> naomi[i];
    for (int i = 0; i < N; ++i)
        std::cin >> ken[i];
    std::pair<int, int> result = naomiWins(N, naomi, ken);
    std::cout << result.first << " " << result.second << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solveCase();
    }
    
    return 0;
}