#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back

ifstream in("C-large-1.in");
ofstream out("output.txt");

int main()
{
    vector<long long> a({0, 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002,1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002});
    cerr << a.size() << endl;
    int t;
    in >> t;
    for (int z = 0; z < t; ++z) {
        long long l, r;
        in >> l >> r;
        int ans = 0;
        for (auto x: a) {
            if (x * x >= l && x * x <= r) {
                ++ans;
            }
        }
        out << "Case #" << z + 1 << ": " << ans << endl;
    }

    return 0;
}
