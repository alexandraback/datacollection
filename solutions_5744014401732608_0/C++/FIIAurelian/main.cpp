#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

int T, B, SOL[52][52];
ll M, maxim;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> B >> M;
        cout << "Case #" << t << ": ";
        
        maxim = B * (B-1) / 2;
        if(M > maxim)
            cout << "IMPOSSIBLE\n";
        else
            cout << "POSSIBLE\n";
        
        if(M > maxim)continue;
        
        for(int i = 1; i <= B; i++)
            for(int j = i+1; j <= B; j++)
                SOL[i][j] = 1;
        int i = B - 1;
        while(maxim > M)
        {
            if(maxim - i >= M)
            {
                SOL[i][B] = 0;
                for(int j = 1; j < i; j++)
                    SOL[j][i] = 0;
                maxim = maxim - i;
            }
            i = i - 1;
        }
        for(int i = 1; i <= B; i++)
        {
            for(int j = 1; j <= B; j++)
            {
                cout << SOL[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
