#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T, K, C, S;

int main()
{
    ifstream cin("D-large.in");
    ofstream cout("D.out");
    
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        cout << "Case #" << casenum << ":";
        cin >> K >> C >> S;
    
        if (C*S < K)
        {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        
        for (int i = 0; i*C < K; i++)
        {
            long long n = 0;
            for (int j = 0; j < C; j++) 
                if (i*C + j < K)
                    n = n*(long long)K + i*C + j;
                else
                    n = n*(long long)K;
                   
            cout << " " << n+1;
        }
        cout << endl;
    }
    
    return 0;
}
