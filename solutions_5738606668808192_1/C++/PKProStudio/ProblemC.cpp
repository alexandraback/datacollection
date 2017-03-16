#include <iostream>
#include <fstream>
#include <string>
#include <mpir.h>
using namespace std;

string toBin(int n, int length) {
    string bin = "";
    while (bin.size() < length) {
        string next = (n % 2 == 0)?"0":"1";
        bin.insert(0, next);
        n /= 2;
    }
    return bin;
}

long long findDivisor(mpz_t& n) {
    if (mpz_probab_prime_p(n, 10)) return 0;
    mpz_t s;
    mpz_init(s);
    mpz_sqrt(s, n);
    mpz_t i;
    mpz_init_set_si(i, 2);
    int x = 0;
    while (mpz_cmp(s, i)) {
        if (mpz_divisible_p(n, i)) return mpz_get_si(i);
        mpz_add_ui(i, i, 1);
        x++;
        if (x > 1000000) break;
    }
    return 0;
}

int main() {
    ifstream ifs("C-large.in");
    ofstream ofs("C-large.out");
    int num;
    ifs >> num;
    for (int i = 1; i <= num; i++) {
        int n, j;
        ifs >> n >> j;
        ofs << "Case #" << i << ":\n";
        int found = 0;
        int current = 0;
        n -= 2;
        while (found < j) {
            string next = '1' + toBin(current, n) + '1';
            long long divs[9] = {};
            bool isJam = true;
            for (int k = 2; k <= 10; k++) {
                mpz_t converted;
                mpz_init_set_str(converted, next.c_str(), k);
                divs[k - 2] = findDivisor(converted);
                if (divs[k - 2] == 0) {
                    isJam = false;
                    break;
                }
            }
            if (isJam) {
                found++;
                ofs << next;
                for (int l = 0; l < 9; l++) ofs << ' ' << divs[l];
                ofs << endl;
            }
            current++;
        }
    }
}