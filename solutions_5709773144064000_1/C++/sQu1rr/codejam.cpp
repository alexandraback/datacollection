#include <iostream>
#include <iomanip>

int main() {
    int size;
    std::cin >> size;

    for(int i = 0; i < size; ++i) {
        double C, F, X;
        std::cin >> C >> F >> X;

        double time = 0.0;
        double step = 2.0;

        double timeC = C / step;
        double timeX = X / step;
        do {
            double nstep = step + F;
            double timeNX = X / nstep;
            if(timeX < timeC + timeNX) {
                time += timeX;
                break;
            }
            else time += timeC;

            step = nstep;
            timeX = timeNX;
            timeC = C / step;
        } while(true);
        
        std::cout << "Case #" << i + 1 << ": ";
        std::cout << std::setprecision(7) << std::fixed << time << std::endl;
    }
}
