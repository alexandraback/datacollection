#include <iostream>
#include <iomanip>

const int C = 500;
const int F = 4;
const int X = 2000;

double cookieStrategy(double C, double F, double X)
{
    int farmCount = 0;
    double time = 0.0;
    while (true) {
        double cookieProd = 2.0 + farmCount*F;
        double timeToFarm = C/cookieProd;
        double timeToWin = X/cookieProd;
        double timeToFarmWin = timeToFarm + X/(cookieProd + F);
        if (timeToFarmWin < timeToWin) {
            time += timeToFarm;
            farmCount++;
        } else {
            return time + timeToWin;
        }
    }
}

void solveCase()
{
    double C, F, X;
    std::cin >> C >> F >> X;
    std::cout << std::fixed;
    std::cout << std::setprecision(12) << cookieStrategy(C, F, X) << std::endl;
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