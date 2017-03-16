#include <iostream>

using namespace std;

bool add1(int* num, int N, int M)
{
    if (N == 0) return true;
    num[0] += 1;
    for (int n = 0; n < N; ++n)
    {
        if (num[n] > M)
        {
            num[n] = 2;
            add1(num+1, N-1, M);
            return false;
        }
    }
    return false;
}

bool can(int* num, int N, int k)
{
    int i = 0;
    while (i < (1<<N))
    {
        int kk = 1;
        for (int n = 0; n < N; ++n)
        {
            if (i & (1<<n)) kk *= num[n];
        }
        if (kk == k) return true;
        ++i;
    }
    return false;
}

int main()
{
    int tcs;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; ++tc)
    {
        cout << "Case #" << tc << ": " << endl;
        
        int R, N, M, K;
        cin >> R >> N >> M >> K;
        
        for (int r = 0; r < R; ++r)
        {
            int ks[K];
            for (int n = 0; n < K; ++n)
            {
                cin >> ks[n];
            }
            int num[N];
            for (int n = 0; n < N; ++n)
                num[n] = 2;
            
            for (int n = 0; n < K; ++n)
            {
                if (!can(num, N, ks[n]))
                {
                    if (add1(num, N, M)) break;
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