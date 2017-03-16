#include <iostream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>
#include <stack>

const int C = 500;
const int F = 4;
const int X = 2000;

int zeroCost(int R, int C, const std::vector<int> &field, int x, int y)
{
    int result = 0;
    for (int j = std::max(y - 1, 0); j <= std::min(y + 1, R - 1); ++j)
        for (int i = std::max(x - 1, 0); i <= std::min(x + 1, C - 1); ++i)
            result += field[i + j*C] != 0 ? 1 : 0;
    return result;
}

void printField(int R, int C, const std::vector<int> &field)
{
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j == 0 && i == 0)
                std::cout << "c";
            else if (field[j + i*C])
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

bool solveSweeper(int R, int C, int M, const std::vector<int> &startField,
    const std::stack<std::pair<int, int> > &startQueue, int freeCount)
{
    if (freeCount == M) {
        printField(R, C, startField);
        return true;
    }

    std::vector<int> field(startField);
    std::stack<std::pair<int, int> > candidateQueue(startQueue);
    
    while (!candidateQueue.empty()) {
        int x, y;
        x = candidateQueue.top().first;
        y = candidateQueue.top().second;
        candidateQueue.pop();
        if (freeCount - zeroCost(R, C, field, x, y) >= M) {
            int newCount = freeCount;
            std::stack<std::pair<int, int> > newQueue(candidateQueue);
            for (int j = std::max(y - 1, 0); j <= std::min(y + 1, R - 1); ++j) {
                for (int i = std::max(x - 1, 0); i <= std::min(x + 1, C - 1); ++i) {
                    if (field[i + j*C] != 0) {
                        newQueue.push(std::make_pair(i, j));
                        newCount--;
                        field[i + j*C] = 0;
                    }
                }
            }
            
            if (solveSweeper(R, C, M, field, newQueue, newCount)) {
                return true;
            } else {
                field = startField;
            }
        }
    }
    return false;
}

void solveCase()
{
    int R, C, M;
    std::cin >> R >> C >> M;
    std::vector<int> field(R*C, 1);
    field[0] = 0;
    std::stack<std::pair<int, int> > candidateQueue;
    candidateQueue.push(std::make_pair(0, 0));
    if (!solveSweeper(R, C, M, field, candidateQueue, R*C - 1))
        std::cout << "Impossible" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ":\n";
        solveCase();
    }
    
    return 0;
}