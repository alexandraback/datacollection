#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, N, K;
string S;

void back(int a, int b, int c)
{
    if(K == 0)return;
    if(a == b)
    {
        K = K - 1;
        
        cout << S << " ";
        for(int k = 3; k <= 11; k++)
            cout << k << " ";
        cout << "\n";
    }
    else
    {
        for(int i = c; i < N - 1; i += 2)
        {
            if(S[i] == '1')continue;
            if(S[i] == '0')
            {
                S[i] = '1';
                back(a, b + 1, i + 1);
                S[i] = '0';
            }
        } 
    }
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":\n";
        
        
        cin >> N >> K;
        S.clear();
        for(int i = 0; i < N; i++)
            S.push_back('0');
        S[0] = S[N-1] = '1';
        
        for(int k = 0; K; k += 2)
            back(k, 0, 1);
    }
    return 0;
}
