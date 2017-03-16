#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int powOfDigits(int a)
{
    int ret = 1;
    while (a) {
        ret *= 10;
        a /= 10;
    }
    return ret;
}

int digits = 0;

int rotate(int a) {
    int last = a % 10;
    a /= 10;
    return last * digits + a;
}

int main()
{
    int testcases;
    FILE *fin;
    fin = fopen("C-large.in", "r");
    FILE *fout;
    fout = fopen("C.txt", "w");
    fscanf(fin, "%d", &testcases);
    for (int tc=0; tc<testcases; ++tc) {
        int A, B;
        fscanf(fin, "%d%d", &A, &B);
        digits = powOfDigits(A / 10);
        int ans = 0;
        for (int i=A; i<=B; ++i) {
            int p = i;
            do {
                if (p % 10 == 0) {
                    p = rotate(p);
                    //cout << "digit " << i << endl;
                    if (p == i) break;
                    else continue;
                } else {
                    p = rotate(p);
                    if (p > i && p <= B && p >= A) {
                        //cout << "new " << i << endl;
                        ++ans;
                    }
                }
            } while (p != i);
        }
        
        fprintf(fout, "Case #%d: %d\n", tc+1, ans);
    }
    
    return 0;
}