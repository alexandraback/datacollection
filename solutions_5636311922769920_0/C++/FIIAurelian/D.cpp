#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, K, C, S;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> K >> C >> S;
        
        cout << "Case #" << t << ": ";
        for(int k = 1; k <= K; k++)
            cout << k << " ";
        cout << "\n";
    }
    return 0;
}
