#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {
        
    FILE *f = fopen("C-small-attempt0.in", "r");
    FILE *out = fopen("out.txt", "w");

    int numberOfCases;
    fscanf(f, "%d\n", &numberOfCases);

    for (int caseNum = 1; caseNum <= numberOfCases; ++caseNum) {
        int A, B;
        fscanf(f, "%d", &A);
        fscanf(f, "%d\n", &B);
        vector<int> digits;
        int result = 0;

        for (int n = max(11, A); n < B; ++n) {
            set<int> ms;
            
            int numOfDigits;
            for (numOfDigits = 1; numOfDigits < 7; ++numOfDigits) {
                if (n < pow(10.0, numOfDigits))
                    break;
            }

            for (int startPos = 1; startPos < numOfDigits; ++startPos) {
                int buf = pow(10.0, numOfDigits - startPos);
                int m = n % buf;
                m = m * pow(10.0, startPos);
                m = m + n / buf;
                if (m > n && m <= B) {
                    ms.insert(m);
                }
            }
            
            result += ms.size();
        }

        fprintf(out, "Case #%d: %d\n", caseNum, result);
    }

    fclose(f);
    fclose(out);

}