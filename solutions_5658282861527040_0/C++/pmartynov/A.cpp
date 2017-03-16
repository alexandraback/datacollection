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
    int tests = 1;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int a, b, k;
        int counter = 0;
        scanf("%d %d %d", &a, &b, &k);
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    counter++;

        printf("Case #%d: %d\n", test, counter);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
