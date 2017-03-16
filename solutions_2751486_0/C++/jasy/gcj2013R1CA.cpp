#include <iostream>
#include <string>

static long long solve()
{
    std::string L;
    int n;
    std::cin >> L >> n;
    const int N = L.size();
    int s=0;
    for(int i=n; i<=N; ++i)
    {
        for(int j=0; j<=N-i; ++j)
        {
            int ccl = 0;
            for(int k=0; k<i; ++k)
            {
                const char c = L[j+k];
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    ccl=0;
                else
                    if(++ccl>=n)
                        break;
            }
            if(ccl>=n)
                ++s;
        }
    }
    return s;
}

int main()
{
    int T;
    std::cin >> T;
    for (int i=1; i<=T; ++i)
        std::cout << "Case #" << i << ": " << solve() << '\n';
    return 0;
}
