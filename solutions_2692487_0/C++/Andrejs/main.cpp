#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input-file>" << endl;
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        cerr << "Couldn't open file" << endl;
        return 2;
    }
    int T = 0;
    if (!fscanf(fp, "%d", &T))
        cerr << "File not valid" << endl;

    for (int case_no = 0; case_no < T; ++case_no) {
        unsigned long long int A, N;
        std::vector<int> motes;
        fscanf(fp, "%llu %llu", &A, &N);
        motes.resize(N);
        for (int i = 0; i < N; ++i) {
            fscanf(fp, "%d", &motes[i]);
        }
        std::sort(motes.begin(), motes.end());
        int result = 0;
        int smallest_alternative = 2000000000;
        // 3 5
        // 11 20 22 60 100
        for (int i = 0; i < N; ++i) {
            if (motes[i] < A) {
                A += motes[i];
            } else {
                // Problem!
                long long int difference = motes[i] - A + 1;
                int moves_to_compensate = 0;
                unsigned long long int largest_edible = A-1;
                while ((difference > 0) && (largest_edible > 0)) {
                    difference -= largest_edible;
                    ++moves_to_compensate;
                    largest_edible *= 2;
                }
                if (smallest_alternative > result + (N - i))
                    smallest_alternative = result + (N - i);
                if ((moves_to_compensate > (N - i)) || (largest_edible <= 0)) {
                    // if it is more expensive to add than remove or if largest edible is 0
                    result += (N - i);
                    break;
                } else {
                    result += moves_to_compensate;
                    A = largest_edible + 1 + motes[i];
                }
            }
        }
        printf("Case #%d: %d\n", case_no + 1, (result < smallest_alternative ? result : smallest_alternative));
    }

    return 0;
}
