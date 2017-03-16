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

const int INF = 1<<25;
const int MAX = 1111;
int F[MAX];
int in[MAX];
int N, orig;

int solve() {
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= N; ++i)
        in[F[i]]++;

    for(int i = 1; i <= N; ++i)
        std::cout << i << ": " << F[i] << " " << in[i] << std::endl;

    return 0;
}

unsigned int next(unsigned int v) {
    unsigned int t = v | (v - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

int brute() {
    for(int n = N; n >= 2; --n) {
        int msk = (1<<n) - 1;
        do {
            std::vector<int> p;
            for(int i = 0; i < N; ++i) 
                if(msk & (1<<i)) 
                    p.push_back(i + 1);

            do {
                p.insert(p.begin(), p.back());
                p.push_back(p[1]);

                for(int i = 1; i <= n; ++i)
                    if(F[p[i]] != p[i - 1] && F[p[i]] != p[i + 1]) goto loop;

                return n;
loop:;
                p.erase(p.begin());
                p.pop_back();
            } while(std::next_permutation(p.begin(), p.end()));

        } while((msk = next(msk)) <= (1<<N) - 1);
    }
}

int main() {
    int CS;
    std::cin >> CS;
    for(int cs = 1; cs <= CS; ++cs) {
        std::cin >> N;
        for(int n = 1; n <= N; ++n)
            std::cin >> F[n];

        int ans = brute();
        std::cout << "Case #" << cs << ": " << ans << std::endl;
    }

    return 0;
}
