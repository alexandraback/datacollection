#include <iostream>
#include <vector>
#include <algorithm>

static long long solve ()
{
    long long E,R;
    int N;
    std::cin >> E >> R >> N;
    std::vector<int> v(N);
    for(auto& vr: v)
        std::cin >> vr;
    std::vector<long long> dp(E+1);
    for(int i=0; i<N; ++i)
    {
        std::vector<long long> dpn(E+1);
        for(int j=0; j<=E; ++j)
        {
            for(int k=0; k<=j; ++k)
            {
                const int n = j-k+R;
                if(n<=E)
                    dpn[n] = std::max(dpn[n],dp[j]+k*v[i]);
            }
        }
        dp.swap(dpn);
    }
    long long gain = 0;
    for(int i=0; i<=E; ++i)
        gain=std::max(gain,dp[i]);
    return gain;
}

int main ()
{
    int T;
    std::cin >> T;
    for (int i=1; i<=T; ++i) {
        std::cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
