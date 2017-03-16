#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

long long numbers[1000];

struct Sum {
    long long value;
    long long mask;
    bool operator<(const Sum& s) const {
        if (value != s.value) {
            return value < s.value;
        } else {
            return mask < s.mask;
        }
    }
};

int randN(int k) {
    return (int) (rand() / (RAND_MAX + 1.0) * k);
}

void randOrder(int n) {
    for (int i = 0; i < n; i++) {
        int j = randN(i + 1);
        swap(numbers[i], numbers[j]);
    }
}

void printSet(long long s) {
    bool first = true;
    for (int i = 0; i < 63; i++) {
        if (s & ((long long) 1 << i)) {
            if (!first) printf(" ");
            printf("%lli", numbers[i]);
            first = false;
        }
    }
    printf("\n");
}

int main() {
    int nCases;
    scanf("%d", &nCases);
    vector<Sum> sums;
    int HALF_RAND_MAX = RAND_MAX / 2;

    for (int iCase = 1; iCase <= nCases; iCase++) {
        int n;
        long long allSum = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &numbers[i]);
            allSum += numbers[i];
        }

        int SET_SIZE = min(n, 23);
        int NUM_SUMS = (int) sqrt(allSum + 50);
        sums.resize(NUM_SUMS);
        bool solutionFound = false;
        long long set1 = -1, set2 = -1;

        while (!solutionFound) {
            randOrder(n);
            cerr << "iCase=" << iCase << " NUM_SUMS=" << NUM_SUMS << endl;
            for (int i = 0; i < NUM_SUMS; i++) {
                long long bit = 1;
                sums[i].mask = 0;
                for (int j = 0; j < SET_SIZE; j++) {
                    if (rand() >= HALF_RAND_MAX) {
                        sums[i].value += numbers[j];
                        sums[i].mask += bit;
                    }
                    bit = bit + bit;
                }
            }
            sort(sums.begin(), sums.end());
            for (int i = 0; i < NUM_SUMS - 1; i++) {
                if (sums[i].value == sums[i + 1].value && sums[i].mask != sums[i + 1].mask) {
                    set1 = sums[i].mask;
                    set2 = sums[i + 1].mask;
                    solutionFound = true;
                }
            }
        }

        printf("Case #%i:\n", iCase);
        printSet(set1);
        printSet(set2);
    }
    return 0;
}
