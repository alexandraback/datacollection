#include <iostream>
#include <fstream>
#include <string>
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

long long findDivisor(long long n) {
    long long s = sqrt(n);
    for (long long i = 2; i <= s; i++) {
        if (n % i == 0) return i;
    }
    return 0;
}

int main() {
    ifstream ifs("C-small-attempt0.in");
    ofstream ofs("C-small-attempt0.out");
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
                divs[k - 2] = findDivisor(stoll(next, nullptr, k));
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