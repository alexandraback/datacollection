/*
Idea: note that n^(2i+1) \equiv -1 (mod n+1). Therefore, for base 2 to 10, 10...01
and 110...0 are both divisible by i+1. Hence this O(J) solution for even N.
For simplicity, output numbers with blocks of length 2 only.
This works because 2^7 = 128 > 50, and 2^15 > 2^9 = 512 > 500.
Otherwise combinations other than 11 must be used to get the required number of strings.
For string construction, make use of the bijection between binary string of length n and subsets of a set with n elements.
*/

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int t, n, J;
    cin >> t >> n >> J;
    int mask[] = {1,2,4,8,16,32,64,128,256};
    string div = " 3 4 5 6 7 8 9 10 11";
    int upper = n / 2 - 1;
    cout << "Case #1:" << endl;
    for (int i = 1; i <= J; ++i) {
        cout << 1;
        for (int j = 0; j < upper; ++j)
            cout << ((i-1)&mask[j]?"11":"00");
        cout << 1 << div << endl;
    }
    return 0;
}
