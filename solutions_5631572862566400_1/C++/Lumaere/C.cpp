#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> pii;

const int INF = 1<<25;
const int MAX = 1111;
bool seen[MAX];
int cmp[MAX];
int F[MAX];
std::vector<std::vector<int> > RF;
int in[MAX];
int N, orig;

std::deque<int> L;

void rec(int cur) {
    if(seen[cur]) return;
    seen[cur] = true;
    for(int neigh : RF[cur])
        rec(neigh);
    L.push_front(cur);
}

int rec2(int cur, int ignore) {
    int max = 0;
    for(int neigh : RF[cur]) {
        if(neigh == ignore) continue;
        max = std::max(max, rec2(neigh, ignore) + 1);
    }
    return max;
}

void assign(int u, int root) {
    if(cmp[u]) return;
    cmp[u] = root;
    assign(F[u], root);
}

int solve() {
    memset(cmp, 0, sizeof(cmp));
    memset(seen, false, sizeof(seen));
    L.clear();
    RF.clear();
    RF.resize(N + 1);
    for(int i = 1; i <= N; ++i)
        RF[F[i]].push_back(i);
    for(int i = 1; i <= N; ++i) rec(i);
    for(int i = 0; i < L.size(); ++i) assign(L[i], L[i]);

    // for(int i = 1; i <= N; ++i)
        // std::cout << i << ": " << cmp[i] << std::endl;

    int tot = 0, tot2 = 0;
    for(int i = 1; i <= N; ++i) {
        std::vector<int> component;
        for(int j = 1; j <= N; ++j)
            if(cmp[j] == i) component.push_back(j);
        if(component.size() <= 1) continue;
        if(component.size() > 2) {
            // std::cout << i << std::endl;
            // tot += component.size();
            tot = std::max(tot, (int)component.size());
            continue;
        } 

        // std::cout << component[0] << " " << component[1] << " " << i << " " << tot << std::endl;

        tot2 += 2 + rec2(component[0], component[1]) + rec2(component[1], component[0]);
        tot = std::max(tot, 2 + rec2(component[0], component[1]) + rec2(component[1], component[0]));
    }

    return std::max(tot, tot2);
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
    exit(1);
    return -1;
}

int main() {
    int CS;
    std::cin >> CS;
    for(int cs = 1; cs <= CS; ++cs) {
        std::cin >> N;
        for(int n = 1; n <= N; ++n)
            std::cin >> F[n];

        int ans = solve();
        // int ans = brute();
        std::cout << "Case #" << cs << ": " << ans << std::endl;
    }

    return 0;
}
