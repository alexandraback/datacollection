#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
string S;

int compute_solution(string X)
{
    int result = 0;
    while(X.size() > 0)
    {
        while(X.size() > 0 && X[X.size() - 1] == '+')
            X.erase(X.size() - 1);
        
        if(X.size() > 0)
        {
            int move = 0;
            for(int i = 0; i < X.size(); i++)
            {
                if(X[i] == '+')
                {
                    X[i] = '-';
                    move = 1;
                }
                else
                    break;
            }
            result = result + move;
            
            result = result + 1;
            reverse(X.begin(), X.end());
            for(int i = 0; i < X.size(); i++)
            {
                if(X[i] == '+')
                    X[i] = '-';
                else
                    X[i] = '+';
            }
        }
    }
    return result;    
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> S;
        cout << "Case #" << t << ": " << compute_solution(S) << "\n";
    }
    return 0;
}
