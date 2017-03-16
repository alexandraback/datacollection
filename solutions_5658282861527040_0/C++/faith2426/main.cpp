#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        int A, B, K;
        ifs >> A >> B >> K;

        int count = 0;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                int r = (i & j);
                if (r < K) {
                    ++count;
                }
            }
        }

        ofs << "Case #" << t << ": " << count << endl;
    }

    return 0;
}
