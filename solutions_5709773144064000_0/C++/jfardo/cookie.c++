#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdio.h>

double DeliciousCookieTime(double c, double f, double x)
{
    // Minimum time and rate with no Farms
    double cookies_per_second = 2;
    double min_time = x/cookies_per_second; 

    unsigned num_farms = 0;
    double farm_time = 0;
    while (1) {
        farm_time += c/cookies_per_second; 
        cookies_per_second += f;
        double new_time = x/cookies_per_second + farm_time;
        if (new_time < min_time) {
            min_time = new_time;
        } else {
            break;
        }
    }
    return min_time;
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cout << "Missing file containing input\n";
        return -1;
    }

    std::ifstream istr(argv[1]);

    // Read in the number of test cases.
    unsigned T;
    istr >> T;

    for (unsigned i = 1; i <= T; ++ i) {
        double c = 0;
        double f = 0;
        double x = 0;

        istr >> c;
        istr >> f;
        istr >> x;
        
        printf("Case #%d: %.7f\n", i, DeliciousCookieTime(c, f, x));
    }

    return 0;
}
