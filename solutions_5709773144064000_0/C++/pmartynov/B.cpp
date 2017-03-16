#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iterator>
#include <complex>
#include <queue>
#include <cassert>
#include <sstream>
#include <cstdlib>

using namespace std;

double pi = acos((double) -1);

int main() {
    clock_t tStart = clock();
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);
        int optimal_farm_count = 0;
        double speed = 2, new_farm_time = 0;
        double best_time = x / speed;

        while (true) {
            new_farm_time += c / speed;
            double new_time = new_farm_time + x / (speed + f);
            if (new_time > best_time) {
                break;
            }
            else {
                best_time = new_time;
                speed += f;
            }
        }

        printf("Case #%d: %.8f\n", test, best_time);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
