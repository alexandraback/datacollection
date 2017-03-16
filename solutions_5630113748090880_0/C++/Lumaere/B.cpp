#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> pii;

const int MAX = 55;
int a[MAX<<1][MAX];
int occ[5555];
int N;

void solve() {
    memset(occ, 0, sizeof(occ));
    for(int i = 0; i < 2 * N - 1; ++i)
        for(int j = 0; j < N; ++j)
            occ[a[i][j]]++;

    for(int i = 0; i <= 2500; ++i)
        if(occ[i] & 1)
            std::cout << " " << i;
    std::cout << std::endl;
}

int main() {
    int CS;
    std::cin >> CS;
    for(int cs = 1; cs <= CS; ++cs) {
        std::cin >> N;
        for(int n = 0; n < 2 * N - 1; ++n)
            for(int i = 0; i < N; ++i)
                std::cin >> a[n][i];


        std::cout << "Case #" << cs << ":";
        solve();
    }

    return 0;
}
