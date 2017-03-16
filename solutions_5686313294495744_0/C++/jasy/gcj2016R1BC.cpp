#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

static auto solve()
{
    int N; std::cin >> N;
    std::map<std::string, unsigned> m;
    unsigned s1=0, s2=0;
    std::vector<unsigned> v1(N);
    std::vector<unsigned> v2(N);
    for(int i=0; i<N; ++i)
    {
        std::string w1,w2;
        std::cin >> w1 >> w2;
        if(!m.count(w1)) m[w1]=m.size();
        v1[i] = m[w1];
        s1 |= 1 << v1[i];
        if(!m.count(w2)) m[w2]=m.size();
        v2[i] = m[w2];
        s2 |= 1 << v2[i];
    }
    int c=0;
    for(unsigned b=0; b<(1<<N); ++b)
    {
        unsigned t1=0, t2=0, u1=0, u2=0;
        for(int i=0; i<N; ++i)
            if(b&(1<<i)) t1 |= 1 << v1[i], t2 |= 1<< v2[i];
            else         u1 |= 1 << v1[i], u2 |= 1<< v2[i];
        if((t1&u1)==t1 && (t2&u2)==t2 && !(t1&s2) && !(t2&s1))
            c=std::max(c,__builtin_popcount(b));
    }
    return c;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int T; std::cin >> T;
    for (int i=1; i<=T; ++i)
        std::cout << "Case #" << i << ": " << solve() << '\n';
}
