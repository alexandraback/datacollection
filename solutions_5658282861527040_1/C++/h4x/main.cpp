#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MaxLen = 40;
const int MaxMsk = 10;

long long A, B, K;
long long m[MaxLen][MaxMsk];

long long f(int len, int msk)
{
    long long result = 0LL;
    int nlen = len - 1;
    
    if(len == 0)
    {
        if(msk == 7) return 1;
        else return 0;
    }
    
    if(m[len][msk] >= 0)
        return m[len][msk];     // memorilize
    
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int r = i & j;
            if((msk & 1) == 0 && (A >> nlen & 1) < i) continue;
            if((msk >> 1 & 1) == 0 && (B >> nlen & 1) < j) continue;
            if((msk >> 2 & 1) == 0 && (K >> nlen & 1) < r) continue;
            
            int nmsk = msk;
            if((A >> nlen & 1) > i) nmsk |= 1;
            if((B >> nlen & 1) > j) nmsk |= 2;
            if((K >> nlen & 1) > r) nmsk |= 4;
            
            result += f(nlen, nmsk);
        }
    }
    
    m[len][msk] = result;
    return result;
}

int main()
{
    int T;
    cin >> T;
    
    for(int c=0; c<T; c++)
    {
        cin >> A >> B >> K;
        memset(m, -1, sizeof(m));
        
        long long result = f(32, 0);
        printf("Case #%d: %lld\n", c+1, result);
    }
    return 0;
}

