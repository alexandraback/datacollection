#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "mylib.h"
using namespace std;

void solve_case();

/**
 * Reads the input from stdin and prints the result
 */
int main(int argc, char** argv)
{
    int num_tests;
    cin >> num_tests;

    for (int i = 0; i < num_tests; ++i) {
        printf("Case #%d: ", i+1);
        solve_case();
    }

    return 0;
}

int bit(int a, int pos)
{
    return (a >> pos) & 1;
}

void solve_case()
{
    int A, B, K;
    cin >> A;
    cin >> B;
    cin >> K;

    int count = 0;
    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j)
            if ((i & j) < K)
                count++;
    cout << count << endl;
}
