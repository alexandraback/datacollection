#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int T, J, P, S, K, N;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> J >> P >> S >> K;
        
        
        if(K >= 3)
        {
            N = J * P * S;
            cout << "Case #" << t << ": " << N << "\n";
            for(int i = 1; i <= J; i++)
                for(int j = 1; j <= P; j++)
                    for(int k = 1; k <= S; k++)
                        cout << i << " " << j << " " << k << "\n";
        }
        
        if(K == 1)
        {
            N = J * P;
            cout << "Case #" << t << ": " << N << "\n";
            for(int i = 1; i <= J; i++)
                for(int j = 1; j <= P; j++)
                    cout << i << " " << j << " " << (i+j) % S + 1<< "\n";
        }
        
        if(K == 2)
        {
            vector<int> cnt1, cnt2;
            for(int i = 1; i <= J; i++)
                for(int j = 1; j <= P; j++)
                {
                    int str = i * 100 + j * 10 + 1;
                    cnt1.push_back(str);
                    cnt2.push_back(str);
                }
            if(P > S - 1)
            {
                for(int i = 1; i <= J; i++)
                    for(int j = 1; j <= S; j++)
                    {
                        if(i == 1 && j == 1)continue;
                        int str = i * 100 + 10 + j;
                        cnt1.push_back(str);
                    }
            }
            else
            {
                if(S >= 2)
                    for(int i = 1; i <= J; i++)
                        for(int j = 1; j <= P; j++)
                        {
                            int str = i * 100 + j * 10 + 2;
                            cnt2.push_back(str);
                        }
            }
            if(cnt1.size() < cnt2.size())
                cnt1 = cnt2;
            cout << "Case #" << t << ": " << cnt1.size() << "\n";
            for(int i = 0; i < cnt1.size(); i++)
                cout << cnt1[i] / 100 << " " << (cnt1[i] % 100) / 10 << " " << cnt1[i] % 10 << "\n";
        }
    }
    return 0;
}
