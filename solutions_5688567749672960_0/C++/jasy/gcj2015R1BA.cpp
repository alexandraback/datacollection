#include <iostream>
#include <vector>
#include <queue>

static auto solve()
{
    typedef long long T;
    T N; std::cin >> N;
    std::vector<bool> u(N+1,false);
    std::queue<T> q;
    q.emplace(1);
    for(int i=1; !q.empty(); ++i)
    {
        std::queue<T> qn;
        while(!q.empty())
        {
            auto v = q.front(); q.pop();
            if(v==N) return i;
            if(v>N || u[v]) continue;
            u[v]=true;
            qn.emplace(v+1);
            T w=0;
            while(v) w=w*10+v%10,v/=10;
            qn.emplace(w);
        }
        q.swap(qn);
    }
    return -1;
};

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int T; std::cin >> T;
    for (int i=1; i<=T; ++i)
        std::cout << "Case #" << i << ": " << solve() << '\n';
}
