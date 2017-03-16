#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
long long K, C, S;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> K >> C >> S;
        
        cout << "Case #" << t << ": ";
        
        long long optimum_S = K / C + ((K % C) ? 1 : 0);
        
        if(optimum_S > S)
        {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        
        for(long long i = 0; i < optimum_S; i++)
        {
            //Horner method
            long long value = 0;
            for(long long j = i * C; j < i*C + C; j++)
            {
                if(j == K)break;
                value = value * K + j;
            }
            cout << value + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
