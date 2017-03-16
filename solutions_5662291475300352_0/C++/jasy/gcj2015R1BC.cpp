#include <iostream>
#include <vector>

static auto solve()
{
    int N; std::cin >> N;
    struct T{ int D,M; };
    std::vector<T> h;
    for(int i=0; i<N; ++i)
    {
        int D,H,M; std::cin >> D >> H >> M;
        for(int j=0; j<H; ++j)
            h.push_back(T{D,M+j});
    }
    if(h.size()>2) return -1;
    if(h.size()<2) return 0;
    if(h[0].M*(360LL-h[1].D)>h[1].M*(720LL-h[1].D)) return 1;
    if(h[1].M*(360LL-h[0].D)>h[0].M*(720LL-h[0].D)) return 1;
    return 0;
};

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int T; std::cin >> T;
    for (int i=1; i<=T; ++i)
        std::cout << "Case #" << i << ": " << solve() << '\n';
}
