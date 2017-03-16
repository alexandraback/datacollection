#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 12;
constexpr int M = 8;
constexpr int K = 12;

bool add1(int* num)//, int N, int M)
{
    int s = 0;
    for (int n = N-1; n >= 0; --n)
        if (num[n] < num[n-1]) {s = n; break;}
    
    if (num[s] == M) return true;
    
    num[s] += 1;
    for (int n = s+1; n < N; ++n)
        num[n] = 2;
    
    return false;
}

bool can(int* num/*, int N*/, int k)
{
    int kk = 1;
    for (int n = 0; n < N; ++n)
        kk *= num[n];
    if (kk < k) return false;
    int i = (1<<N)-1;
    while (i > 0)
    {
        int kk = 1;
        for (int n = 0; n < N; ++n)
        {
            kk *= 1+((i & (1<<n))>>n) * (num[n]-1);
        }
        if (kk == k) return true;
        --i;
    }
    return false;
}

int main(int argc, char*argv[])
{
    int tcs;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; ++tc)
    {
        if (argc == 1) cout << "Case #" << tc << ": " << endl;
        
        int R, nN, nM, nK;
        cin >> R >> nN >> nM >> nK;
        
        for (int r = 0; r < R; ++r)
        {
            int ks[K];
            for (int n = 0; n < K; ++n)
            {
                cin >> ks[n];
            }
            if (r < 400*(argc-1)) continue;
            if (r >= 400*(argc)) return 0;
            
            std::sort(ks, ks+K);
            std::reverse(ks, ks+K);
            int num[N];
            for (int n = 0; n < N; ++n)
                num[n] = 2;
            
            for (int n = 0; n < K; ++n)
            {
                if (!can(num,/* N,*/ ks[n]))
                {
                    if (add1(num/*, N, M*/)) break;
                    n = -1;
                }
            }
            
            for (int n = 0; n < N; ++n)
                cout << num[n];
            
            cout << endl;
        }
        
    }
    return 0;
}