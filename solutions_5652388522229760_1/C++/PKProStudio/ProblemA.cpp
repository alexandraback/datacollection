#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main() {
    ifstream ifs("A-large.in");
    ofstream ofs("A-large.out");
    int num;
    ifs >> num;
    for (int i = 1; i <= num; i++) {
        int n;
        ifs >> n;
        ofs << "Case #" << i << ": ";
        if (n == 0) {
            ofs << "INSOMNIA\n";
            continue;
        }
        string seen = "0000000000";
        int counter = 1;
        while (true) {
            int tempN = counter * n;
            while (tempN > 0) {
                seen[tempN % 10] = '1';
                tempN /= 10;
            }
            if (seen == "1111111111") break;
            counter++;
        }
        ofs << counter * n << endl;
    }
}