#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {
        
    FILE *f = fopen("B-large.in", "r");
    FILE *out = fopen("out.txt", "w");

    int numberOfCases;
    fscanf(f, "%d\n", &numberOfCases);

    for (int caseNum = 1; caseNum <= numberOfCases; ++caseNum) {
        int N, S, p;
        fscanf(f, "%d", &N);
        fscanf(f, "%d", &S);
        fscanf(f, "%d", &p);
        int result = 0;

        vector<int> possib;
        for (int googleNum = 0; googleNum < N; ++googleNum) {
            int total;
            
            fscanf(f, "%d", &total);
            int modThree = total % 3;
            
            if (modThree == 1 && floor(total/3.0) +1 >= p) {
                ++result;
            } else if (modThree == 0) {
                if (floor(total / 3.0) >= p) {
                    ++result;
                } else {
                    if (total >= 3) {
                        possib.push_back(floor((total - 3) / 3.0) + 2);
                    }
                }
            } else if (modThree == 2) {
                if (floor(total / 3.0) + 1 >= p) {
                    ++result;
                } else {
                    if (total >= 2) {
                        possib.push_back(floor((total - 2) / 3.0) + 2);
                    }
                }
            }
        }

        sort(possib.begin(), possib.end());
        reverse(possib.begin(), possib.end());

        int ind = 0;
        while (ind < possib.size() && possib[ind] >= p && ind < S) {
            ++result;
            ++ind;
        }

        fprintf(out, "Case #%d: %d\n", caseNum, result);
    }

    fclose(f);
    fclose(out);

    int a = 1;
}