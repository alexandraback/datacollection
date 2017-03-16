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

int n;
int numbers[1000];
int sum;
int partialSums[2000005];

void printSet(int s) {
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (s & (1 << i)) {
            if (!first) printf(" ");
            printf("%i", numbers[i]);
            first = false;
        }
    }
    printf("\n");
}

int main() {
    int nCases;
    scanf("%d", &nCases);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        fill(partialSums, partialSums + 2000005, -1);
        sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
            sum += numbers[i];
        }
        int nChoices = 1 << n;
        int set1 = -1, set2 = -1;
        for (int mask = 1; mask < nChoices; mask++) {
            int bit = 1;
            int partialSum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & bit) partialSum += numbers[i];
                bit <<= 1;
            }
            if (partialSums[partialSum] != -1) {
                set1 = partialSums[partialSum];
                set2 = mask;
                break;
            }
            partialSums[partialSum] = mask;
        }
        printf("Case #%i:\n", iCase);
        if (set1 == -1) {
            printf("Impossible\n");
        } else {
            printSet(set1);
            printSet(set2);
        }
    }
    return 0;
}
